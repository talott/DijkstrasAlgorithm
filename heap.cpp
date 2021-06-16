//
// Created by TraAL on 4/20/2021.
//

#include "heap.h"
#include "graph.h"
#include <iostream>
#include <fstream>


HEAP array = {0,0,0};
HEAP *A = &array; //Create Heap Pointer Object
int counter = 0;
int temp;
//int flag;

HEAP * Initialize(int n)
{
    //HEAP A = {n,0,E}; //Create Heap Pointer Object
    (*A).capacity = n; //Capacity n
    (*A).size = 0; //Size 0
    ElementT *E = new ElementT [n+1]; //H point to array of n+1
    (*A).H = E;
    return A; //return heap pointer
}

int Insert(HEAP *heap, ElementT element, VERTEX *V)
{
    //inserts element into heap
    if(heap->size >= heap->capacity)
    {
        printf("Error in HeapInsert: Heap full...\n");
        return 1;
    }

    heap->size++;
    heap->H[heap->size] = element;
    V[heap->H[heap->size]->vertex].pos = heap->size;

    MovingUP(heap, heap->size, V);
    //DecreaseKey(*heap, heap->size, element->key);
    return 0;
}

void buildHeap(HEAP heap)
{
    //heap.size = heap.capacity;
    for(int i = (heap.size/2); i>=1; i--)
    {
        minHeapify(heap, i);
    }
}

ElementT ExtractMin(HEAP *heap, int flag, VERTEX *V)
{
    ElementT min, last;

    if(heap->size <= 0)
    {
        printf("Error in DeleteMin: heap empty\n");
        return NULL;
    }

    min = heap->H[1];//printf("Extrat Test: %f\n", min->key);
    last = heap->H[heap->size--];
    heap->H[1] = last;
    minHeapify(*heap, 1);
    V[min->vertex].pos = 0;

    return min;

    //deletes min element from heap
    //if A.heap.size < 1

   /* int min;
    if(heap->size < 1)
    {
        //error "heap underflow"
        std::cout << "heap underflow\n";
        return -1; //////////////issue here
    }
    if(flag == 1)
    {
        std::cout << "Delete vertex "<< heap->H[1]->vertex <<", key=     " << heap->H[1]->key<<"\n";
    }
    //min = A[1]
    min = heap->H[1]->vertex;
    //A[1] = A[A.heapsize]
    heap->H[1]->key = heap->H[heap->size]->key;
    //A.heap-size = A.heap-size-1
    heap->size = heap->size - 1;
    //minHeapify(A, 1)
    minHeapify(*heap, 1);
    //return min
    return min;*/
}

void DecreaseKey(HEAP heap, int index, int value, VERTEX *V)
{
    //decrease the key at H[index] to value
    //printf("Decrease Value: %d\n", value);
    //if key < A[i]
    int temp;
    /*if (value > heap.H[index]->key)
    {
        //error "new key is smaller than current key
        std::cout << "new key is bigger than current key\n";
    }*/

    //A[i] = key
    heap.H[index]->key = value;
    //while i> 1 and A[parent(i)] < A[i]
    while (index > 1 && heap.H[index/2]->key > heap.H[index]->key)
    {
        //exchange A[i] wth A[parent]
        temp = heap.H[index]->key;
        heap.H[index]->key = heap.H[index/2]->key;
        heap.H[index/2]->key = temp;
       // V[heap.H[index]->vertex].pos = index;
       // V[heap.H[index/2]->vertex].pos = index/2;
        //i = parent
        index = index/2;
    }
    //printf("Decrease key: %f", heap.H[index]->key);
    buildHeap(heap);
}

void minHeapify(HEAP heap, int index)
{
    //performs the heapify function at the index
    counter++;
    //parent is i/2 (integer division)
    //l = left (2i)
    //r = right (2i+1)
    int l = 2*index;
    int r = l+1;
    int smallest;
    int temp;

    //if l <=  A.heap-size and A[l] < A[i]
    if (l <= heap.size && heap.H[l]->key < heap.H[index]->key)
    {
        //smallest = l
        smallest = l;
    } else { //else
        //smallest = i
        smallest = index;
    }

    //if r <= A.heap-size and A[r] < A[smallest]
    if (r <= heap.size && heap.H[r]->key < heap.H[smallest]->key) {
        //smallest = r
        smallest = r;
    }

    //if smallest != i
    if (smallest != index)
    {
        //exchange A[i] with A[smallest]
        temp = heap.H[index]->key;
        heap.H[index]->key = heap.H[smallest]->key;
        heap.H[smallest]->key = temp;
        //printf("KEY VALUE: %f", heap.H[index]->key);
        //minHeapify(A, smallest)
        minHeapify(heap, smallest);
    }
}

void heapFree(HEAP *heap)
{
    free(heap->H);
    free(heap);
}

void MovingUP(HEAP *heap, int pos, VERTEX *V)
{
    ElementT temp;
    int parent;

    parent = pos/2;
    if(pos > 1 && heap->H[pos]->key < heap->H[parent]->key)
    {
        temp = heap->H[pos];
        heap->H[pos] = heap->H[parent];
        heap->H[parent] = temp;

        V[heap->H[pos]->vertex].pos = pos;
        V[heap->H[parent]->vertex].pos = parent;

        MovingUP(heap, parent, V);
    }
}

int returnHeapifyCounter(int *count)
{
    temp = counter;
    //counter = counter - temp;
    //*count = counter;
    return counter;
}

void counterZero(int *count)
{

    if(counter > 0)
    {
        counter = 0;
    }

}
