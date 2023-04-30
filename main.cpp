#include "Implementations/ArrayBasedList.h"
#include "Implementations/CircularLinkedList.h"
#include "Implementations/doublyLinkedList.h"
#include "Implementations/QueueWithLinkedList.h"
#include "Implementations/SingleLinkedList.h"
#include "Implementations/Stack.h"

#include "Problems/SortingQueue.h"
#include "Problems/longestValidParentheses.h"
#include "Problems/printBinaryIntegers.h"
#include "Problems/infixToPostfix.h"

int main(){
    ///++++++++++++++++++++++Implementations++++++++++++++++++++++///

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
//    Stack<int> s;
//    s.push(1);
//    s.push(2);
//    s.push(3);
//
//    s.print();
//    cout << s.top() << endl;
//    s.pop();
//    cout << s.stackSize() << endl;
//    s.print();

    ///++++++++++++++++++++++Problems++++++++++++++++++++++///
    /////Try Sorting Queue
//    QueueWithLinkedList<int> q;
//    q.enQueue(5);
//    q.enQueue(3);
//    q.enQueue(1);
//    q.enQueue(2);
//
//    SortingQueue(q);
//    q.print();
//    cout << endl;

    /////Try Longest Valid Parentheses
//    string s = "(()";
//    cout << longestValidParentheses(s) << endl;

    /////Try Print Binary Integers
//    int N = 3;
//    printBinaryIntegers(N);

    /////Try Infix to Postfix
//    string infix = "X^Y / (5*Z) + 2";
//    string postfix = infixToPostfix(infix);
//    cout << postfix << endl;


}