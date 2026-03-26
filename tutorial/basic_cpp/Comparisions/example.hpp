#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

class example {
	public:
		example(int value);
		~example();

		int		getFoo() const; // const means that this function wont change the object, its not super necessary writing the const
		void	setFoo(int value);
		int		compare(example *other);
	
	private:
		int _foo;
};

#endif