#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>

using namespace std;

class Job{
public:
    int id;
    string userName;
    int pages;

    Job(){
        id = 0;
        userName = "";
        pages = 0;
    }

    Job(int i, string user, int p){
        id = i;
        userName = user;
        pages = p;
    }
};

class JobNode{
public:
    Job data;
    JobNode* next;
};

class Printer{
private:
    JobNode* frontPtr;
    JobNode* backPtr;

public:
    Printer(){
        frontPtr = nullptr;
        backPtr = nullptr;
    }

    ~Printer(){
        while(frontPtr != nullptr){
            JobNode* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
        }
    }

    bool isEmpty(){
        return frontPtr == nullptr;
    }

    void addJob(Job newJob){
        JobNode* newNode = new JobNode;
        newNode->data = newJob;
        newNode->next = nullptr;

        if(frontPtr == nullptr){
            frontPtr = newNode;
            backPtr = newNode;
        }
        else{
            backPtr->next = newNode;
            backPtr = newNode;
        }

        cout << "[Queued] Job #" << newJob.id
             << " from " << newJob.userName
             << " (" << newJob.pages << " pages)"
             << endl;
    }

    void processAll(){
        if(isEmpty()){
            cout << "No pending jobs." << endl;
            return;
        }

        while(frontPtr != nullptr){
            Job currentJob = frontPtr->data;

            cout << "[Printing] Job #" << currentJob.id
                 << " from " << currentJob.userName
                 << " -- " << currentJob.pages
                 << " page(s)..."
                 << endl;

            JobNode* temp = frontPtr;
            frontPtr = frontPtr->next;

            if(frontPtr == nullptr){
                backPtr = nullptr;
            }

            delete temp;

            cout << "[Done] Job #" << currentJob.id
                 << " completed."
                 << endl;
        }
    }
};

#endif


