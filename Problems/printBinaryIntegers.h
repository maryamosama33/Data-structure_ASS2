
#ifndef DATA_STRUCTURE_ASS2_PRINTBINARYINTEGERS_H
#define DATA_STRUCTURE_ASS2_PRINTBINARYINTEGERS_H
#include<bits/stdc++.h>
#include"QueueWithLinkedList.h"
using namespace std;

void printBinaryIntegers(int N) {
    QueueWithLinkedList<string> q;
    q.enQueue("1");
    for (int i = 0; i < N; i++) {
        string curr = q.getFirst();
        q.deQueue();
        cout << curr << " ";
        q.enQueue(curr + "0");
        q.enQueue(curr + "1");
    }
    cout<<endl;
}

#endif //DATA_STRUCTURE_ASS2_PRINTBINARYINTEGERS_H
