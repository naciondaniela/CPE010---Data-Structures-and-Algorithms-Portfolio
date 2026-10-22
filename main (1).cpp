#include <iostream>
#include "queueLL.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('D', &front, &back);
    std::cout << front->data <<" " << back->data << std::endl;
    enqueue('A', &front, &back);
    std::cout << front->data <<" " << back->data << std::endl;
    enqueue('N', &front, &back);
    std::cout << front->data <<" " << back->data << std::endl;
    enqueue('I', &front, &back);

    dequeue(&front, &back);
    std::cout << front->data <<" " << back->data << std::endl;
    dequeue(&front, &back);

    std::cout << "Front: " << checkFront(&front) << std::endl;
    std::cout << "Back: " << checkBack(&back) << std::endl;
    std::cout << "Display: ";
    displayAll(&front);

    return 0;
}