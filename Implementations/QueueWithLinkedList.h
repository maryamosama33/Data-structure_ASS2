//
// Created by T on 4/27/2023.
//

#ifndef ASS2DS_QUEUEWITHLINKEDLIST_H
#define ASS2DS_QUEUEWITHLINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;

template<class T>
class QueueWithLinkedList {
    struct Node {
        T item;
        Node *next;
    };
    Node *first, *last;
    int length;

public:
    QueueWithLinkedList();
    bool isEmpty();
    T getFirst();
    T getLast();
    void enQueue(T element);
    void deQueue();
    void clear();
    int QueueSize();
    void print();
};
#endif //ASS2DS_QUEUEWITHLINKEDLIST_H
