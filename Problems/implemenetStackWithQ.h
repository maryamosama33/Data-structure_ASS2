//
// Created by Salma ameer on 01/05/2023.
//
#ifndef DS_ASSIGN2_IMPLEMENTSTACKWITHQ_H
#define DS_ASSIGN2_IMPLEMENTSTACKWITHQ_H

#include <iostream>
#include "QueueWithLinkedList.h"

using namespace std;

template<typename T>
class QStack{
private:
    QueueWithLinkedList<T> q1,q2;


public:
    void push(T item);
    T pop();
    T top();
    void printStack();

};

template<typename T>
void QStack<T>::push(T item) { //      2 5 4

    q2.enQueue(item);

    // Push all the remaining
    // elements in q1 to q2.
    while (!q1.isEmpty()) {
        q2.enQueue(q1.getFirst());
        q1.deQueue();
    }

    // swap the names of two queues
    QueueWithLinkedList<int> q = q1;
    q1 = q2;
    q2 = q;

}

template<typename T>
T QStack<T>::pop(){

    if (q1.isEmpty())
        return -1;
    q1.deQueue();
}

template<typename T>
T QStack<T>::top() {
    return q1.getFirst();
}

template<typename T>
void QStack<T>::printStack (){
    q1.print();
}

#endif //DS_ASSIGN2_IMPLEMENTSTACKWITHQ_H

