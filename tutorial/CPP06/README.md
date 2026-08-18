# CPP06 — Type Casting Cheatsheet

---

## C — Type Casting (C Style)

### 1. Type Conversion (`CTypeConversion`)

Converting between numeric types like `int` and `double`.

```c
int a = 42;
double b = a;         // implicit promotion  → safe, no data loss
int e = b;            // implicit demotion   → DANGEROUS (silent truncation)
int f = (int)b;       // explicit demotion   → ok, you're in charge
```

- Promotion (small → big type): safe, implicit is fine
- Demotion (big → small type): implicit is hazardous, use explicit `(type)` cast

---

### 2. Type Qualifier Cast (`CTypeQualifier`)

Adding/removing `const` from a pointer.

```c
int a = 42;
int const *b = &a;       // implicit promotion  → ok (adding const)
int *e = d;              // implicit demotion   → compiler error / UB
int *f = (int *)d;       // explicit demotion   → ok, removing const
```

- You can always *add* `const` implicitly
- Removing `const` requires explicit C cast — and it's your responsibility

---

### 3. Type Reinterpretation (`CTypeReinterpretation`)

Treating raw memory as a different type via `void *`.

```c
float a = 420.042f;
void *b = &a;          // implicit reinterpret → ok (void* is generic)
int *e = d;            // implicit demotion    → HAZARDOUS
int *f = (int *)d;     // explicit demotion    → ok, same bits, new type
```

- `void *` acts as a generic pointer — no type info
- Casting to `int *` reinterprets the raw bytes — the value will be garbage (not 420)

---

## C++ — Type Casting

### 4. `static_cast` (`StaticCast`)

The standard, compile-time checked cast. Works for numeric conversions and up/downcasting in class hierarchies.

```cpp
// numeric
double b = a;                // implicit promotion
int d = static_cast<int>(b); // explicit demotion → ok

// class hierarchy
Parent *b = &a;                        // implicit upcast   → ok
Child1 *c = static_cast<Child1 *>(b);  // explicit downcast → ok, but no runtime check
// static_cast<Unrelated *>(&a)        // unrelated type    → compiler error
```

- Checked at compile time (semantically), not at runtime
- Downcast is allowed but unsafe — no guarantee the object actually is that type

---

### 5. `dynamic_cast` (`DynamicCast`)

Runtime-safe downcast. Requires at least one `virtual` function in the base class (polymorphic type).

```cpp
// with pointer — returns nullptr on failure
Child1 *c = dynamic_cast<Child1 *>(b);
if (c == NULL) { /* failed */ }

// with reference — throws std::bad_cast on failure
try {
    Child2 &d = dynamic_cast<Child2 &>(*b);
} catch (std::bad_cast &e) { /* failed */ }
```

- The only cast with a runtime check
- Pointer version: returns `nullptr` on failure
- Reference version: throws `std::bad_cast` on failure
- Base class MUST have a `virtual` method (vtable required)

---

### 6. `const_cast` (`ConstCast`)

The only cast that can add or remove `const`/`volatile`.

```cpp
int const *b = &a;              // implicit promotion → ok
int *d = const_cast<int *>(b);  // remove const → ok, I obey
```

- Only use this when you know the original object was not actually `const`
- Modifying a truly `const` object via `const_cast` is undefined behavior

---

### 7. `reinterpret_cast` (`ReinterpretCast`)

Reinterprets raw memory as a different type. No conversion, just bit reinterpretation.

```cpp
float a = 420.042f;
void *b = &a;
int *c = reinterpret_cast<int *>(b);  // same address, different type interpretation
int &d = reinterpret_cast<int &>(b);  // same with reference
```

- Most dangerous cast — no type safety, no runtime check
- Useful for low-level stuff: serialization, hardware, memory inspection
- The int value you get back is NOT 420 — it's the raw IEEE 754 bits of the float

---

### 8. Type Cast Operator (`TypeCastOperator`)

You can define implicit conversions *from* your class to other types using `operator Type()`.

```cpp
class Foo {
public:
    Foo(float v) : _v(v) {}
    operator float() { return _v; }          // Foo → float
    operator int()   { return (int)_v; }     // Foo → int
private:
    float _v;
};

Foo a(420.024f);
float b = a;   // calls operator float()
int c = a;     // calls operator int()
```

---

### 9. Upcast / Downcast (`UpcastDowncast`)

Class hierarchy casting overview.

```cpp
Parent *d = &a;          // implicit upcast   → always safe
Child1 *e = d;           // implicit downcast → compiler error
Child2 *f = (Child2 *)d; // explicit downcast → compiles, but dangerous
```

- Upcast (Child → Parent): always safe
- Downcast (Parent → Child): needs `static_cast` or `dynamic_cast`; C-style cast compiles but skips all checks

---

### 10. `explicit` Keyword (`ExplicitKeyword`)

Prevents a constructor from being used as an *implicit* converter.

```cpp
class C {
public:
    C(A const &) {}           // implicit conversion allowed
    explicit C(B const &) {}  // implicit conversion BLOCKED
};

f(A()); // ok — implicit conversion via constructor
f(B()); // error — constructor is explicit, must convert manually
```

- By default, single-argument constructors are "conversion constructors"
- `explicit` opts out of that behavior — forces the caller to be intentional

---

## Summary Table (from Conclusion)

| Cast              | Conversion | Reinterpret | Upcast | Downcast | Const qual |
|-------------------|:---:|:---:|:---:|:---:|:---:|
| Implicit          |  ✓  |     |  ✓  |     |     |
| `static_cast`     |  ✓  |     |  ✓  |  ✓  |     |
| `dynamic_cast`    |     |     |  ✓  |  ✓  |     |
| `const_cast`      |     |     |     |     |  ✓  |
| `reinterpret_cast`|     |  ✓  |  ✓  |  ✓  |     |
| C-style `(type)`  |  ✓  |  ✓  |  ✓  |  ✓  |  ✓  |

| Cast              | Semantic check | Reliable at runtime | Tested at runtime |
|-------------------|:--------------:|:-------------------:|:-----------------:|
| Implicit          |  ✓  |  ✓  |     |
| `static_cast`     |  ✓  |     |     |
| `dynamic_cast`    |  ✓  |  ✓  |  ✓  |
| `const_cast`      |     |     |     |
| `reinterpret_cast`|     |     |     |
| C-style `(type)`  |     |     |     |

> Rule of thumb: prefer `static_cast` for most casts, use `dynamic_cast` when you need runtime safety, avoid C-style casts in C++.
