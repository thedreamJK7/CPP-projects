#ifndef CONST_HPP
#define CONST_HPP

class example {
	public:
		float const pi;
		int			q;

		example(float const f);
		~example();

		void bar() const;
};

#endif