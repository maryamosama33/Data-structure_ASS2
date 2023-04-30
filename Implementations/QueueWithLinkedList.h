
#ifndef PRBLEMS_QUEUEWITHLINKEDLIST_H
#define PRBLEMS_QUEUEWITHLINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;

template<class T>
class QueueWithLinkedList{
    struct Node{
        T item ;
        Node *next;
    };
    Node *first , *last;
    int length;

public:
    QueueWithLinkedList(){
        first = last = NULL;
        length = 0;
    }
    //---------------------------//
    bool isEmpty(){
        return first == NULL;
    }
    //---------------------------//
    T getFirst()
    {
        if(!isEmpty())
            return first->item;
    }
    //---------------------------//
    T getLast()
    {
        if(!isEmpty())
            return last->item;
    }
    //---------------------------//
    void enQueue(T element)
    {
        Node *newNode = new Node;
        newNode->item = element;
        newNode->next = NULL ;

        if(isEmpty())
        {
            first = newNode;
            last = first ;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }
    //---------------------------//
    void deQueue(){
        if(isEmpty())
            cout << "Queue is Empty";
        else
        {
            if (length == 1)
            {
                first = last = NULL ;
                length--;
            }

            else
            {
                Node *temp = first;
                first = first->next;
                temp->next = NULL;
                delete temp;
                length--;
            }
        }
    }
    //---------------------------//
    void clear(){
        Node* curr = first;
        while (first != NULL)
        {
            first = first->next;
            delete curr;
            curr = first;
        }
        last = NULL;
        length = 0;
    }
    //---------------------------//
    int QueueSize(){
        return length;
    }
    //---------------------------//
    void print()
    {
        Node *curr = first;
        if (isEmpty())
            cout << "Queue is Empty";
        else
        {
            while (curr != NULL)
            {
                cout << curr->item << ' ';
                curr = curr->next;
            }
        }
    }
};


#endif //PRBLEMS_QUEUEWITHLINKEDLIST_H
