#include<iostream>
#include"printer.h"

int main(){
    Printer officePrinter;

    //simulate multiple users sending print jobs to the shared printer
    officePrinter.addJob(Job(1, "Daniela", 5));
    officePrinter.addJob(Job(2, "Joy", 2));
    officePrinter.addJob(Job(3, "Barbie", 10));
    officePrinter.addJob(Job(4, "CJ", 1));

    std::cout << "\n--- Printer now processing all jobs ---\n" << std::endl;
    officePrinter.processAll();

    std::cout << "\n--- Trying to process an empty queue ---\n" << std::endl;
    officePrinter.processAll();

    return 0;
}


