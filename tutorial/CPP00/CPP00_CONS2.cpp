#include <iostream>

class Car {
	public:
		Car();
		Car(std::string brand, std::string model, int year);
		std::string brand;
		std::string model;
		int year;
};

Car::Car(void)
{
	std::cout << "Hello World" << std::endl;
	brand = "Chevrolet";
	model = "Camaro";
	year = 1992;
	return;
};

Car::Car(std::string mbrand, std::string mmodel, int myear)
{
	brand = mbrand;
	model = mmodel;
	year = myear;
	return;
}

int main(void)
{
	Car car1;
	Car car2("Dodge", "Luxus", 2005);

	std::cout << car1.brand << " " << car1.model << " " << car1.year << std::endl;
	std::cout << car2.brand << " " << car2.model << " " << car2.year << std:: endl;
	return (0);
}
