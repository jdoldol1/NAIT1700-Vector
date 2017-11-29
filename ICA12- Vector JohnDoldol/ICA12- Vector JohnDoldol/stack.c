#include <stdlib.h>
#include <stdio.h>
#include "vect.h"
#include "stack.h"

void PrintVector(Vector v)
{
	printf("\n");
	for (int i = 0; i < v.size; ++i)
	{
		//don't print zeroes(empty vectors)
		if (v.store[i] == 0)
			continue;

		printf("%d ", v.store[i]);
	}
}

Vector Release(Vector v)
{
	free(v.store);
	v.store = NULL;
	v.size = 0;
	v.max = 0;
	return v;
}

Vector Grow(Vector v)
{
	Vector w = { NULL, 0, 0, 0 };
	//create a vector if there is none
	if (!v.store)
	{
		v.store = (int *)malloc(sizeof(int)*INTVECTSIZE);
		if (!v.store)//Didn't get memory for some reason
		{
			fprintf(stderr, "Memory allocation error in Grow. Unable to continue.");
			exit(EXIT_FAILURE);
		}
		//initial size of vector
		v.size = 0;
		v.max = INTVECTSIZE;
		return v;
	}

	w.max = 2 * v.max;
	printf("\nGrowing vector from %d to %d.\n", v.max, w.max);
	w.size = v.size;
	w.store = (int *)malloc(sizeof(int)*w.max);

	//copy array over
	for (int i = 0; i < v.size; ++i)
	{
		w.store[i] = v.store[i];
	}

	//set the rest to 0
	for (int j = w.size; j < w.max; ++j)
	{
		w.store[j] = 0;
	}

	//clean up v vector
	return w;
}

Vector Push(Vector  v, int val)
{
	//weight is the total number of items inside the vector
	if (v.size == v.max)
		v = Grow(v);

	v.store[v.size++] = val;
	return v;
}

Vector Pop(Vector v, int * pop)
{
	//set pop to value of top of stack
	* pop = v.store[--v.size];
	//top of stack is set to 0(empty)
	v.store[v.size] = 0;
	return v;
}
Vector ReSize(Vector v)
{
	if (!v.store) return v;
	//create new vector to replace old one
	Vector w = { NULL, 0, 0, 0 };	

	//copy contents to new vector;
	//top value is back to zero, size is upcountered each time we push
	for (int i = v.top; i < v.size; ++i)
	{
		w = Push(w, v.store[i]);
	}
	Release(v);
	return w;
}