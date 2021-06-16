//
// Created by TraAL on 4/20/2021.
//

#ifndef P3_GRAPH_H
#define P3_GRAPH_H

#include <stdio.h>

typedef struct TAG_NODE{
    int v;
    int u;
    float w;
    TAG_NODE *next;
}NODE;
typedef NODE *pNODE;

typedef struct TAG_PATH{
    int vertex;
    TAG_PATH *next;
}PATH;

//adjaceny list is an array of A[n+1], where a[u] is
//the adj list of vertex u, u - 1,2,...n
//Each node on the adj list is a NODE struct

//after n is read from file allocate memory like
//A = (pNODE *) calloc(n+1, sizeof(pNODE));

typedef struct TAG_VERTEX{
    int color;
    int pi;
    float d;
    int pos; //index in the heap array
    char *name;
}VERTEX;
typedef VERTEX *pVERTEX;
//Vertex attribures are implemented as an array of n+1 ptr
//V = (VERTEX *) calloc(n+1, sizeof(VERTEX));

int Dijkstra(int n, pNODE *A, int s, int t, int flag, VERTEX *V);
void printPath(int n, int source, int destination, int s, int t, VERTEX *V);


#endif //P3_GRAPH_H
