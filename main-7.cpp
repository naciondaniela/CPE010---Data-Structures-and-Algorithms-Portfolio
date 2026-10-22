#include<iostream>
#include<queue>

void display(std::queue<char> copyQ);

int main(){
    //create an object
    std::queue<char> myQ;

    myQ.push('D');
    myQ.push('A');
    myQ.push('N');
    myQ.push('I');
    myQ.push('E');
    myQ.push('L');
    myQ.push('A');

    display(myQ);
    //try all member function
    //empty
    std::cout << "Empty: " << myQ.empty() << std::endl;
    //size
    std::cout << "Size: " << myQ.size() << std::endl;
    //front
    std::cout << "Front: " << myQ.front() << std::endl;
    //back
    std::cout << "Back: " << myQ.back() << std::endl;
    //pop
    myQ.pop();
    //display
    display(myQ);
    //push
    myQ.push('!');
    //display
    display(myQ);


    return 0;
}
void display(std::queue<char> copyQ){
    //create a copy of the queue that was passed
    std::queue<char> c = copyQ;

    while(!c.empty()){
        std::cout<<" " <<c.front();
        c.pop();
    }
    std::cout<<"\n";
}


