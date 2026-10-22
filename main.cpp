#include <iostream>
#include "doubly_ll.h"

int main() {

    // create the head node
    doubleList<char>* head = new_Node('C');

    // create the remaining nodes
    doubleList<char>* second = new_Node('P');
    doubleList<char>* third = new_Node('E');

    // link the nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    // initial Traversal
    std::cout << "Initial Traversal" << std::endl;
    dllTraverse(head);

    // general Insertion
    std::cout << "\nGeneral Insertion (Position 2)" << std::endl;
    dllInsertPosition('G', 2, &head);
    dllTraverse(head);

    // general Deletion
    std::cout << "\nGeneral Deletion (Position 3)" << std::endl;
    dllDeletePosition(3, &head);
    dllTraverse(head);

    return 0;
}


