#include <iostream>
#include <iomanip>

template <typename T = float>
class Vertex{
	public:
		Vertex(T const &a, T const &b, T const &c): _x(a), _y(b), _z(c) {}
		~Vertex(void) {};

		/*
		** T — return the value of type T (whatever the template type is)
		** const — the caller cannot modify what's returned
		** & — return a reference, not a copy
		*/
		T	const &getX(void) const { return this->_x; };
		T	const &getY(void) const { return this->_y; };
		T	const &getZ(void) const { return this->_z; };

	private:
		T	const _x;
		T	const _y;
		T	const _z;

		Vertex(void) {};
};

template <typename T>
std::ostream & operator << (std::ostream &o, Vertex <T> const &v)
{
	std::cout.precision(1);
	o << std::setiosflags( std::ios::fixed );
	o << "Vertex( ";
	o << v.getX() << ", ";
	o << v.getY() << ", ";
	o << v.getZ();
	o << " )";
	return o;
}
