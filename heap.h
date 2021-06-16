//
// Created by TraAL on 4/20/2021.
//

#ifndef P1_HEAP_H
#define P1_HEAP_H


#include "graph.h"

typedef struct TAG_ELEMENT{
    float key;
    int vertex; //points to vertex V[vertex]
}ELEMENT;
typedef ELEMENT *ElementT;

typedef struct TAG_HEAP{
    int capacity; /* max size of the heap */
    int size; /* current size of the heap */
    ElementT *H; /* pointer to pointers to elements */
}HEAP;

HEAP * Initialize(int n);

void MovingUP(HEAP *heap, int pos, VERTEX *V);

void buildHeap(HEAP heap);

int Insert(HEAP *heap, ElementT element, VERTEX *V);

ElementT ExtractMin(HEAP *heap, int flag, VERTEX *V);

void DecreaseKey(HEAP heap, int index, int value, VERTEX *V);

void minHeapify(HEAP heap, int index);

void heapFree(HEAP *heap);

int returnHeapifyCounter(int *count);

void counterZero(int *count);

#endif //P1_HEAP_H
