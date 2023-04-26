//
// Created by Salma ameer on 27/04/2023.
//

#ifndef DS_ASSIGN2_STACK_H
#define DS_ASSIGN2_STACK_H
#include <iostream>
using namespace std;

template<typename T>
struct Node {

    int value;
    Node *next;

    Node(){
        value = 0;
        next = nullptr;
    }
};


template<typename T>
class Stack {
private:
    int size;
    Node<T> *head;

public:
    Stack(){
        head = nullptr;
        size = 0;
    }

    bool isEmpty();
    void push(T val);
    T pop();
    T top();
    void print();
    int stackSize();
    void clear();

};


#endif //DS_ASSIGN2_STACK_H
