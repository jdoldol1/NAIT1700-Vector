#pragma once
#define INTVECTSIZE 10

typedef struct vector
{
	int * store; //Link to dma'd store
	int size; //Current number of used elements
	int max; //Maximum number of elements in store (size <= max)
	int top;
}Vector;


