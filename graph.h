#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "queue.h"

typedef struct edge
{
    int begin;
    int end;
    int weight;
} edge;

int lenght_compare(int a, int b);

int lenght_sum(int a, int b);

void dijkstra(edge *graph, int cnt_edge, int cnt_vert, int *distances, int *pastback, int start);

#endif //DIJKSTRA_GRAPH_H
