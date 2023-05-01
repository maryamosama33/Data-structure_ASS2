
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
    void insertAt(t item , int index);
    void insertAfter(Node* pNode, int iData);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    t retrieveAt(int index);
    void replaceAt(t item,int index);
    bool isExist(t item);
    bool isItemEqual(t item,int index);
    void swap(int firstItemIdx, int secondItemIdx);
    void reverse();
    bool isEmpty();
    void clear();
    int doubleLinkedListSize();
    void forwardTraversal(); //Print from head to tail
    void backwardTraversal(); //Print from tail to head




//            o retrieveAt (int index): elementType
//    o replaceAt (elementType newElement, int index)
//    o isExist (elementType element) : bool
//            o isItemAtEqual (elementType element, int index) : bool
//            o swap (int firstItemIdx, int secondItemIdx) : void // swap two nodes without
//    swapping data.
//    o reverse () : void //reverse the data in the double linked list

};
//------------------------------//

template<class t>
bool doublyLinkedList<t>::isEmpty() {
    return head == nullptr;
}

//------------------------------//

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

//------------------------------//
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

//------------------------------//
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
//------------------------------//

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
//------------------------------//

template<class t>
void doublyLinkedList<t>::insertAtTail(t item) {

    if (isEmpty())
        insertAtHead(item);
    else{
        Node* newNode = new Node();
        newNode->data = item;
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
        newNode->next = nullptr;
    }

    size++;

}


//------------------------------//
template<class t>
void doublyLinkedList<t>::insertAt(t item, int index) {
    if (index < 0 || index >= size ) {
        cout << "This index doesn't exist! " << endl;

    }else if(index == 0){
        insertAtHead(item);
        size++;

    }else if (index == size-1){
        insertAtTail(item);
        size++;
    }
    else{
        Node* newNode = new Node();
        newNode->data = item;

          Node* temp = head;

        for (int i = 0; i < index-1; ++i) { // & & . & &   // index 3
           temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->previous = temp;
        if (newNode->next != nullptr) {
            newNode->next->previous = newNode;
        }
        size++;

    }
}


//------------------------------//
template<class t>
void doublyLinkedList<t>::insertAfter(doublyLinkedList::Node *pNode, int iData) {

    if (pNode == nullptr){
       cout << "cant insert, the previous node is null" <<endl;
        return;
    }


        Node* newNode = new Node();
        newNode->data = iData;
        newNode->next = pNode->next;
        pNode->next = newNode;
        newNode->previous = pNode;
    if (newNode->next != nullptr)
        newNode->next->previous = newNode;
    size++;

}

//------------------------------//
template<class t>
void doublyLinkedList<t>::removeAtHead() {
    if (isEmpty()) cout << "There is no elements to remove" << endl;
    else if (size == 1){
        delete head;
        tail = head = nullptr;
        size--;

    }
    else{
        Node* temp = head;
        head = head->next;
        head->previous = nullptr;
        delete temp;
        size--;


    }

}
//------------------------------//

template<class t>
void doublyLinkedList<t>::removeAtTail() {
    if (isEmpty()) cout << "There is no elements to remove" << endl;
    else if (size == 1){
        delete head;
        tail = head = nullptr;
        size--;
    }
    else{
        Node* temp = tail;
        tail = tail->previous;
        tail->next = nullptr;
        delete temp;
        size--;

    }
}


//------------------------------//
template<class t>
void doublyLinkedList<t>::removeAt(int index) {
    if (index < 0 || index >= size ) {
        cout << "This index doesn't exist! " << endl;

    }else if(index == 0){
        removeAtHead();
        size--;

    }else if (index == size-1){
        removeAtTail();
        size--;
    }
    else{

        Node* temp = head;

        for (int i = 0; i < index-1; ++i) { // & & . & &   // index 3
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        temp->next->previous = temp;
        delete delNode;


    }


}

//------------------------------//

template<class t>
t doublyLinkedList<t>::retrieveAt(int index) {
    if (index < 0 || index >= size ) {
        return -1;
    }
    else{


        Node* temp = head;

        for (int i = 0; i < index; ++i) { // & & . & &   // index 3
            temp = temp->next;
        }
        return temp->data;

    }
}

//------------------------------//

template<class t>
void doublyLinkedList<t>::replaceAt(t item, int index) {
    if (index < 0 || index >= size ) {
        cout << "This index doesn't exist! " << endl;

    }else{

        Node* temp = head;

        for (int i = 0; i < index; ++i) { // & & . & &   // index 3
            temp = temp->next;
        }
        temp->data = item;


    }
}

//------------------------------//

template<class t>
bool doublyLinkedList<t>::isExist(t item) {
    bool isFound = false;

    if (!isEmpty()){
        Node* temp = head;
        // passing throughout all nodes to check their data with the data give
        while (temp != nullptr){
            if (temp->data == item){
               isFound = true;
            }
            if (isFound) break;
        }
    }
        return isFound;

}

//------------------------------//

template<class t>
bool doublyLinkedList<t>::isItemEqual(t item, int index) {

    if (isExist(item) && (index < 0 || index >= size)){
        Node* temp = head;
        for (int i = 0; i < index ; ++i) {
            temp = temp->next;
        }
        if (temp->data == item) return true;
    }

    return false;

}

template<class t>
void doublyLinkedList<t>::reverse() {
    if (isEmpty()){
        cout << "NO elements to reverse,)"<< endl;
    }else if(size > 1){
        Node* current = head ;
        Node* temp = nullptr;  // this node to get back step of the current node to reverse

        while (current != nullptr){  //
            temp = current->previous;
            current->previous = current->next;
            current->next = temp;
            current = temp->previous;

            // if the temp not the head or the tail
            if (temp != nullptr)
            {
                head = temp->prev;
            }
        }
    }

}

//------------------------------//

template<class t>
void doublyLinkedList<t>::swap(int firstItemIdx, int secondItemIdx) { // & 7 & & 5 &
    if ( firstItemIdx < 0 || firstItemIdx >= size ) {
        cout << "first Item index is Invalid ,) " << endl;
        return;
    }
    if (secondItemIdx < 0 || secondItemIdx >= size){
        cout << "Second Item index is Invalid ,) " << endl;
        return;
    }

    Node *firstTemp  = head , *secondTemp = head;

    // two for loops to find the index of the two elements
    for (int i = 0; i < firstItemIdx ; ++i) {
        firstTemp = firstTemp->next;
    }
    for (int i = 0; i < secondItemIdx ; ++i) {
        secondTemp = secondTemp->next;
    }
    //cout << firstTemp->data << " " << secondTemp->data;

    Node* nextTemp ;
    nextTemp = firstTemp->next; // to save it until use it

    firstTemp->next = secondTemp->next;
    secondTemp->next = nextTemp;

    // check first if the next not null
    if (firstTemp->next != nullptr)
        firstTemp->next->previous = firstTemp;
    if (secondTemp->next != nullptr)
        secondTemp->next->previous = secondTemp;

    nextTemp = firstTemp->previous;

    firstTemp->previous = secondTemp->previous;
    secondTemp->previous = nextTemp;

    // check before the assigning if the previous is null
    if (firstTemp->previous != nullptr)
        firstTemp->previous->next = firstTemp;
    if (secondTemp->previous != nullptr)
        secondTemp->previous->next = secondTemp;







}

//------------------------------//






int main(){
    doublyLinkedList<int> d;
    d.insertAtHead(3);
    d.insertAtHead(50);
    d.forwardTraversal();
    d.insertAtTail(60);
    d.forwardTraversal();
    d.insertAt(28,2);
    d.forwardTraversal();
    d.replaceAt(89,2);
    d.forwardTraversal();
    d.swap(2,3);
    d.forwardTraversal();




}

#endif //IMPLEMENTATIONS_DOUBLYLINKEDLIST_H
