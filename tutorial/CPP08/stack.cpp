#include <iostream>
#include <stack>

// Stack is the container which works with LIFO(Last in first out) method

int main(void)
{
	std::stack <int> st;

	st.push(10);
	st.push(20);
	st.push(30);

	std::cout << st.top() << std::endl;
	st.pop();
	std::cout << st.top() << std::endl;
	std::cout << st.size() << std::endl;

	return (0);
}
