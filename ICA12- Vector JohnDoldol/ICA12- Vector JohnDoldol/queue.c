#include <stdlib.h>
#include <stdio.h>
#include "vect.h"
#include "stack.h"

Vector Enqueue(Vector v, int queue)
{	
	v = Push(v,queue);	
	return v;
}

Vector DeQueue(Vector v, int * pop)
{
	//check if you empty queue
	if (v.top == v.size)
		return v;
	//v.store[v.size++] = queue;
	int weight = v.size - v.top;

	if (weight < v.max)
	{
		v = ReSize(v);
	}
	v.top = Top(v);
	*pop = v.store[v.top];
	v.store[v.top++] = 0;
	return v;
}

Vector Space(Vector v)
{
	if (v.size - v.top >= v.max)
	{
		v = Grow(v);
	}
	return v;
}
int Top(Vector v)
{
	int top = 0;
	for (int i = 0; i < v.size; ++i)
	{
		if (v.store[i] != 0)
		{
			return i;
		}
	}
	return top;
}