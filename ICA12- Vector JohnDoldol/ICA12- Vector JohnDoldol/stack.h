#pragma once
#include "vect.h"

void PrintVector(Vector v);
Vector Release(Vector v);
Vector Grow(Vector v);
Vector Push(Vector v, int val);
Vector Pop(Vector v, int * pop);
Vector ReSize(Vector v);