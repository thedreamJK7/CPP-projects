# CPP07 — Templates

## What problem do templates solve?

When you write the same logic for multiple types:

```cpp
int    add(int a, int b)       { return a + b; }
double add(double a, double b) { return a + b; }
long   add(long a, long b)     { return a + b; }
```

The logic is identical. Only the type changes. Templates let you write it once:

```cpp
template <typename T>
T add(T a, T b) { return a + b; }
```

---

## Core concepts

### typename T

`T` is a placeholder for a type. The compiler fills it in based on how you use the function.

```cpp
add(10, 20);      // T = int
add(4.5, 2.3);    // T = double
```

### Templates are compile-time

Unlike runtime polymorphism (virtual + inheritance), templates are resolved at compile time. The compiler generates the appropriate version when it sees your usage.

```
template → compiler sees usage → generates version for that type
```

### What can T be?

Any type that supports the operations your template uses. If your template does `a * b`, any type that doesn't support `*` will cause a compile error.

---

## Function templates

```cpp
template <typename T>
T bigger(T a, T b) {
    return a > b ? a : b;
}
```

Works with any type that supports `>`. One definition, many types.

### Passing by const reference

```cpp
template <typename T>
void show(const T& value) {
    std::cout << value << std::endl;
}
```

Avoids copying large objects while promising not to modify them.

### Multiple type parameters

```cpp
template <typename T, typename U>
void printPair(T first, U second) {
    std::cout << first << " " << second << std::endl;
}
```

---

## Why definitions go in headers

The compiler needs to see the full template definition to instantiate it. This is why templates generally live in `.hpp` files (or a `.tpp` included at the bottom of the `.hpp`).

```
Normal function  → declaration in .hpp, implementation in .cpp  ✓
Template         → definition must be visible to the compiler    ✓
```

---

## Function as a parameter (ex01)

You can pass a function to a template to apply it to every element of an array.

```cpp
template <typename T, typename F>
void iter(T* array, size_t len, F func) {
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}
```

Usage:

```cpp
void print(int x) { std::cout << x << std::endl; }

int arr[] = {10, 20, 30};
iter(arr, 3, print);
```

The iteration logic is generic. Only the operation (the function) changes.

```
iter
 ├── print
 ├── modify
 └── calculate
```

### const and templates

A `const` array means elements shouldn't be modified. The function passed to `iter` must respect that. Templates don't remove normal C++ const rules.

---

## Class templates (ex02)

Just like function templates, you can make an entire class generic.

```cpp
template <typename T>
class Array {
private:
    T*     _data;
    size_t _size;

public:
    Array(size_t n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T&     operator[](size_t i);
    size_t size() const;
};
```

Usage:

```cpp
Array<int>         ints(5);
Array<std::string> strings(3);
```

Same class logic, different element type.

### Deep copy

Each object must own its own allocated memory. A shallow copy leaves two objects pointing to the same array:

```
// BAD — shallow copy
a ──→ [10][20][30]
           ↑
b ─────────┘
```

Modifying `b[0]` would change `a[0]`. Deep copy allocates separately:

```
// GOOD — deep copy
a ──→ [10][20][30]
b ──→ [10][20][30]
```

### Bounds checking

Invalid index access should throw an exception:

```cpp
T& operator[](size_t i) {
    if (i >= _size)
        throw std::out_of_range("index out of bounds");
    return _data[i];
}
```

---

## Module progression

| Exercise | Concept | Key idea |
|----------|---------|----------|
| ex00 | Function templates | One function works with many types |
| ex01 | Templates + function parameters | Generic iteration using a passed function |
| ex02 | Class templates | An entire class works with many types |

---

## 8 things to know before starting

1. A template is generic code parameterized on a type
2. `typename T` — `T` is a placeholder filled in at usage
3. Templates are instantiated at compile time
4. Template definitions must be visible to the compiler (put them in headers)
5. A function template replaces multiple overloads with one definition
6. A function pointer holds the address of a function and can be passed as an argument
7. A class template is a blueprint for a class that works with different types
8. Deep copy means each object owns its own allocated memory

> STL containers and algorithms (`std::vector`, `std::for_each`, etc.) are forbidden in CPP07. The point is to build the generic mechanism yourself.
