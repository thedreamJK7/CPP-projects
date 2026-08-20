void dump_32bits_integer ( int const n );
void dump_64bits_double ( double const n );

int main( void )
{
	int		a = 42; // Reference value

	double	b = a; // implicit conversion cast
	double	c = (double) a; // explicit conversion cast

	double	d = a; // implicit promotion -> OK
	int		e = d;	// implicit demotion -> hazardous
	int		f = (int)d; // Explicit demotion -> OK

	dump_32bits_integer( a );
	return 0;
}
