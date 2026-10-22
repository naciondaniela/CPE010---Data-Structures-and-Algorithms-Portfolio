#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

//circular array-based queue (per B.2 spec)
template <typename T>
class Queue{
    private:
        T* q_array;      //queue array pointer
        int q_capacity;   //queue capacity
        int q_size;       //queue size
        int q_front;      //subscript of front item
        int q_back;       //subscript of back item

    public:
        //Constructor: constructs an empty queue
        Queue(int capacity = 10){
            q_capacity = capacity;
            q_array = new T[q_capacity];
            q_size = 0;
            q_front = 0;
            q_back = -1;
        }

        //Copy Constructor: copies the entire queue array since elements may wrap around
        Queue(const Queue<T>& other){
            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;
            q_array = new T[q_capacity];
            for(int i = 0; i < q_capacity; i++){
                q_array[i] = other.q_array[i];
            }
        }

        //Copy Assignment Operator: replaces contents with a copy of another queue
        Queue<T>& operator=(const Queue<T>& other){
            if(this == &other){
                return *this;
            }
            delete[] q_array;

            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;
            q_array = new T[q_capacity];
            for(int i = 0; i < q_capacity; i++){
                q_array[i] = other.q_array[i];
            }
            return *this;
        }

        //Destructor: deletes the dynamically allocated array
        ~Queue(){
            delete[] q_array;
        }

        //Empty(): true if queue has no elements
        bool Empty(){
            return q_size == 0;
        }

        //Size(): number of elements currently stored
        int Size(){
            return q_size;
        }

        //Clear(): resets size and pointers, does not deallocate or resize
        void Clear(){
            q_size = 0;
            q_front = 0;
            q_back = -1;
        }

        //Front(): element at the front (next to be removed)
        T Front(){
            return q_array[q_front];
        }

        //Back(): element at the back (most recently added)
        T Back(){
            return q_array[q_back];
        }

        //Enqueue(): inserts a new element at the back
        void Enqueue(T newItem){
            if(q_size == q_capacity){
                std::cout << "Queue is full!" << std::endl;
                return;
            }
            q_back = (q_back + 1) % q_capacity;
            q_array[q_back] = newItem;
            q_size++;
        }

        //Dequeue(): removes the element at the front
        void Dequeue(){
            if(Empty()){
                std::cout << "Queue is empty!" << std::endl;
                return;
            }
            q_front = (q_front + 1) % q_capacity;
            q_size--;
        }
};

#endif



