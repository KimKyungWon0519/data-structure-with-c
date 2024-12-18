#include "single_circular_linked_list.h"

Node *create_node(int data)
{
    Node *node = (Node *)calloc(1, sizeof(Node));

    node->data = data;
    node->next_node = NULL;

    return node;
}

void add_node(Node **head, Node *new_node)
{
    if (new_node == NULL)
    {
        return;
    }

    if (*head == NULL)
    {
        *head = new_node;
        new_node->next_node = *head;
    }
    else
    {
        Node *tail = *head;

        while (tail->next_node != *head)
        {
            tail = tail->next_node;
        }

        tail->next_node = new_node;
        new_node->next_node = *head;
    }
}

void insert_after_node(Node **node, Node *new_node)
{
    if (node == NULL || new_node == NULL)
    {
        return;
    }

    new_node->next_node = (*node)->next_node;
    (*node)->next_node = new_node;
}

void remove_node(Node **head, Node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (*head == node)
    {
        Node *tail = *head;

        while (tail->next_node != *head)
        {
            tail = tail->next_node;
        }

        *head = node->next_node;
        tail->next_node = node->next_node;
    }
    else
    {
        Node *current_node = *head;

        while (current_node != NULL && current_node->next_node != node)
        {
            current_node = current_node->next_node;
        }

        if (current_node != NULL)
        {
            current_node->next_node = node->next_node;
        }
    }
}

void delete_node(Node *node)
{
    free(node);
}

Node *get_node_at(Node *head, int index)
{
    if (index < 0 || get_size(head) <= index)
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
    Node *current = head;

    if (current == NULL)
    {
        return 0;
    }

    do
    {
        current = current->next_node;

        length++;
    } while (current != head);

    return length;
}

void print_node_information(Node *node)
{
    printf("address : %p\ndata : %d\nnext_node : %p\n\n", node, node->data, node->next_node);
}

void print_all_node(Node *head)
{
    Node *current = head;

    if (current == NULL)
    {
        return;
    }

    do
    {
        print_node_information(current);

        current = current->next_node;
    } while (current != head);
}

void print_linked_list_information(Node *head)
{
    printf("[show linked list information]\n");

    print_all_node(head);

    int length = get_size(head);

    printf("\nlinked list size : %d\n", length);
}