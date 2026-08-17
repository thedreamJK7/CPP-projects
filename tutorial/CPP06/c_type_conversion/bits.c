#include <stdio.h>

void dump_32bits_integer ( int const n )
{
	for (int i = 31; i >= 0; i--) {
        putchar((n >> i) & 1 ? '1' : '0');
        if (i % 8 == 0 && i != 0) putchar(' '); // Byte separator
    }
    putchar('\n');
}
