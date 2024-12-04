#include <stdio.h>
#include "doubly_linked_list.h"

int main(int argc, char *argv[])
{
    Node *linked_list = NULL;
    Node *new_node = NULL;
    Node *node = NULL;

    printf("===[INITIALIZED LINKED LIST]===\n");

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[ADD NEW NODES(5)]===\n");

    for (int i = 0; i < 5; i++)
    {
        new_node = create_node(i);

        add_node(&linked_list, new_node);
    }

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[INSERT BEFORE HEAD]===\n");

    new_node = create_node(10);

    insert_before_node(&linked_list, linked_list, new_node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[INSERT BEFORE MIDDLE NODE]===\n");

    new_node = create_node(11);
    node = get_node_at(linked_list, get_size(linked_list) / 2 - 1);

    insert_before_node(&linked_list, node, new_node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[INSERT BEFORE TAIL]===\n");

    new_node = create_node(12);
    node = get_node_at(linked_list, get_size(linked_list) - 1);

    insert_before_node(&linked_list, node, new_node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[INSERT AFTER HEAD]===\n");

    new_node = create_node(20);

    insert_after_node(&linked_list, new_node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[INSERT AFTER MIDDLE NODE]===\n");

    new_node = create_node(21);
    node = get_node_at(linked_list, get_size(linked_list) / 2 - 1);

    insert_after_node(&node, new_node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[INSERT AFTER TAIL]===\n");

    new_node = create_node(22);
    node = get_node_at(linked_list, get_size(linked_list) - 1);

    insert_after_node(&node, new_node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n");

    printf("===[REMOVE HEAD]===\n");

    remove_node(&linked_list, linked_list);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[REMOVE MIDDLE NODE]===\n");

    node = get_node_at(linked_list, get_size(linked_list) / 2 - 1);

    remove_node(&linked_list, node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[REMOVE TAIL]===\n");

    node = get_node_at(linked_list, get_size(linked_list) - 1);

    remove_node(&linked_list, node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    return 0;
}
