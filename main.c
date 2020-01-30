#include "graph.h"

int main()
{
    int cnt_vert;
    int cnt_edge;

    freopen("in.txt", "r", stdin);

    scanf("%d\n", &cnt_vert);

    if (cnt_vert < 0 || cnt_vert > 5000)
    {
        printf("bad number of vertices\n");
        return 1;
    }
    else if (cnt_vert == 0)
    {
        printf("no spanning tree\n");
        return 1;
    }
    else if (cnt_vert == 1)
    {
        return 1;
    }

    int start, end;
    scanf("%d %d", &start, &end);
    start--;
    end--;

    if (scanf("%d\n", &cnt_edge) != 1)
    {
        printf("bad number of lines\n");
        return 1;
    }

    if (cnt_edge < 0 || cnt_edge > ((cnt_vert) * (cnt_vert + 1)) / 2)
    {
        printf("bad number of edges\n");
        return 1;
    }

    edge *graph = malloc(sizeof(edge) * cnt_edge);
    for (int i = 0; i < cnt_edge; i++)
    {
        if ((scanf("%d %d %d", &graph[i].begin, &graph[i].end, &graph[i].weight) != 3))
        {
            printf("bad number of lines\n");
            return 1;
        }

        if (graph[i].begin < 1 || graph[i].begin > cnt_vert ||
            graph[i].end < 1 || graph[i].end > cnt_vert)
        {
            printf("bad vertex\n");
            free(graph);
            return 1;
        }

        graph[i].begin -= 1;
        graph[i].end -= 1;

        if (graph[i].weight < 0)
        {
            printf("bad lengt\n");
            free(graph);
            return 1;
        }
    }

    int *distances = malloc(sizeof(int) * cnt_vert);
    int *pastback = malloc(sizeof(int) * cnt_vert);

    dijkstra(graph, cnt_edge, cnt_vert, distances, pastback, start);

    for (int i = 0; i < cnt_vert; ++i)
    {
        if (distances[i] == -1)
            printf("oo ");
        else if (distances[i] == -2)
            printf("INT_MAX+ ");
        else printf("%d ", distances[i]);
    }
    printf("\n");

    if (start == end)
    {
        printf("%d\n", start+1);
    }
    else if (pastback[end] >= 0)
    {
        for (int i = end; i != start; i = pastback[i])
        {
            printf("%d ", i + 1);
        }
        printf("%d\n", start + 1);
    }
    else if (pastback[end] == -2)
    {
        printf("overflow\n");
    }
    else
    {
        printf("no path\n");
    }

    return 0;
}