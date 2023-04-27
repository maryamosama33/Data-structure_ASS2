//
// Created by Shahd on 4/27/2023.
//

#ifndef ASS2DS_CIRCULARLINKEDLIST_H
#define ASS2DS_CIRCULARLINKEDLIST_H

#include <iostream>
using namespace std;

template<class T>
class CircularLinkedList {
private:
    struct Node {
        T item;
        Node *next;
    };

    Node *first, *last;
    int length;

public:
    CircularLinkedList();
    bool isEmpty();
    int CircularLinkedListSize();
    void clear();
    void insertAtHead(T element);
    void insertAtEnd(T element);
    void insertAt(T element, int index);
    void replaceAt(T element , int index);
    void removeAtHead();
    void removeAtEnd();
    void removeAt(int index);
    T retrieveAt(int index);
    bool isItemAtEqual(T element , int index);
    bool isExist(T element);
    void swap(int firstItemIdx , int secondItemIdx);
    void print();

};
#endif //ASS2DS_CIRCULARLINKEDLIST_H
