#include "doubly_circular_queue.h"

#include <stdlib.h>

// 头尾哨兵
static struct node tailsentinel;
static struct node headsentinel = {0, NULL, &tailsentinel};
static struct node tailsentinel = {0, &headsentinel, NULL};

static link head = &headsentinel;
static link tail = &tailsentinel;

link make_node(int data) {
    // TODO: 在这里添加你的代码
    link new_node = (link)malloc(sizeof(struct node));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void free_node(link p) {
    // TODO: 在这里添加你的代码
    free(p);
}

link search(int key) {
    // TODO: 在这里添加你的代码
    link ptr = head->next;
    while (ptr != tail)
    {
        if (ptr->data == key)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void insert(link p) {
    // TODO: 在这里添加你的代码
    link ptr = head->next;

    ptr->prev = p;
    p -> next = ptr;
    //prev

    //next
    p -> prev = head; 
    head -> next = p;
}

void delete(link p) {
    // TODO: 在这里添加你的代码
    if (p == head || p == tail )
        return ;
    link last = p -> prev;
    link next = p -> next;
    last->next = next;
    next->prev = last;
}

void traverse(void (*visit)(link)) {
    // TODO: 在这里添加你的代码
    link ptr = head -> next;
    while(ptr != tail )
        {
            visit(ptr);
            ptr = ptr->next;
        }
}

void destroy(void) {
    // TODO: 在这里添加你的代码
    link ptr = head->next;
    link temp;
    while(ptr != tail)
    {
        temp = ptr;
        ptr = ptr->next;
        free_node(temp);
    }
    head ->next = tail;
    tail -> prev = head;
}
