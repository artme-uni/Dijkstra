#ifndef DIJKSTRA_QUEUE_H
#define DIJKSTRA_QUEUE_H

#include "graph.h"

typedef struct queue
{
    struct queue *next;
    int vert;
} queue;

queue *pop(queue *temp, int *result);

queue *push(queue *temp, int val, int *distaces);

queue *q_remove(queue *temp, int vert);

#endif //DIJKSTRA_QUEUE_H
