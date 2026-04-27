#include <iostream>

class Quadruped
{
	private:
		std::string	_name; // Only accessible from a Quadruped object

	protected:
		Leg		leg[4]; // Accessible from a Quadruped and derived(hosil bolgan) objects
	
	public:
		void 	run(); // Accessible from wherever
};

class Dog : public Quadruped // Can access run() and legs
{

};


int main() // Can only access to run()
{

}