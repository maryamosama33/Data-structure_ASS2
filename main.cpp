#include "Implementations/ArrayBasedList.h"
#include "Implementations/CircularLinkedList.h"
#include "Implementations/doublyLinkedList.h"
#include "Implementations/QueueWithLinkedList.h"
#include "Implementations/SingleLinkedList.h"
#include "Implementations/Stack.h"
#include "Implementations/doublyLinkedList.h"

#include "Problems/SortingQueue.h"
#include "Problems/longestValidParentheses.h"
#include "Problems/printBinaryIntegers.h"
#include "Problems/infixToPostfix.h"

int main(){
    ///++++++++++++++++++++++Implementations++++++++++++++++++++++///

    ////Try array based list
//    arrayBasedList<int> list(5); // creates a new ArrayList of maximum size 5
//    list.insert(10); // adds 10 to the end of the list
//    list.insert(20); // adds 20 to the end of the list
//    list.insert(30); // adds 30 to the end of the list
//    list.insertAt(15, 1); // adds 15 at index 1
//    list.print(); // prints: 10 15 20 30
//    cout << endl;
//    list.replaceAt(25, 2); // replaces the element at index 2 with 25
//    list.print(); // prints: 10 15 25 30
//    cout << endl;
//    list.removeAt(3); // removes the element at index 3
//    list.print(); // prints: 10 15 25
//    cout << endl;
//    cout << "List size: " << list.listSize() << endl; // prints: List size: 3
//    cout << "Maximum list size: " << list.maxListSize() << endl; // prints: Maximum list size: 5
//    cout << "Is list empty? " << list.isEmpty() << endl; // prints: Is list empty? 0 (false)
//    cout << "Is list full? " << list.isFull() << endl; // prints: Is list full? 0 (false)
//    list.clear(); // clears all elements from the list
//    cout << "Is list empty? " << list.isEmpty() << endl; // prints: Is list empty? 1 (true)

    ////Try singly linked list
//    singleLinkedList<int> list;
//    cout << "Initial size of list: " << list.linkedListSize() << endl; // Output: 0
//
//    list.insertAtHead(3);
//    list.insertAtHead(2);
//    list.insertAtHead(1);
//    list.insertAtTail(4);
//    list.insertAtTail(5);
//    cout << "Size of list after adding elements: " << list.linkedListSize() << endl; // Output: 5
//    list.print(); // Output: 1 2 3 4 5
//
//    cout << "Is 3 in the list? " << list.isExist(3) << endl; // Output: 1 (true)
//    cout << "Is 6 in the list? " << list.isExist(6) << endl; // Output: 0 (false)
//
//    list.replaceAt(10, 2);
//    list.print(); // Output: 1 2 10 4 5
//
//    cout << "Is the element at index 2 equal to 10? " << list.isItemAtEqual(10, 2) << endl; // Output: 1 (true)
//
//    list.swap(1, 3);
//    list.print(); // Output: 1 4 10 2 5
//
//    list.clear();
//    cout << "Size of list after clearing: " << list.linkedListSize() << endl; // Output: 0

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


    ////Try MergeLinkedList

}