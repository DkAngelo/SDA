#include <stdlib.h>
#include <stdio.h>

void CombinaMoneteRec(int b, const int* m, size_t m_size, int* nsol, int* vcurr, int sum, int start, int i)
{
	if (sum > b)
	{
		return;
	}

	if (sum == b)
	{
		(*nsol)++;
		for (size_t j = 0; j < m_size; j++)
		{
			printf("%i ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	
	if (i == m_size)
	{
		return;
	}

	for (size_t j = start; j < m_size; j++)
	{
		vcurr[j] += 1;
		sum += m[j];
		CombinaMoneteRec(b, m, m_size, nsol, vcurr, sum, start, i + 1);
		vcurr[j] -= 1;
		sum -= m[j];
		start++;
	}

}


int CombinaMonete(int b, const int* m, size_t m_size)
{
	int* vcurr = calloc(m_size , sizeof(int));

	int nsol = 0;

	CombinaMoneteRec(b, m, m_size, &nsol, vcurr, 0, 0, 0);

	free(vcurr);
	return nsol;
}