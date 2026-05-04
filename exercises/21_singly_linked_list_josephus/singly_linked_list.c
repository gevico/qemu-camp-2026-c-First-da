#include "singly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

// 全局头指针
static link head = NULL;

// 创建新节点
link make_node(unsigned char item) {
    link new_node;
    new_node = (link)malloc(sizeof(struct node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

// 释放节点
void free_node(link p) { free(p); }

// 查找节点
link search(unsigned char key) {
    // TODO: 在这里添加你的代码
    link ptr = head;
    while(ptr)
    {
        if (ptr->item == key)
            return ptr;
        ptr = ptr->next;
    }

    return NULL;
}

// 在链表头部插入节点
void insert(link p) {
    // TODO: 在这里添加你的代码
    p->next = head;
    head = p;
}

// 删除指定节点
void delete(link p) {
    // TODO: 在这里添加你的代码
    link curr = head;
    if (p == head)
        {
            head = p->next;
            free_node(p);
            return;
        }
    while(curr)
    {
        if (curr->next == p)
            {
                curr->next = p->next;
                free_node(p);
                return ;
            }
        else 
            curr = curr->next;
    }
}

// 遍历链表
void traverse(void (*visit)(link)) {
    // TODO: 在这里添加你的代码
    link ptr = head;
    while(ptr)
    {
        visit(ptr);
        ptr = ptr->next;
    }
}

// 销毁整个链表
void destroy(void) {
    // TODO: 在这里添加你的代码
    link curr = head;
    link prev;
    while(curr)
    {
        prev = curr->next;
        free_node(curr);
        curr = prev;
    }
}

// 在链表头部推入节点
void push(link p) { 
    // TODO: 在这里添加你的代码
    insert(p);
}

// 从链表头部弹出节点
link pop(void) {
    // TODO: 在这里添加你的代码
    link ptr = head;
    if (head)
    {
        head = head->next;
        return ptr;
    }
    else 
        return NULL;
}

// 释放链表内存
void free_list(link list_head) {
    // TODO: 在这里添加你的代码
    link ptr = list_head;
    link prev;
    while(ptr)
    {
        prev = ptr->next;
        free_node(ptr);
        ptr = prev;
    }
}
