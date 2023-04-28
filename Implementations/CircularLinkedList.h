//
// Created by T on 4/28/2023.
//

#ifndef PRBLEMS_CIRCULARLINKEDLIST_H
#define PRBLEMS_CIRCULARLINKEDLIST_H

#include <iostream>
using namespace std;

template<class T>
class CircularLinkedList
{
private:
    struct Node
    {
        T item;
        Node *next;
    };

    Node *first , *last;
    int length;

public:
    CircularLinkedList(){
        first = nullptr;
        last = nullptr;
        length = 0;
    }
    //------------------------------//
    bool isEmpty(){
        return length == 0;
    }
    //------------------------------//
    int CircularLinkedListSize(){
        return length;
    }
    //------------------------------//
    void clear(){
        first = last = nullptr;
        length = 0;
    }
    //------------------------------//
    void insertAtHead(T element){
        Node *newNode = new Node();
        newNode->item = element;

        if (length == 0)
            first = last = newNode;

        else{
            last->next = newNode;
            newNode->next = first;
            first = newNode;
        }
        length++;
    }
    //-----------------------------//
    void insertAtEnd(T element){
        Node *newNode = new Node();
        newNode->item = element;
        if(length == 0)
            first = last = newNode;
        else
        {
            last->next = newNode;
            newNode->next = first;
            last = newNode;
        }
        length++;
    }
    //-----------------------------//
    void insertAt(T element, int index){
        Node* newNode = new Node ;
        newNode->item = element ;

        if(index == 0)
            insertAtHead(element);
        else if(index == length)
            insertAtEnd(element);
        else
        {
            Node *Curr = first;
            for(int i = 0 ; i < index - 1 ; i++)
                Curr = Curr->next;

            newNode->next = Curr->next;
            Curr->next = newNode;
        }
        length++;
    }
    //-----------------------------//
    void replaceAt(T element , int index){

        if (index == 0)
            first->item = element;
        else if(index == length - 1)
            last->item = element;
        else{
            Node *Curr = first;
            for(int i = 0 ; i < index ; i++)
                Curr = Curr->next;

            Curr->item = element;
        }
    }
    //-----------------------------//
    void removeAtHead(){
        if(length == 0)
            return;
        else if (length == 1)
        {
            delete first;
            first = last = NULL;
            length--;
        }
        else
        {
            Node* Curr = first;
            first = first->next;
            last->next = first;
            delete Curr;
            length--;
        }
    }
    //-----------------------------//
    void removeAtEnd(){
        if(length == 0)
            return;
        else if (length == 1)
        {
            delete first;
            first = last = NULL;
            length--;
        }
        else
        {
            Node* Curr = first;
            for(int i = 0 ; i < length - 2 ; i++)
                Curr = Curr->next;

            delete last;
            last = Curr;
            last->next = first;
            length--;
        }
    }
    //-----------------------------//
    void removeAt(int index){
        if (index == 0)
            removeAtHead();
        else if(index == length - 1)
            removeAtEnd();
        else{
            Node *Curr = first;
            for(int i = 0 ; i < index - 1 ; i++)
                Curr = Curr->next;

            Node *temp = Curr->next;
            Curr->next = temp->next;
            delete temp;
            length--;
        }
    }
    //-----------------------------//
    T retrieveAt(int index){
        if(index == 0)
            return first->item;
        else if(index == length - 1)
            return last->item;
        else{
            Node *Curr = first;
            for (int i = 0 ; i < index ; i++)
                Curr = Curr->next;

            return Curr->item;
        }
    }
    //-----------------------------//
    bool isItemAtEqual(T element , int index){
        if (index == 0)
        {
            if(first->item == element)
                return true;
        }
        else if (index == length - 1)
        {
            if(last->item == element)
                return true;
        }
        else
        {
            Node *Curr = first;
            for (int i = 0 ; i < index ; i++)
                Curr = Curr->next;

            if(Curr->item == element)
                return true;
        }
        return false;
    }
    //-----------------------------//
    bool isExist(T element){
        Node *Curr = first;
        if (length == 0)
            return false;
        else{
            while (Curr){
                if (Curr->item == element)
                    return true;
                Curr = Curr->next;
                if (Curr == first)
                    break;
            }
        }
        return false;
    }
    //-----------------------------//
    void swap(int firstItemIdx , int secondItemIdx){
        T temp = retrieveAt(firstItemIdx);
        replaceAt(retrieveAt(secondItemIdx) , firstItemIdx);
        replaceAt(temp , secondItemIdx);
    }
    //-----------------------------//
    void print(){
        Node *Curr = first;
        if (length == 0)
            cout << "Empty List" << endl;
        else{
            while (Curr){
                cout << Curr->item << " ";
                Curr = Curr->next;
                if (Curr == first)
                    break;
            }
        }
    }
};

#endif //PRBLEMS_CIRCULARLINKEDLIST_H
