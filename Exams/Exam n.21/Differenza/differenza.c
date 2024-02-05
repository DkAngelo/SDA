#include "differenza.h"

Item* Differenza(const Item* i1, const Item* i2)
{
	
	int n1 = 0;
	int i = 0;
	for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp))
	{
		n1 += ( * ListGetHeadValue(tmp)- '0') * (int)pow(10, i);
		i++;
	}

	int n2 = 0;
	 i = 0;
	for (const Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp))
	{
		n2 += (* ListGetHeadValue(tmp) - '0') * (int)pow(10, i);
		i++;
	}

	int n = n1 - n2;
	Item* list = ListCreateEmpty();
	for (int tmp = n; tmp != 0; )
	{
		int a = tmp % 10;
		ElemType e = a +'0';
		list = ListInsertBack(list, &e);
		tmp /= 10;
	}
	
	return list;
}