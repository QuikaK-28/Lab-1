#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct ListNode
{
    int data;
    ListNode *next;
} ListNode;

typedef struct Tree
{
    ListNode *head;
    ListNode *tail;
} Tree;

void construct_list(Tree *lst)
{
    lst->head = (ListNode *)malloc(sizeof(ListNode));
    lst->tail = (ListNode *)malloc(sizeof(ListNode));
    lst->head->next = lst->tail;
    lst->tail->next = NULL;
    lst->head->data = 0;
    lst->tail->data = 0;
}

void destruct_list(Tree *lst)
{
    //clear(lst);
    free(lst->head);
    free(lst->tail);
    lst->head = NULL;
    lst->tail = NULL;

}

ListNode *begin(Tree *lst)
{
    return lst->head->next;
}

ListNode *end(Tree *lst)
{
    return lst->tail;
}

void inc(ListNode **ptr)
{
    *ptr = (*ptr)->next;
}

int is_empty(Tree *lst)
{
    return begin(lst) == end(lst) ? 1 : 0;
}

void push_front(Tree *lst, int data)
{
    ListNode *new_elem = (ListNode *)malloc(sizeof(ListNode));
    new_elem->data = data;
    new_elem->next = begin(lst);
    lst->head->next = new_elem;
}

void push_back(Tree *lst, int data)
{
    ListNode *new_elem = (ListNode *)malloc(sizeof(ListNode));
    ListNode *i = lst->head;
    new_elem->data = data;
    while (i->next != end(lst))
        inc(&i);
    i->next = new_elem;
    new_elem->next = end(lst);
}

int front(Tree *lst)
{
    return begin(lst)->data;
}

int back(Tree *lst)
{
    ListNode *i = lst->head;

    while (i->next != end(lst))
        inc(&i);

    return i->data;
}

int pop_front(Tree *lst)
{
    ListNode *del_elem = begin(lst);
    int data = 0;
    if (is_empty(lst) != 1)
    {
        data = del_elem->data;

        lst->head->next = del_elem->next;

        free(del_elem);
    }
    return data;
}

int pop_back(Tree *lst)
{
    ListNode *del_elem = lst->head;
    int data = 0;

    if (is_empty(lst) != 1)
    {
        while (del_elem->next->next != end(lst))
            inc(&del_elem);

        data = del_elem->next->data;

        del_elem->next = end(lst);

        free(del_elem->next);
    }

    return data;
}

void clear(Tree *lst)
{
    while (is_empty(lst) != 1)
        pop_front(lst);
}

void print_list(Tree *lst)
{
    ListNode *i;
    for (i = begin(lst); i != end(lst); inc(&i))
    {
        printf("%d", i->data);

        if (i->next != end(lst))
            printf(" -> ");
    }
    printf("\n");
}

typedef struct Queue
{
    Tree queue;
} Queue;

void construct_queue(Queue *queue)
{
    construct_list(&queue->queue);
}

void destruct_queue(Queue *queue)
{
    destruct_list(&queue->queue);
}

void push(Queue *queue, int data)
{
    push_back(&queue->queue, data);
}

int pop(Queue *queue)
{
    return pop_front(&queue->queue);
}

void print_queue(Queue *queue)
{
    print_list(&queue->queue);
}

int main(void)
{
    Queue q;
    construct_queue(&q);
    push(&q, 1);
    push(&q, 2);
    push(&q, 3);

    print_queue(&q);

    printf("%d\n", pop(&q));
    printf("%d\n", pop(&q));

    print_queue(&q);

    destruct_queue(&q);

    return 0;
}
