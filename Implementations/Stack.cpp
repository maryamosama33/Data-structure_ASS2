//
// Created by Salma ameer on 27/04/2023.
//

#include "Stack.h"
template<typename T>
bool Stack<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
void Stack<T>::push(T val) {

    Node<T> *newNode = new Node<T>();
    newNode->value = val;

    if (head == nullptr){
        head = newNode;
    }

    else{
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template<typename T>
T Stack<T>::pop() {

    T nodeVal = head->value;

    if (size == 1){
        free(head);
        head = nullptr;
    }
    else{
        Node<T> *temp = head;
        head = head->next;
        free(temp);
    }
    size--;
    return nodeVal;
}

template<typename T>
void Stack<T>::print() {

    Node<T> *temp = head;
    while (temp != nullptr){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

template<typename T>
T Stack<T>::top() {
    if (isEmpty()) cout << "This Stack is empty" << endl;
    else{
        return head->value;
    }
}

template<typename T>
int Stack<T>::stackSize() {
    return size;
}

template<typename T>
void Stack<T>::clear() {

    if (head != nullptr) {
        Node<T> temp = new Node<T>();
        while (head != nullptr) {
            temp = head;
            head = head->next;
            free(temp);
        }
        size = 0;
        cout << "Stack has been cleared!" << endl;

    }
}

