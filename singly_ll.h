#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>
using namespace std;

template <typename T>
class SimplyList{
public:
    T data;
    SimplyList<T> *next = NULL;
};

template <typename T>
void listTraversal(SimplyList<T>* head){

    if(head == NULL){
        cout << "List is Empty" << endl;
        return;
    }

    while(head != NULL){
        cout << head->data;
        if(head->next != NULL){
            cout << "->";
        }
        head = head->next;
    }
    cout << endl;
}

template <typename T>
void sllInsertHead(T newData, SimplyList<T>** currentHead){

    SimplyList<T>* newNode = new SimplyList<T>;

    newNode->data = newData;
    newNode->next = *currentHead;
    *currentHead = newNode;
}

template <typename T>
void sllGeneralInsert(T newData, SimplyList<T>* prevNode){

    if(prevNode == NULL){
        cout << "Previous node cannot be null." << endl;
        return;
    }

    SimplyList<T>* newNode = new SimplyList<T>;

    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

template <typename T>
void sllInsertEnd(T newData, SimplyList<T>** head){

    SimplyList<T>* newNode = new SimplyList<T>;
    SimplyList<T>* currentNode = *head;

    newNode->data = newData;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, SimplyList<T>** head){

    if(*head == NULL){
        return;
    }

    SimplyList<T>* currNode = *head;
    SimplyList<T>* prevNode = NULL;

    while(currNode != NULL && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    if(currNode == NULL){
        return;
    }

    if(prevNode == NULL){
        *head = currNode->next;
    }
    else{
        prevNode->next = currNode->next;
    }

    delete currNode;
}

template <typename T>
void sllDeleteList(SimplyList<T>** head){

    SimplyList<T>* current = *head;

    while(current != NULL){
        SimplyList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = NULL;
}

#endif
