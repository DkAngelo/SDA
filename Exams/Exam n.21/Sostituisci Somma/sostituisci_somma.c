#include "tree.h"
#include "elemtype.h"
ElemType Somma(Node* t)
{
	if (TreeIsEmpty(t))
	{
		return 0;
	}
	else if (TreeIsLeaf(t))
	{
		return *TreeGetRootValue(t);
	}
	ElemType e1 = Somma(TreeLeft(t));
	ElemType e2 = Somma(TreeRight(t));
	t->value += (e1 + e2);
	return t->value;
}
void SostituisciSomma(Node* t)
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	else if (TreeIsLeaf(t))
	{
		return;
	}

	ElemType e = Somma(t);
	t->value = e; 
	return;
}