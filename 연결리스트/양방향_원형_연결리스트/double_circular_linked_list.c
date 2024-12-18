#include "double_circular_linked_list.h"

Node *create_node(int data)
{
    Node *node = (Node *)calloc(1, sizeof(Node));

    node->data = data;
    node->previous_node = NULL;
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
        new_node->previous_node = new_node;
        new_node->next_node = new_node;
        *head = new_node;
    }
    else
    {
        Node *tail = (*head)->previous_node;

        new_node->previous_node = tail;
        new_node->next_node = *head;
        tail->next_node = new_node;
        (*head)->previous_node = new_node;
    }
}

void insert_before_node(Node **head, Node *node, Node *new_node)
{
    if (head == NULL || node == NULL || new_node == NULL)
    {
        return;
    }

    new_node->previous_node = node->previous_node;
    new_node->next_node = node;

    node->previous_node->next_node = new_node;

    if (*head == node)
    {
        *head = new_node;
    }

    node->previous_node = new_node;
}

void insert_after_node(Node **node, Node *new_node)
{
    if (node == NULL || new_node == NULL)
    {
        return;
    }

    new_node->previous_node = *node;
    new_node->next_node = (*node)->next_node;

    if ((*node)->next_node != NULL)
    {
        (*node)->next_node->previous_node = new_node;
    }

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
        (*head)->previous_node->next_node = node->next_node;
        *head = node->next_node;
    }
    else
    {
        node->previous_node->next_node = node->next_node;
        node->next_node->previous_node = node->previous_node;
    }
}

void delete_node(Node *node)
{
    free(node);
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
    printf("address : %p\ndata : %d\nprevious_node : %p\nnext_node : %p\n\n", node, node->data, node->previous_node, node->next_node);
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