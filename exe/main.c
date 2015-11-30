#include <stdio.h>
#include "numbers.h"

int main(int argc, const char *argv[])
{
	int i = 3;
	printf("%d is %s\n", i, is_odd(i) ? "odd" : "even");
	return 0;
}

