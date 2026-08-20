int main( void )
{
	int a = 42;

	const int *b = &a; // implicit promotion
	// int *c = &b; // implicit demotion not good

	int *d = const_cast<int *>(b); // remove const

	int e = 42;

	const int *f = const_cast<int *>(&e);
	return 0;
}
