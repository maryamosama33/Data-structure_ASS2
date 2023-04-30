#include "Implementations/ArrayBasedList.h"
#include "Implementations/CircularLinkedList.h"
#include "Implementations/doublyLinkedList.h"
#include "Implementations/QueueWithLinkedList.h"
#include "Implementations/SingleLinkedList.h"
#include "Implementations/Stack.h"

//#include "Problems/longestValidParentheses.cpp"
//#include "Problems/printBinaryIntegers.cpp"
//#include "Problems/infixToPostfix.cpp"

int main(){
    ////Try array based list

    ////Try singly linked list

    ////Try doubly linked list

    ////Try circular linked list
//    CircularLinkedList<int> cll;
//    cll.insertAtHead(1);
//    cll.insertAtHead(2);
//    cll.insertAtHead(3);
//
//    cll.insertAtEnd(4);
//    cll.insertAtEnd(5);
//
//    cll.insertAt(6, 3);
//    cll.insertAt(7, 0);
//
//    cll.print();
//    cout << endl;
//
//    cll.removeAtHead();
//    cll.removeAtEnd();
//    cll.removeAt(2);
//
//    cll.print();
//    cout << endl;
//    cout << cll.retrieveAt(2) << endl;
//    cout << cll.isItemAtEqual(2, 3) << endl;
//
//    cll.replaceAt(8, 1);
//    cll.swap(0, 1);
//    cll.print();
//    cout << endl;

    /////Try Queue
//    QueueWithLinkedList<int> q;
//    q.enQueue(1);
//    q.enQueue(2);
//    q.enQueue(3);
//
//    cout << q.getFirst() << endl;
//    q.deQueue();
//
//    cout << q.getLast() << endl;
//    q.print();
//    cout << endl;
//    cout << q.QueueSize() << endl;

    /////Try Stack
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.print();
    cout << s.top() << endl;
    s.pop();
    cout << s.stackSize() << endl;
    s.print();

}