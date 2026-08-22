#include <iostream>

// defining a class template called List, with a type parameter called T.
template <typename T> class List {
	public:
		List<T>(T const & content) { };
		List<T>(List<T> const &rhs) { };
		~List<T>( void ) { };
	private:
		T	_content;
		List<T> *_next;
};

int main( void )
{
	List<int>a(42);
	List<float>b(42.24f);
	List<List<int>>c(a);
	return (0);
}

/*

template <typename T>
        ↓
T = placeholder
        ↓
	List<T>
	↓
┌───────────────┐
│ _content : T  │
│ _next ────────┼──► List<T>
└───────────────┘

*/
