#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
	(void)rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

/*
	NaN is for not a number, undefined and cant be represented: sqrt(-5), 1 / 0
	inf is for infinity numbers: 1 / 0.000000009, or can not be stored
*/
bool	handle_literals(const std::string &str)
{
	static const std::string	f_options[4] = {"-inff", "+inff", "inff", "nanf"};
	static const std::string	d_options[4] = { "-inf", "+inf", "inf", "nan"};

	for (int k = 0;k < 4; k++)
	{
		if (str == f_options[k] || str == d_options[k])
		{
			std::cout	<< "char: impossible"
						<< "\nint: impossible"
						<< "\nfloat: "	<< f_options[k]
						<< "\ndouble: "	<< d_options[k]
						<< std::endl;
			return (true);
		}
	}
	return (false);
}

void	print_char(const char &c)
{
	std::cout	<< "char: "			<< c
				<< "\nint: "		<< static_cast<int>(c) 
									<< std::fixed
				<< "\nfloat: "		<< std::setprecision(1)
									<< static_cast<float>(c)
									<< "f"
				<< "\ndouble: "		<< std::setprecision(1)
									<< static_cast<double>(c)
				<< std::endl;
	return ;
}

/*
	1.0 / 0.0 -- inf 
	0.0 / 0.0 -- NaN
*/
bool	handle_double_edges(const double &doubleVal)
{
	const static std::string	inf[2] = {"-inf", "+inf"};
	
	if (std::isnan(doubleVal))
	{
		std::cout	<< "char: impossible"
					<< "\nint: impossible"
					<< "\nfloat: nanf"
					<< "\ndouble: nan"
					<< std::endl;
		return (true);
	}
	if (std::isinf(doubleVal))
	{
		std::cout	<< "char: impossible"
					<< "\nint: impossible"
					<< "\nfloat: "	<< inf[(doubleVal > 0)]
									<< "f"
					<< "\ndouble: "	<< inf[(doubleVal > 0)]
					<< std::endl;
		return (true);
	}
	return (false);
}

void	print_number(double &d)
{
	if (d > std::numeric_limits<float>::max()
		|| d < -std::numeric_limits<float>::max())
	{
		std::cout	<< "char: impossible"
					<< "\nint: impossible"
					<< "\nfloat: impossible";
	}
	else if (d > std::numeric_limits<int>::max()
			|| d < -std::numeric_limits<int>::max())
	{
		std::cout	<< "char: impossible"
					<< "\nint: impossible"
					<< "\nfloat: "	<< std::fixed
									<< std::setprecision(1)
									<< static_cast<float>(d) << "f";
	}
	else if (static_cast<int>(d) < 0
			||	static_cast<int>(d) > 127)
	{
		std::cout	<< "char: impossible"
					<< "\nint: impossible"
					<< "\nfloat: "	<< std::fixed
									<< std::setprecision(1)
									<< static_cast<float>(d) << "f";
	}
	else if (!std::isprint(static_cast<int>(d)))
	{
		std::cout	<< "char: Non displayable"
					<< "\nint: "	<< static_cast<int>(d)
					<< "\nfloat: "	<< std::fixed
									<< std::setprecision(1)
									<< static_cast<float>(d) << "f";
	}
	else
	{
		std::cout	<< "char: "		<< static_cast<char>(d)
					<< "\nint: "	<< static_cast<int>(d)
					<< "\nfloat: "	<< std::fixed
									<< std::setprecision(1)
									<< static_cast<float>(d) << "f";
	}
	std::cout	<< "\ndouble: "	<< std::fixed
								<< std::setprecision(1)
								<< static_cast<double>(d)
								<< std::endl;
}

/*
	strtod() converts string to double
	end pointer points to where conversion stopped
*/
void	ScalarConverter::convert(const std::string &str)
{
	double	doubleVal;
	char *end;

	end = NULL;
	// literal cases
	if (handle_literals(str))
		return ;

	// char case
	if (str.size() == 1 && std::isalpha(str[0]))
		return (print_char(str[0]));

	// convert to double
	doubleVal = std::strtod(str.c_str(), &end);
	if (handle_double_edges (doubleVal))
		return ;
	// numbers case
	if ((*end == 'f' && *(end + 1) == 0)
		|| *end == 0)
		return (print_number(doubleVal));
	std::cerr << "ERROR!" << std::endl;
	return ;
}
