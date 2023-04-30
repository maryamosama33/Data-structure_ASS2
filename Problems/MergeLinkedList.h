
#ifndef DATA_STRUCTURE_ASS2_MERGELINKEDLIST_H
#define DATA_STRUCTURE_ASS2_MERGELINKEDLIST_H

#include<bits/stdc++.h>
#include "../Implementations/SingleLinkedList.h"
using namespace std;

template <class T>
singleLinkedList<T> mergeLinkedList(singleLinkedList<T> list1, singleLinkedList<T> list2) {
    singleLinkedList<T> mergedList;
    int i = 0, j = 0;

    //push the smaller element
    while (i < list1.linkedListSize() && j < list2.linkedListSize()) {
        if (list1.retrieveAt(i) < list2.retrieveAt(j)) {
            mergedList.insertAtTail(list1.retrieveAt(i));
            i++;
        }
        else {
            mergedList.insertAtTail(list2.retrieveAt(j));
            j++;
        }
    }

    //push the remaining elements
    while (i < list1.linkedListSize()) {
        mergedList.insertAtTail(list1.retrieveAt(i));
        i++;
    }
    while (j < list2.linkedListSize()) {
        mergedList.insertAtTail(list2.retrieveAt(j));
        j++;
    }
    return mergedList;
}

#endif //DATA_STRUCTURE_ASS2_MERGELINKEDLIST_H
