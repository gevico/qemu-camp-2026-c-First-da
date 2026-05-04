#include "circular_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

Node* create_circular_list(int n) {
    // TODO: 在这里添加你的代码
    Node * head = NULL;
    Node * tail;
    for (int i = 1; i <= n; i++)
        {
            Node *new_node = (Node *)malloc(sizeof(Node));
            if (new_node == NULL)
                return NULL;
            new_node->id = i;
            new_node->next = NULL;
            if (i == 1)
                {
                    head = new_node;
                    new_node->next = head;
                    tail = new_node;
                }
            else 
                {
                    tail->next = new_node;
                    new_node->next = head;
                    tail = tail -> next;
                }
        }
    return head;
}

void free_list(Node* head) {
    // TODO: 在这里添加你的代码
    if (head == NULL)   return;
    Node *ptr = head;
    Node *temp;
    do
    {
        temp = ptr;
        ptr = ptr -> next;
        free(temp);
    }while(ptr != head);
}
