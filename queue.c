#include "queue.h"

queue *pop(queue *temp, int *result)
{
    *result = temp->vert;
    queue *res = temp->next;
    free(temp);

    return res;
}

queue *push(queue *temp, int val, int *distaces)
{
    if (temp == NULL || lenght_compare(distaces[temp->vert], distaces[val]) < 0)
    {
        queue *new = malloc(sizeof(queue));
        new->next = temp;
        new->vert = val;
        return new;
    }

    queue *current = temp;

    while ((current->next != NULL) && (lenght_compare(distaces[val], distaces[current->next->vert]) < 0))
    {
        current = current->next;
    }

    queue *new = malloc(sizeof(queue));
    new->next = current->next;
    current->next = new;
    new->vert = val;

    return temp;
}

queue *q_remove(queue *temp, int vert)
{
    if (temp == NULL)
    {
        return NULL;
    }

    queue *current = temp;

    if (current->vert == vert)
    {
        struct queue *next = temp->next;
        free(temp);
        return next;
    }

    while ((current->next != NULL))
    {
        if (current->next->vert == vert)
        {
            struct queue *next = current->next->next;
            free(current->next);
            current->next = next;

            break;
        }

        current = current->next;
    }

    return temp;
}
