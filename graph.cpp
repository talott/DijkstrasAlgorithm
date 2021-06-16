//
// Created by TraAL on 4/20/2021.
//

#include "graph.h"
#include "heap.h"
#include <stdio.h>
#include <list>
#include <cstdlib>

using namespace std;


int Dijkstra(int n, pNODE *A, int s, int t, int flag, VERTEX *V) {
    pNODE node;
    HEAP *heap;
    ELEMENT *element;

    int u, v, i;
    float w;

    int pos;
    int count_Heapify;

    for (i = 1; i <=n; i++)
    {
        V[i].color = 0;
        V[i].pi = 0;
    }
    V[s].d = 0;
    V[s].color = 1;

    heap = Initialize(n);
    element = (ELEMENT *)malloc(sizeof(ELEMENT));
    element->vertex = s;
    element->key = 0;
    Insert(heap, element, V);
    if(flag == 1)
    {
        //print insert info
        printf("Insert vertex %d, key=%12.4f\n", element->vertex, element->key);
    }

    while(heap->size)
    {
        element = ExtractMin(heap, flag, V); //include heap counter?
        if(flag == 1)
        {
            //print delete information
            element->key = V[element->vertex].d;
            printf("Delete vertex %d, key=%12.4f\n", element->vertex, element->key);
        }
        u = element->vertex;
        V[u].color = 2;
        if(element->vertex == t)
        {
            break;
        }
        free(element);

        node = A[u];
        while (node)
        {
            v = node->v;
            w = node->w;
            if (V[v].color == 0)
            {
                V[v].d = V[u].d + w;
                V[v].pi = u;
                V[v].color = 1;

                V[v].pos = heap->size +1;
                element = (ELEMENT *)malloc(sizeof(ELEMENT));
                element->vertex = v;
                element->key = V[v].d;
                Insert(heap, element, V);
                if(flag == 1)
                {
                    //print insert info
                    printf("Insert vertex %d, key=%12.4f\n", element->vertex, element->key);
                }

            } else if (V[v].d > V[u].d + node->w){
                if(flag == 1)
                {
                    //print insert info
                    printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", v, V[v].d, V[u].d + node->w);
                }
                V[v].d = V[u].d + node->w;
                V[v].pi = u;
                DecreaseKey(*heap, v, V[v].d, V);
            }
            free(node);////
            node = node->next;
        }
    }
return 1;
}

void printPath(int n, int source, int destination, int s, int t, VERTEX *V)
{
    PATH *pPATH;
    PATH *pNode;
    int u, v;

    if (V[t].color == 0)
    {
        if(destination < 1 || destination > n || t == destination)
        {
            printf("No %d-%d path exists.\n", s, t);
            return;
        } else {
            printf("No %d-%d path has been computed.\n", s, t);////
            return;
        }
    } else if (V[t].color == 1) {
        printf("Path not known to be shortest: <%d", s);////
    } else if (V[t].color == 2){
        printf("Shortest path: <%d", s);////
    }

    //push onto stack
    pNode = (PATH *)malloc(sizeof(PATH));
    pNode-> vertex = t;
    pNode-> next = nullptr;
    pPATH = pNode;
    v = pNode->vertex;
    while(V[v].pi)
    {
        u = V[v].pi;
        pNode = (PATH *) malloc (sizeof(PATH));
        pNode->vertex = u;
        pNode->next = pPATH;
        pPATH = pNode;
        v = pNode->vertex;
        //free(pNode);
    }
    pNode = pPATH;
    pPATH = pPATH->next;
    free(pNode);

     while(pPATH) {
         pNode = pPATH;
         printf(", %d", pNode->vertex);
         pPATH = pPATH->next;
         free(pNode);
     }
     printf(">\n");
     printf("The path weight is: %12.4f\n", V[t].d);////

};
