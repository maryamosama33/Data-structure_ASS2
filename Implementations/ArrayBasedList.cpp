#include <iostream>
using namespace std;

template<class T>
class arrayBasedList{
private:
    T* list;       // pointer to the list
    int maxSize;   // maximum size of the list
    int size;      // current size of the list
public:

   arrayBasedList(int max=100);
   void insert(T element);
   void insertAt(T element, int index);
   T retrieveAt(int index);
   void removeAt(int index);
   void replaceAt(T newElement, int index);
   bool isItemAtEqual(T element, int index);
   bool isEmpty();
   bool isFull();
   int listSize();
   int maxListSize();
   void clear();
   void print();
   ~arrayBasedList();
};
//---------------------------------------------------------------------------
template<class T>
arrayBasedList<T>::arrayBasedList(int max) {
    maxSize = max;
    size=0;
    list = new T[maxSize];    // allocate memory for the list
}
//---------------------------------------------------------------------------
template<class T>
void arrayBasedList<T>::insert(T element) {
    if (isFull()) {
        cout << "List is full";
    }
    list[size] = element;
    size++;
}
//---------------------------------------------------------------------------
template<class T>
void arrayBasedList<T>::insertAt(T element, int index) {
    if (isFull()) {
        cout << "List is full";
    }
    if (index < 0 || index > size) {
        cout << "Invalid index";
    }
    // shift all elements to the right of the index to make space for the new element
    for (int i = size; i > index; i--) {
        list[i] = list[i-1];
    }
    list[index] = element;
    size++;
}
//---------------------------------------------------------------------------
template<class T>
T arrayBasedList<T>::retrieveAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index";
    }
    return list[index];
}
//---------------------------------------------------------------------------
template<class T>
void arrayBasedList<T>::removeAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index";
    }
    // shift all elements to the left of the index to remove the element at the index
    for (int i = index; i < size - 1; i++) {
        list[i] = list[i+1];
    }
    size--;
}
//---------------------------------------------------------------------------
template<class T>
void arrayBasedList<T>::replaceAt(T newElement, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index";
    }
    list[index] = newElement;
}
//---------------------------------------------------------------------------
template<class T>
bool arrayBasedList<T>::isItemAtEqual(T element, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index";
    }
    return list[index] == element;
}
//---------------------------------------------------------------------------
template<class T>
bool arrayBasedList<T>::isEmpty() {
    return size == 0;
}
//---------------------------------------------------------------------------
template<class T>
bool arrayBasedList<T>::isFull() {
    return size == maxSize;
}
//---------------------------------------------------------------------------
template<class T>
int arrayBasedList<T>::listSize() {
    return size;
}
//---------------------------------------------------------------------------
template<class T>
int arrayBasedList<T>::maxListSize() {
    return maxSize;
}
//---------------------------------------------------------------------------
template<class T>
void arrayBasedList<T>::clear() {
    size = 0;
}
//---------------------------------------------------------------------------
template<class T>
void arrayBasedList<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}
//---------------------------------------------------------------------------
template<class T>
arrayBasedList<T>::~arrayBasedList() {
    delete[] list; // deallocate memory for the list
}
//---------------------------------------------------------------------------
int main() {
    arrayBasedList<int> list(5); // creates a new ArrayList of maximum size 5
    list.insert(10); // adds 10 to the end of the list
    list.insert(20); // adds 20 to the end of the list
    list.insert(30); // adds 30 to the end of the list
    list.insertAt(15, 1); // adds 15 at index 1
    list.print(); // prints: 10 15 20 30
    cout << endl;
    list.replaceAt(25, 2); // replaces the element at index 2 with 25
    list.print(); // prints: 10 15 25 30
    cout << endl;
    list.removeAt(3); // removes the element at index 3
    list.print(); // prints: 10 15 25
    cout << endl;
    cout << "List size: " << list.listSize() << endl; // prints: List size: 3
    cout << "Maximum list size: " << list.maxListSize() << endl; // prints: Maximum list size: 5
    cout << "Is list empty? " << list.isEmpty() << endl; // prints: Is list empty? 0 (false)
    cout << "Is list full? " << list.isFull() << endl; // prints: Is list full? 0 (false)
    list.clear(); // clears all elements from the list
    cout << "Is list empty? " << list.isEmpty() << endl; // prints: Is list empty? 1 (true)
    return 0;
}
