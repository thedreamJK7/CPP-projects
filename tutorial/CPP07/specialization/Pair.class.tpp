#include <iostream>
#include <iomanip>
#include <string>

/************** Generic template **************************/

template <typename T, typename U>
class Pair {
	public:
		Pair<T, U>(T const & lhs, U const & rhs): _lhs(lhs), _rhs(rhs) {
			std::cout << "Generic template!" << std::endl;
			return ;
		}

		~Pair<T, U>(void) {};

		T const & getLhs( void ) const { return this->_lhs; };
		U const & getRhs( void ) const { return this->_rhs; };

	private:
		T const & _lhs;
		U const & _rhs;

		Pair<T, U>(void);
};

/************** Specialized int template **************************/

template <typename U>
class Pair<int, U> {
	public:
		Pair<int, U>(int const & lhs, U const & rhs): _lhs(lhs), _rhs(rhs) {
			std::cout << "Specialized int template!" << std::endl;
			return ;
		}

		~Pair<int, U>(void) {};

		int const & getLhs( void ) const { return this->_lhs; };
		U const & getRhs( void ) const { return this->_rhs; };

	private:
		int		 _lhs;
		U const & _rhs;

		Pair<int, U>(void);
};

/************** Specialized bool template **************************/

/*
	What is going on over there?
	We are storing lhs and rhs in a single integer, which can store up to 32 booleans at the same time.
	However, in this case, we only need 2 bits, so we are not actually saving any memory.
	Still, this is a good method to learn if you ever want to store multiple boolean values efficiently in 
	the future. For example, you can store up to 32 booleans in a single 4-byte integer.
*/

template <>
class Pair <bool, bool> {
	public:
		Pair<bool, bool>(bool lhs, bool rhs) {
			std::cout << "Bool/bool specialization!" << std::endl;
			this->_n = 0;
			// 00000000 00000000 00000000 00000000
			this->_n |= static_cast<int>(lhs) << 0;
			// if 1 then 00000000 00000000 00000000 00000001
			this->_n |= static_cast<int>(rhs) << 1;
			// if 1 then 00000000 00000000 00000000 00000010
			/*
			bit:       3 2 1 0
					   ↓ ↓ ↓ ↓
			_n =       0 0 R L
			
			*/
			return ;
		}

		~Pair<bool, bool>(void) {};
		// return the bit at the position 0
		bool getLhs( void ) const { return (this->_n & 0x01); };
		// return the bit at the position 1
		bool getRhs( void ) const { return (this->_n & 0x02); };

	private:
		int	_n;

		Pair<bool, bool>(void);
};

template <typename T, typename U>
std::ostream & operator << (std::ostream & o, Pair<T, U> const & p)
{
	o << "Pair( " << p.getLhs() << ", " << p.getRhs() << " )";
	return o;
}
