#include<iostream>
#include"queueArr.h"

int main(){
    Queue<char> q(10);

    std::cout << "Empty: " << q.Empty() << std::endl;

    q.Enqueue('D');
    q.Enqueue('A');
    q.Enqueue('N');
    q.Enqueue('I');
    q.Enqueue('E');
    q.Enqueue('L');
    q.Enqueue('A');

    std::cout << "Empty: " << q.Empty() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;

    q.Dequeue();
    std::cout << "After Dequeue -> Front: " << q.Front() << std::endl;

    q.Enqueue('!');
    std::cout << "After Enqueue('!') -> Back: " << q.Back() << std::endl;

    //test copy constructor
    Queue<char> qCopy = q;
    std::cout << "Copy Constructor -> Front: " << qCopy.Front() << " Back: " << qCopy.Back() << std::endl;

    //test copy assignment operator
    Queue<char> qAssigned(10);
    qAssigned = q;
    std::cout << "Copy Assignment -> Front: " << qAssigned.Front() << " Back: " << qAssigned.Back() << std::endl;

    //test Clear()
    q.Clear();
    std::cout << "After Clear -> Empty: " << q.Empty() << " Size: " << q.Size() << std::endl;

    return 0;
}



