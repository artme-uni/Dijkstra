#include "graph.h"

int lenght_compare(int a, int b)
{
    if (a == -1 && b == -1) return 0;
    else if (a == -1) return -1;
    else if (b == -1) return 1;

    if (a == -2 && b == -2) return 0;
    else if (a == -2) return -1;
    else if (b == -2) return 1;

    return b - a;
}

int lenght_sum(int a, int b)
{
    if (a == -1 || b == -1)
        return -1;
    if (a == -2 || b == -2)
        return -2;

    if (b > (INT_MAX - a))
        return -2;

    return b + a;
}


void dijkstra(edge *graph, int cnt_edge, int cnt_vert, int *distances, int *pastback, int start)
{
    queue *q = malloc(sizeof(queue));
    q->next = NULL;
    q->vert = start;

    for (int i = 0; i < cnt_vert; i++)
    {
        distances[i] = -1;
        pastback[i] = -1;
    }

    distances[start] = 0;

    while (q != NULL)
    {
        int vert;
        q = pop(q, &vert);

        for (int i = 0; i < cnt_edge; i++)
        {
            int sum = lenght_sum(graph[i].weight, distances[vert]);

            if (graph[i].begin == vert)
            {
                if (lenght_compare(distances[graph[i].end], sum) <= 0)
                {
                    pastback[graph[i].end] = vert;

                    if (distances[graph[i].end] == -2 && sum == -2)
                    {
                        pastback[graph[i].end] = -2;
                    }

                    distances[graph[i].end] = sum;

                    q = q_remove(q, graph[i].end);
                    q = push(q, graph[i].end, distances);
                }
            }
            else if (graph[i].end == vert)
            {
                if (lenght_compare(distances[graph[i].begin], sum) <= 0)
                {
                    pastback[graph[i].begin] = vert;

                    if (distances[graph[i].begin] == -2 && sum == -2)
                    {
                        pastback[graph[i].begin] = -2;
                    }

                    distances[graph[i].begin] = sum;


                    q = q_remove(q, graph[i].begin);
                    q = push(q, graph[i].begin, distances);
                }
            }
        }

    }
}