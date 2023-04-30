
#ifndef IMPLEMENTATIONS_DOUBLYLINKEDLIST_H
#define IMPLEMENTATIONS_DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

template<class t>
class doublyLinkedList{
private:
    struct Node{
        Node* next;
        Node* previous;
        t data;
    };

    int size;
    Node* head;
    Node* tail;

public:

    doublyLinkedList(){
        size = 0;
        head = nullptr;
        tail = nullptr;
    };
    void insertAtHead(t item);
    void insertAtTail(t item);
    void swap(int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    void clear();
    int doubleLinkedListSize();
    void forwardTraversal(); //Print from head to tail
    void backwardTraversal(); //Print from tail to head


//            o insertAtTail (elementType element) : void
//            o insertAt (elementType element, int index) : void
//            o insertAfter (* prev_node, int data) : void
//            o removeAtHead () : void
//            o removeAtTail () : void
//            o removeAt (int index) : void
//            o retrieveAt (int index): elementType
//    o replaceAt (elementType newElement, int index)
//    o isExist (elementType element) : bool
//            o isItemAtEqual (elementType element, int index) : bool
//            o swap (int firstItemIdx, int secondItemIdx) : void // swap two nodes without
//    swapping data.
//    o reverse () : void //reverse the data in the double linked list

};

template<class t>
bool doublyLinkedList<t>::isEmpty() {
    return head == nullptr;
}

template<class t>
void doublyLinkedList<t>::clear() {
    if (head != nullptr){
       Node* temp = new Node;

        while (head != nullptr){
            temp = head ;
            head = head->next;
            free(temp);
        }
        size = 0;
        cout << "list has been cleared!" << endl;
    }
}

template<class t>
int doublyLinkedList<t>::doubleLinkedListSize() {
    return size;
}

template<class t>
void doublyLinkedList<t>::forwardTraversal() {

    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;


}

template<class t>
void doublyLinkedList<t>::backwardTraversal() {
    if (!isEmpty()){
        Node* temp = tail;

        while (temp != nullptr){

            cout << temp->data << " ";
            temp = temp->previous;
        }

        cout << endl;
    }

}

template<class t>
void doublyLinkedList<t>::insertAtHead(t item) {
    // make newNode node to store the new node on it
    Node* newNode = new Node();
    newNode->data = item;

    if (isEmpty()){
        head = tail = newNode;

    }else{

        newNode->next = head;
        newNode->previous = nullptr;
        head ->previous = newNode;
        head = newNode;
    }

    size++;

}

#endif //IMPLEMENTATIONS_DOUBLYLINKEDLIST_H
