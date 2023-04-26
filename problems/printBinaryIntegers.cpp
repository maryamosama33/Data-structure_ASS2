#include<bits/stdc++.h>
#include"QueueWithLinkedList.cpp"
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


int main() {
    int N = 3;
    printBinaryIntegers(N);
    return 0;
}
