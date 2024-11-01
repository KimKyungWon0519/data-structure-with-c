#include <stdio.h>
#include "single_linked_list.h"

int main(int argc, char *argv[])
{
    Node *linked_list = NULL;

    printf("===[INITIALIZED LINKED LIST]===\n");

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[ADD NEW NODES(5)]===\n");

    for (int i = 0; i < 5; i++)
    {
        Node *new_node = create_node(i);

        add_node(&linked_list, new_node);
    }

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[Add NULL]===\n");

    add_node(&linked_list, NULL);

    printf("===[END]===\n\n");

    printf("===[GET HEAD]===\n");

    Node *node = get_node_at(linked_list, 0);

    print_node_information(node);

    printf("===[END]===\n\n");

    printf("===[GET MIDDLE]===\n");

    int length = get_size(linked_list);

    node = get_node_at(linked_list, length / 2);

    print_node_information(node);

    printf("===[END]===\n\n");

    printf("===[GET TAIL]===\n");

    length = get_size(linked_list);

    node = get_node_at(linked_list, length - 1);

    print_node_information(node);

    printf("===[END]===\n\n");

    printf("===[GET UNDERFLOW INDEX AND OVERFLOW INDEX]===\n");

    node = get_node_at(linked_list, -1);

    printf("index(-1) node : %p\n", node);

    length = get_size(linked_list);

    node = get_node_at(linked_list, length);

    printf("index(length) node : %p\n", node);

    printf("===[END]===\n\n");

    printf("===[INSERT HEAD]===\n");

    Node *new_node = create_node(10);

    insert_after_node(&linked_list, new_node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[INSERT MIDDLE]===\n");

    new_node = create_node(20);

    length = get_size(linked_list);

    node = get_node_at(linked_list, length / 2);

    insert_after_node(&node, new_node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[INSERT TAIL]===\n");

    new_node = create_node(30);

    length = get_size(linked_list);

    node = get_node_at(linked_list, length - 1);

    insert_after_node(&node, new_node);

    print_linked_list_information(linked_list);

    printf("===[END]===\n\n");

    printf("===[INSERT NULL]===\n");

    node = get_node_at(linked_list, 0);
    new_node = create_node(100);

    // new node null
    insert_after_node(&node, NULL);

    // node null
    insert_after_node(NULL, new_node);

    printf("===[END]===\n\n");

    printf("===[REMOVE NULL NODE]===\n");

    remove_node(&linked_list, NULL);

    printf("===[END]===\n\n");

    printf("===[REMOVE HEAD]===\n");

    node = get_node_at(linked_list, 0);

    remove_node(&linked_list, node);

    print_linked_list_information(linked_list);

    delete_node(node);

    printf("===[END]===\n\n");

    printf("===[REMOVE MIDDLE]===\n");

    length = get_size(linked_list);

    node = get_node_at(linked_list, length / 2);

    remove_node(&linked_list, node);

    print_linked_list_information(linked_list);

    delete_node(node);

    printf("===[END]===\n\n");

    printf("===[REMOVE TAIL]===\n");

    length = get_size(linked_list);

    node = get_node_at(linked_list, length - 1);

    remove_node(&linked_list, node);

    print_linked_list_information(linked_list);

    delete_node(node);

    printf("===[END]===\n\n");

    return 0;
}
