#include <iostream>

class Foo {
public:
  Foo(float const v) : _v(v) {}
  float getV() { return this->_v; }

  operator float() { return this->_v; }
  operator int() { return static_cast<int>(this->_v); }

private:
  float _v;
};

int main() {
  Foo a(420.024f);
  float b = a;
  int c = a;

  float d = 420.042f;
  int e = d;

  std::cout << a.getV() << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << e << std::endl;
}