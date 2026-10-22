#include <iostream>
#include "singly_ll.h"

using namespace std;

int main() {

    // Creating the initial linked list: C -> P -> E -> 1 -> 0 -> 1
    SimplyList<char>* head = new SimplyList<char>;
    SimplyList<char>* second = new SimplyList<char>;
    SimplyList<char>* third = new SimplyList<char>;
    SimplyList<char>* fourth = new SimplyList<char>;
    SimplyList<char>* fifth = new SimplyList<char>;
    SimplyList<char>* sixth = new SimplyList<char>;

    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '1';
    fourth->next = fifth;

    fifth->data = '0';
    fifth->next = sixth;

    sixth->data = '1';
    sixth->next = NULL;

    // a. Traversal
    cout << "a. Traversal" << endl;
    listTraversal(head);

    // b. Insert G at the head
    cout << "\nb. Insert G at the head" << endl;
    sllInsertHead('G', &head);
    listTraversal(head);

    // c. Insert E after P
    cout << "\nc. Insert E after P" << endl;
    sllGeneralInsert('E', head->next->next);   // Previous node is P
    listTraversal(head);

    // d. Delete C
    cout << "\nd. Delete C" << endl;
    sllDeleteNode('C', &head);
    listTraversal(head);

    // e. Delete P
    cout << "\ne. Delete P" << endl;
    sllDeleteNode('P', &head);
    listTraversal(head);

    // f. Show final list
    cout << "\nf. Final List" << endl;
    listTraversal(head);

    return 0;
}
