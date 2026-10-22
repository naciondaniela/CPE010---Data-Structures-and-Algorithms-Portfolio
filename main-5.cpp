#include <iostream>
#include "listStack.h"

int main(){
    std::cout<<"-------- Pushing 'I' 'E' 'E' 'E' -------- \n";

    //pushing
    push('I');
    push('E');
    push('E');
    push('E');

    //display all
    std::cout<<"-------- Displaying all elements in the stack -------- \n";
    displayAll<char>();

    //display top
    Top<char>();
    //pop and print each element
    std::cout<<"-------- Popping 'E' 'E' 'E' 'I'-------- \n";
    while(!isEmpty<char>()){
        std::cout<<"Popping: "<<pop<char>()<<std::endl;
    }

    //test stack underflow
    pop<char>();

    return 0;
}
