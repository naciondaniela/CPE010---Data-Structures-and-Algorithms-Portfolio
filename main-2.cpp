#include<iostream>
#include <stack> //call the stack from STL.

int main(){

    std::stack<int> newStack; //created an object

    //testing the empty() function to check if the stack is empty.
    std::cout<<"Is the stack empty? "<< newStack.empty()<<std::endl;

    //insert a 3 elements:
    newStack.push(3);
    std::cout<<"Top of stack: "<<newStack.top()<<std::endl;
    newStack.push(2);
    std::cout<<"Top of stack: "<<newStack.top()<<std::endl;
    newStack.push(1);
    std::cout<<"Top of stack: "<<newStack.top()<<std::endl;

    std::cout<<"Is the stack empty? "<<newStack.empty()<<std::endl;
    newStack.push(6);
    newStack.push(7);
    newStack.push(8);

    std::cout<<"Size of the stack is: " << newStack.size()<<std::endl;

    //swap?? -? swap the content of the public member functions

    //emplace -> construct and insert element -> public member function

    return 0;
}
