#ifndef LIST_STACK_H
#define LIST_STACK_H

#include <iostream>

template <typename T>
class Node{
    public:
    T data;
    Node<T>* next = nullptr;
};

//create a pointer/reference tip that always points to current top node

//global
template <typename T>
Node<T>* head = nullptr;

//pushing operation:
template <typename T>
void push(T newData){
    //create a new node
    Node<T>* newNode = new Node<T>();
    //assign the data to the newnode
    newNode->data = newData;
    //point the newNode next to the current top
    newNode->next = head<T>;
    //assign the new Top to the new Node
    head<T> = newNode;
}

//isEmpty()
template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

template <typename T>
T pop(){
    // if the stack is empty error catch:
    if(isEmpty<T>()) {
        std::cout<<"Stack Underflow"<<std::endl;
        return T(); // Return default-constructed value
    }
    // saving a current top node to a temporary variable
    Node<T>* temp = head<T>;
    //store the data of the top node to a temporary variable
    T tempVal = temp->data;
    //move the head to next node
    head<T> = head<T>->next;
    //free up the memory
    delete temp;
    //return the temporary variable data
    return tempVal;
}

template <typename T>
void Top(){
    //what if the stack is empty?
    if(isEmpty<T>()){
        std::cout<<"Stack is empty"<<std::endl;
        return;
    }
    std::cout<<"The top is: " << head<T> ->data<<std::endl;
}

template <typename T>
void displayAll(){
    //check if the stack is empty
    if(isEmpty<T>()) {
        std::cout<<"Stack is empty"<<std::endl;
        return;
    }
    //use a temp pointer so we don't destroy the actual stack while walking it
    std::cout<<"Stack (top to bottom): ";
    Node<T>* temp = head<T>;
    while(temp != nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}
#endif