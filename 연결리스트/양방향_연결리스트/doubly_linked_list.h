#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *previous_node;
    struct _Node *next_node;
} Node;

Node *create_node(int data);
void add_node(Node **head, Node *new_node);
void insert_before_node(Node **head, Node *node, Node *new_node);
void insert_after_node(Node **node, Node *new_node);
void remove_node(Node **head, Node *node);
void delete_node(Node *node);
Node *get_node_at(Node *head, int index);
int get_size(Node *head);

void print_node_information(Node *node);
void print_all_node(Node *head);
void print_linked_list_information(Node *head);

#endif