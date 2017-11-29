#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "stack.h"
#include "queue.h"

int * main(int argc, char ** argv)
{
	printf("------------------ Vector Stack Test ------------------\n");

	Vector vect = { NULL,0,0,0 };
	vect = Grow(vect);
	int popVectVal = 0;

	for (int i = 0; i < 10; ++i)
		vect = Push(vect, rand() % 100);
	PrintVector(vect);

	printf("Push integer 420 to a vector: \n");
	vect = Push(vect, 420);
	PrintVector(vect);

	for (int i = 0; i<vect.size; )
	{
		vect = Pop(vect, &popVectVal);
		printf("Poped integer from VectPop function: %d\n", popVectVal);
	}
	//vect = VectPop(vect, &popVectVal);
	//printf("Poped integer from VectPop function: %d\n", popVectVal);
	PrintVector(vect);

	vect = Release(vect);

	printf("------------------ Vector Queue Test ------------------\n");

	vect = Grow(vect);
	int dequeVectVal = 0;

	for (int i = 0; i < 10; ++i)
		vect = Enqueue(vect, rand() % 100);
	PrintVector(vect);

	printf("\nEnque integer 420 to a vector: \n");
	vect = Enqueue(vect, 999);

	printf("\nSize: %d, Top: %d",vect.size, vect.top);
	PrintVector(vect);
	printf("\n");	
	
	printf("------------------ Vector Dequeue Test ------------------\n");
	////QUEUE and DEQUQUe secquence
	//test out resize as well
	int pop;	
	int counter = 0;
	while (vect.top != vect.size)
	{		
		vect = DeQueue(vect, &pop);
		printf("\nDeQueue: %d\nSize: %d, Top: %d", pop, vect.size, vect.top);
		//tell user the vector resized
		//this happens when top goes back to 1
		if (counter > 0 && vect.top == 1)
		{
			printf("\nVector SHRUNK!");
		}
		PrintVector(vect);
		printf("\n");
		counter++;
	}
	

	vect = Release(vect);

	getchar();
	fflush(stdout);
	//Press enter to not make debug window go away
#ifdef _DEBUG
	fflush(stdin); //Make sure there's nothing lurking in the buffer.
	printf("\nPress Enter to Exit");
	fgetc(stdin);
#endif

	return EXIT_SUCCESS;
}

//test code
//
//Vector thor = { NULL, 0 ,0 };
//srand((unsigned int)time(NULL));
//int size;
//
//printf("Enter size of Vector: ");
//scanf("%d", &size);
//
//for (int i = 0; i < size; ++i)
//{
//	thor = Push(thor, (rand() % 99) + 1);
//}
//PrintVector(thor);
//
////pop sequence
//int pop;
///*thor = Pop(thor, &pop);
//printf("\nPop: %d", pop);
//printf("\nSize: %d", thor.size);
//printf("\nTop: %d",thor.top);*/
///*PrintVector(thor);*/
//
//////QUEUE and DEQUQUe secquence
////test out resize as well
//while (thor.size < 12)
//{
//	printf("\n\nEnter Queue value: ");
//	scanf("%d", &pop);
//	thor = Queue(thor, pop);
//	thor = DeQueue(thor, &pop);
//	PrintVector(thor);
//}

//
//while (count < 5)
//{
//	while (vect.size - vect.top)
//	{
//		vect = DeQueue(vect, &dequeVectVal);
//		printf("\nDeque integer from Dequeue function: %d\n-test end: \nDequeue", dequeVectVal);
//		PrintVector(vect);
//	}
//
//	for (int i = 0; i < 20; ++i)
//	{
//		printf("\nEnqueue integer %d to list: \n", 420 + i);
//		vect = Enqueue(vect, 420 + i);
//		PrintVector(vect);
//		printf("\n-test end: VectEnque\n");
//	}
//	++count;
//}
//
//
//while (vect.size < 12)
//{
//	printf("\n\nEnter Queue value: ");
//	scanf("%d", &pop);
//	vect = Enqueue(vect, pop);
//	vect = DeQueue(vect, &pop);
//	printf("\nDeQueue: %d, Size: %d, Top: %d", pop, vect.size, vect.top);
//	PrintVector(vect);
//}