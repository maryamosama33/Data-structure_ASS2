#include <iostream>
using namespace std;

template<class T>
struct node{
    T data;
    node* next;
};

template<class T>
class singleLinkedList{
private:
private:
    node<T> *first, *last;
    int size;
public:
    singleLinkedList();
    void insertAtHead (T element);
    void insertAtTail (T element);
    void insertAt (T element, int index) ;
    void removeAtHead ();
    void removeAtTail ();
    void removeAt (int index);
    T retrieveAt (int index);
    void replaceAt (T newElement, int index);
    bool isExist (T element);
    bool isItemAtEqual (T element, int index);
    void swap (int firstItemIdx, int secondItemIdx);// swap two nodes without swapping data.
    bool isEmpty ();
    int linkedListSize ();
    void clear ();
    void print ();
    ~singleLinkedList();
};
//----------------------------------------------------
template<class T>
singleLinkedList<T>::singleLinkedList() {
   first = nullptr;
   last = nullptr;
   size=0;
}
//----------------------------------------------------
template<class T>
void singleLinkedList<T>::insertAtHead(T element)
{
    node<T>* newNode = new node<T>{element, nullptr};
    if (isEmpty()) {
        first = last = newNode;
    } else {
        newNode->next = first;
        first = newNode;
    }
    size++;
}
//----------------------------------------------------
template<class T>
void singleLinkedList<T>::insertAtTail(T element)
{
    node<T>* newNode = new node<T>{element, nullptr};
    if (isEmpty()) {
        first = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    size++;
}
//----------------------------------------------------
template<class T>
void singleLinkedList<T>::insertAt(T element, int index)
{
    if (index < 0 || index > size) {
        cout << "Index out of range" << endl;
    }
    if (index == 0) {
        insertAtHead(element);
        return;
    }
    if (index == size) {
        insertAtTail(element);
        return;
    }
    node<T>* newNode = new node<T>{element, nullptr};
    node<T>* current = first;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    size++;
}
//----------------------------------------------------
template<class T>
void singleLinkedList<T>::removeAtHead()
{
    if (isEmpty()) {
        cout << "List is empty" << endl;
    }
    node<T>* temp = first;
    first = first->next;
    delete temp;
    size--;
    if (isEmpty()) {
        last = nullptr;
    }
}
//----------------------------------------------------
template<class T>
void singleLinkedList<T>::removeAtTail()
{
    if (isEmpty()) {
        cout << "List is empty" << endl;
    }
    if (size == 1) {
        removeAtHead();
        return;
    }
    node<T>* current = first;
    while (current->next != last) {
        current = current->next;
    }
    delete last;
    last = current;
    last->next = nullptr;
    size--;
}
//----------------------------------------------------
template<class T>
void singleLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= size) {
        cout << "Index out of range" << endl;
    }
    if (index == 0) {
        removeAtHead();
        return;
    }
    if (index == size - 1) {
        removeAtTail();
        return;
    }
    node<T>* current = first;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    node<T>* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}
//----------------------------------------------------
template<class T>
T singleLinkedList<T>::retrieveAt(int index)
{
    if (index < 0 || index >= size) {
        cout << "Index out of range" << endl;
    }
    node<T>* current = first;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}
//----------------------------------------------------
template<class T>
void singleLinkedList<T>::replaceAt (T newElement, int index) {
    if (index >= size || index < 0) {
        cout << "Index out of range." << endl;
        return;
    }
    node<T>* current = first;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = newElement;
}
//----------------------------------------------------
template<class T>
bool singleLinkedList<T>::isExist (T element) {
    node<T>* current = first;
    while (current != nullptr) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}
//----------------------------------------------------
template<class T>
bool singleLinkedList<T>::isItemAtEqual (T element, int index) {
    if (index >= size || index < 0) {
        cout << "Index out of range." << endl;
        return false;
    }
    node<T>* current = first;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data == element;
}
//----------------------------------------------------
template<class T>
void singleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx){
    if (firstItemIdx < 0 || secondItemIdx < 0 || firstItemIdx >= size || secondItemIdx >= size) {
        std::cout << "Invalid indices" << std::endl;
        return;
    }
    if (firstItemIdx == secondItemIdx) {
        return;
    }
    node<T> *prevFirst = nullptr, *currentFirst = first;
    for (int i = 0; i < firstItemIdx; i++) {
        prevFirst = currentFirst;
        currentFirst = currentFirst->next;
    }
    node<T> *prevSecond = nullptr, *currentSecond = first;
    for (int i = 0; i < secondItemIdx; i++) {
        prevSecond = currentSecond;
        currentSecond = currentSecond->next;
    }
    if (currentFirst->next == currentSecond) {
        currentFirst->next = currentSecond->next;
        currentSecond->next = currentFirst;
        if (prevFirst != nullptr) {
            prevFirst->next = currentSecond;
        }
        else {
            first = currentSecond;
        }
        prevSecond->next = currentFirst;
    }
    else {
        if (prevFirst != nullptr) {
            prevFirst->next = currentSecond;
        }
        else {
            first = currentSecond;
        }

        if (prevSecond != nullptr) {
            prevSecond->next = currentFirst;
        }
        else {
            first = currentFirst;
        }

        node<T> *temp = currentSecond->next;
        currentSecond->next = currentFirst->next;
        currentFirst->next = temp;
    }
}
//----------------------------------------------------
template<class T>
bool singleLinkedList<T>::isEmpty () {
    return size == 0;
}
//----------------------------------------------------
template<class T>
int singleLinkedList<T>::linkedListSize () {
    return size;
}
//----------------------------------------------------
template<class T>
void singleLinkedList<T>::clear () {
    node<T>* current = first;
    while (current != nullptr) {
        node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    first = nullptr;
    last = nullptr;
    size = 0;
}
//----------------------------------------------------
template<class T>
void singleLinkedList<T>::print () {
    node<T>* current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
//----------------------------------------------------
template<class T>
singleLinkedList<T>::~singleLinkedList() {
    clear();
}
//----------------------------------------------------

int main() {
    singleLinkedList<int> list;
    cout << "Initial size of list: " << list.linkedListSize() << endl; // Output: 0

    // add some elements to the list
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.insertAtTail(4);
    list.insertAtTail(5);
    cout << "Size of list after adding elements: " << list.linkedListSize() << endl; // Output: 5
    list.print(); // Output: 1 2 3 4 5

    // check if an element exists in the list
    cout << "Is 3 in the list? " << list.isExist(3) << endl; // Output: 1 (true)
    cout << "Is 6 in the list? " << list.isExist(6) << endl; // Output: 0 (false)

    // replace an element at a specific index
    list.replaceAt(10, 2);
    list.print(); // Output: 1 2 10 4 5

    // check if an element at a specific index is equal to a given value
    cout << "Is the element at index 2 equal to 10? " << list.isItemAtEqual(10, 2) << endl; // Output: 1 (true)

    // swap two nodes without swapping data
    list.swap(1, 3);
    list.print(); // Output: 1 4 10 2 5

    // clear the list
    list.clear();
    cout << "Size of list after clearing: " << list.linkedListSize() << endl; // Output: 0

    return 0;
}
