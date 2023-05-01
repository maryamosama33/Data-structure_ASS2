
#ifndef DATA_STRUCTURE_ASS2_MERGELINKEDLIST_H
#define DATA_STRUCTURE_ASS2_MERGELINKEDLIST_H

#include<bits/stdc++.h>
#include "../Implementations/SingleLinkedList.h"
using namespace std;

//Merge K sorted linked lists
// You have k linked-lists, each linked-list is sorted in ascending order.
// You need to merge all the given linked-lists into one sorted linked-list then
//return it.
// Example:
//If the Input is an array of pointers storing the head nodes of following the
//linked lists: [1, 4, 5], [1, 3, 4], [2, 6].
//Then the Output Linked List will be: [1, 1, 2, 3, 4, 4, 5, 6]
//If the Input is an array of pointers storing the head nodes of following the
//linked lists: [1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10].
//Then the Output Linked List will be: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10].

//Solution
singleLinkedList<int> mergeKSortedLinkedLists(singleLinkedList<int> lists[], int k) {
    singleLinkedList<int> mergedList;
    int count = 0;
    while (count < k) {
        int minIndex = -1, minValue = INT_MAX;
        for (int i = 0; i < k; i++) {
            if (lists[i].linkedListSize() > 0 && lists[i].getHead()->data < minValue) {
                minValue = lists[i].getHead()->data;
                minIndex = i;
            }
        }
        if (minIndex >= 0) {
            mergedList.insertAtTail(minValue);
            lists[minIndex].removeAtHead();
            if (lists[minIndex].linkedListSize() == 0) {
                count++;
            }
        }
    }
    return mergedList;
}

#endif //DATA_STRUCTURE_ASS2_MERGELINKEDLIST_H
