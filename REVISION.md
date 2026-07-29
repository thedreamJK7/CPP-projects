# C++ Revision — CPP00 → CPP02

A quick refresher on everything you've built so far, based on your actual code.

---

## CPP00 — Basics of C++

### ex00 — Megaphone
Simple program: takes command-line args and prints them in uppercase using `std::toupper`.

**Key concepts:**
- `argc` / `argv` handling
- `std::cout` instead of `printf`
- `#include <cctype>` for character functions

---

### ex01 — PhoneBook
Two classes: `Contact` and `PhoneBook`. PhoneBook stores up to 8 contacts in a fixed array. Oldest contact is overwritten when full (`_numContacts % MAX_CONTACTS`).

**Key concepts:**
- Classes with `private` attributes and `public` methods
- Encapsulation: getters and setters
- `const std::string&` — return by const reference to avoid unnecessary copies
- `std::getline` for reading full lines from stdin
- `std::setw` / `std::iomanip` for formatted table output
- `static const` member (`MAX_CONTACTS = 8`) — belongs to the class, not each object
- Input validation loop (reject empty fields)

```cpp
// returning const ref — no copy made
const std::string& Contact::get_f_name() const { return first_name; }
```

---

## CPP01 — Memory, Pointers, References

### ex00 — Zombie (heap vs stack)
Two functions: `newZombie` (heap, returns pointer) and `randomChump` (stack, local object).

**Key concept: when to use heap vs stack**
- Stack → object dies when function returns. Use for short-lived, local objects.
- Heap (`new`) → object lives until you `delete` it. Use when you need to control lifetime.

```cpp
Zombie* newZombie(std::string name) {
    return new Zombie(name);  // heap — caller must delete
}

void randomChump(std::string name) {
    Zombie foo = Zombie(name);  // stack — destroyed automatically
    foo.announce();
}
```

---

### ex01 — ZombieHorde (array on heap)
`zombieHorde(int N, std::string name)` allocates an array of N Zombies with `new Zombie[N]`.

**Key concept:**
- `new Type[N]` → allocates array on heap. Requires a **default constructor**.
- Must be freed with `delete[]` (not `delete`).

```cpp
Zombie* zombies = new Zombie[N];  // default constructor called N times
// ...
delete[] zombies;  // destructor called N times
```

---

### ex02 — HI THIS IS BRAIN (pointers vs references)
Showed that a pointer and a reference to the same variable all share the same memory address.

**Key concept:**
- Pointer (`*`) — holds an address, can be null, can be reassigned.
- Reference (`&`) — alias to an existing variable, can never be null, can't be reassigned.

```cpp
std::string  str = "HI THIS IS BRAIN";
std::string* ptr = &str;   // pointer
std::string& ref = str;    // reference

// All three print the same address:
&str == ptr == &ref  // true
```

---

### ex03 — Unnecessary Violence (pointer vs reference member)
`HumanA` holds a `Weapon&` (reference) — must be set at construction, weapon always exists.
`HumanB` holds a `Weapon*` (pointer) — can be set later, weapon may not exist at creation.

**Key concept: when to use pointer vs reference as a class member**
- Use **reference member** when the dependency is mandatory and always exists → `HumanA`
- Use **pointer member** when the dependency is optional or set later → `HumanB`

```cpp
class HumanA {
    Weapon& _weapon;  // must be given at construction
};

class HumanB {
    Weapon* _weapon;  // can be null, set later with setWeapon()
};
```

---

### ex04 — Sed is for Losers (file I/O)
Reads a file, replaces all occurrences of a string with another, writes to `<filename>.replace`.
No `std::string::replace` allowed — had to find and rebuild manually using `substr`.

**Key concepts:**
- `std::ifstream` / `std::ofstream` for file reading/writing
- `std::string::find` to locate substrings
- `std::string::substr` to extract parts and rebuild the string

---

### ex05 — Harl 2.0 (pointers to member functions)
`Harl::complain(level)` calls the right private method using an array of function pointers instead of a big if/else chain.

**Key concept: pointer to member function**
```cpp
void (Harl::*pointers[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

// Calling it:
(this->*pointers[i])();
```
Syntax: `ReturnType (ClassName::*varName)(params)`

---

## CPP02 — Orthodox Canonical Form, Operator Overloading, Fixed-Point

### Orthodox Canonical Form (OCF)
Every class must have these four:

```cpp
class Fixed {
public:
    Fixed();                          // 1. Default constructor
    Fixed(Fixed const &src);          // 2. Copy constructor
    Fixed& operator=(Fixed const &);  // 3. Copy assignment operator
    ~Fixed();                         // 4. Destructor
};
```

**Why?** So your class behaves correctly when copied, assigned, or destroyed — just like a built-in type.

---

### ex00 — Fixed Point basics
Introduced the `Fixed` class. Stored an integer `_value` with 8 fractional bits.
`static const int _fractionalBits` — shared across all instances, not per-object.

---

### ex01 — Conversions
Added constructors from `int` and `float`, and conversion methods back.

**How fixed-point math works:**
- `_fractionalBits = 8` means the last 8 bits are the fractional part (like multiplying by 256).
- `int → fixed`: `_value = i << 8` (same as `i * 256`)
- `float → fixed`: `_value = roundf(f * 256)`
- `fixed → float`: `_value / 256.0f`
- `fixed → int`: `_value >> 8` (same as `_value / 256`, integer division)

Also overloaded `operator<<` to print directly with `std::cout`:
```cpp
std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
    o << rhs.toFloat();
    return o;
}
```

---

### ex02 — Full operator overloading
Added all comparison, arithmetic, and increment/decrement operators.

**Comparison operators** (`>`, `<`, `>=`, `<=`, `==`, `!=`) — compare `_value` directly.

**Arithmetic operators** (`+`, `-`, `*`, `/`) — operate on raw bits:
- `+` and `-`: just add/subtract raw values directly.
- `*`: multiply then shift right by 8 (to correct the double-scaling).
- `/`: shift left then divide (undoes the scaling).

**Increment/Decrement:**
```cpp
Fixed& operator++();    // pre:  ++x  — increments then returns *this
Fixed  operator++(int); // post: x++  — saves copy, increments, returns old copy
```
The `int` parameter in `operator++(int)` is just a dummy to distinguish post from pre.

**Static min/max — overloaded for const and non-const:**
```cpp
static Fixed&       min(Fixed& a, Fixed& b);
static Fixed const& min(Fixed const& a, Fixed const& b);
```

---

## CPP03 — Inheritance (what you're working on now)

### What you need to remember going in:

**Inheritance** lets a class reuse and extend another class.
```cpp
class ScavTrap : public ClapTrap { ... };
```
- ScavTrap **is a** ClapTrap — it gets all of ClapTrap's members.
- `protected` members are accessible in derived classes (unlike `private`).

**Constructor/Destructor chaining:**
- Construction: base first, then derived. (`ClapTrap` → `ScavTrap`)
- Destruction: derived first, then base. (`ScavTrap` → `ClapTrap`) ← LIFO

```cpp
ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name) {
    // ClapTrap's constructor runs first, then this body
}
```

**Method overriding:**
ScavTrap overrides `attack()` with its own message. The base `takeDamage` / `beRepaired` are inherited unchanged.

**ScavTrap stats** (what you used):
| Stat | ClapTrap | ScavTrap |
|------|----------|----------|
| HP | 10 | 100 |
| Energy | 10 | 50 |
| Attack | 0 | 20 |

---

## Quick Reference Cheatsheet

```cpp
// Heap allocation
Type* p = new Type(args);
delete p;

Type* arr = new Type[N];
delete[] arr;

// References vs pointers
int& ref = x;    // alias, never null, can't reassign
int* ptr = &x;   // address, can be null, can reassign

// Member function pointer
void (Class::*fp)() = &Class::method;
(obj.*fp)();         // on object
(ptr->*fp)();        // on pointer

// Pre vs post increment
Fixed& operator++();     // pre:  ++x
Fixed  operator++(int);  // post: x++

// Fixed-point: 8 fractional bits
int   → fixed:  value << 8
float → fixed:  roundf(f * 256)
fixed → float:  raw / 256.0f
fixed → int:    raw >> 8

// Inheritance
class Child : public Parent { ... };
// Always call parent constructor explicitly:
Child::Child() : Parent() { ... }
```
