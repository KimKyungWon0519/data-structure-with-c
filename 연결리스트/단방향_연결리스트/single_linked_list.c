#include "single_linked_list.h"

Node *create_node(int data)
{
    Node *node = (Node *)calloc(1, sizeof(Node));

    node->data = data;
    node->next_node = NULL;

    return node;
}

void delete_node(Node *node)
{
    free(node);
}

void add_node(Node **head, Node *new_node)
{
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *tail = *head;

        while (tail->next_node != NULL)
        {
            tail = tail->next_node;
        }

        tail->next_node = new_node;
    }
}

void insert_before_node(Node **head, Node *node, Node *new_node)
{
    if (*head == node)
    {
        new_node->next_node = *head;
        *head = new_node;
    }
    else
    {
        Node *previous_node = *head;

        while (previous_node != NULL && previous_node->next_node != node)
        {
            previous_node = previous_node->next_node;
        }

        new_node->next_node = node;
        previous_node->next_node = new_node;
    }
}

void insert_after_node(Node **node, Node *new_node)
{
    new_node->next_node = (*node)->next_node;
    (*node)->next_node = new_node;
}

void remove_node(Node **head, Node *node)
{
    if (*head == node)
    {
        *head = node->next_node;
    }
    else
    {
        Node *previous_node = *head;

        while (previous_node != NULL && previous_node->next_node != node)
        {
            previous_node = previous_node->next_node;
        }

        previous_node->next_node = node->next_node;
    }
}

Node *get_node_at(Node *head, int index)
{
    if (index < 0)
    {
        return NULL;
    }

    Node *current_node = head;

    while (current_node != NULL && --index >= 0)
    {
        current_node = current_node->next_node;
    }

    return current_node;
}

int get_size(Node *head)
{
    int length = 0;
    Node *current_node = head;

    while (current_node != NULL)
    {
        current_node = current_node->next_node;

        length++;
    }

    return length;
}

void print_node_information(Node *node)
{
    printf("address : %p\ndata : %d\nnext_node : %p\n\n", node, node->data, node->next_node);
}

void print_all_node(Node *head)
{
    while (head != NULL)
    {
        print_node_information(head);

        head = head->next_node;
    }
}

void print_linked_list_information(Node *head)
{
    printf("[show linked list information]\n");

    print_all_node(head);

    int length = get_size(head);

    printf("\nlinked list size : %d\n", length);
}