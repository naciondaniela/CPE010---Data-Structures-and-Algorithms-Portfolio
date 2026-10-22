#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <iostream>

template <typename T>
class doubleList {
public:
    T data;
    doubleList<T>* next = NULL;
    doubleList<T>* prev = NULL;
};

template <typename T>
doubleList<T>* new_Node(T newData) {

    doubleList<T>* newNode = new doubleList<T>;
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

template <typename T>
void dllTraverse(doubleList<T>* currentNode) {

    doubleList<T>* tail = NULL;
    std::cout << "Forward Traversal" << std::endl;

    while (currentNode != NULL) {

        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    std::cout << std::endl;
    std::cout << "Reverse Traversal" << std::endl;

    while (tail != NULL) {

        std::cout << tail->data << " ";
        tail = tail->prev;
    }

    std::cout << std::endl;
}

template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead) {

    doubleList<T>* newNode = new_Node(newData);

    if (*currentHead == NULL) {
        *currentHead = newNode;
        return;
    }

    newNode->next = *currentHead;
    (*currentHead)->prev = newNode;
    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, doubleList<T>** currentHead) {

    doubleList<T>* newNode = new_Node(newData);

    if (*currentHead == NULL) {
        *currentHead = newNode;
        return;
    }

    doubleList<T>* temp = *currentHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

template <typename T>
void dllInsertPosition(T newData, int position, doubleList<T>** currentHead) {

    if (position == 1) {
        dllInsertHead(newData, currentHead);
        return;
    }

    doubleList<T>* temp = *currentHead;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        std::cout << "Invalid Position!" << std::endl;
        return;
    }

    if (temp->next == NULL) {
        dllInsertEnd(newData, currentHead);
        return;
    }

    doubleList<T>* newNode = new_Node(newData);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

template <typename T>
void dllDeletePosition(int position, doubleList<T>** currentHead) {

    if (*currentHead == NULL) {
        std::cout << "List is Empty!" << std::endl;
        return;
    }

    doubleList<T>* temp = *currentHead;

    if (position == 1) {

        *currentHead = temp->next;

        if (*currentHead != NULL) {
            (*currentHead)->prev = NULL;
        }

        delete temp;
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        std::cout << "Invalid Position!" << std::endl;
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

#endif



