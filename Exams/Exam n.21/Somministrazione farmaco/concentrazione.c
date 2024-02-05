#include <stdio.h>
#include <stdlib.h>

double concentrazione(double n)
{
	if(n == 1)
	{
		return 0;
	}

	return 0.3 * concentrazione(n - 1) + 0.2;
}


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;
	}

	double n = atof(argv[1]);

	if (n < 1)
	{
		return 1;
	}

	double cn = concentrazione(n);
	printf("%f", cn);
	return 0;
}