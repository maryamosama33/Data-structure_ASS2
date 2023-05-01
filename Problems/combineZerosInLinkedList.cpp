//
// Created by Salma ameer on 01/05/2023.
//
#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

node<int> *combineNodesBetweenZeros(node<int> *head) {
    node<int> *newHead = nullptr;
    node<int> *newTail = nullptr;
    int sum = 0;
    while (head != nullptr) {
        if (head->data == 0) {
            if (sum != 0) {
                node<int> *newNode = new node<int>;
                newNode->data = sum;
                if (newHead == nullptr) {
                    newHead = newNode;
                    newTail = newNode;
                } else {
                    newTail->next = newNode;
                    newTail = newNode;
                }
                sum = 0;
            }
        } else {
            sum += head->data;
        }
        head = head->next;
    }
    return newHead;
}

