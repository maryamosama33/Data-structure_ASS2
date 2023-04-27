#include "CircularLinkedList.h"
template<class T>
CircularLinkedList<T>:: CircularLinkedList()
{
    first = nullptr;
    last = nullptr;
    length = 0;
}


template<class T>
bool CircularLinkedList<T>:: isEmpty()
{
    return length == 0;
}


template<class T>
int CircularLinkedList<T> :: CircularLinkedListSize()
{
        return length;
}


template<class T>
void CircularLinkedList<T> :: clear()
{
        first = last = nullptr;
        length = 0;
}


template<class T>
void CircularLinkedList<T> :: insertAtHead(T element)
{
        Node *newNode = new Node();
        newNode->item = element;

        if (length == 0)
            first = last = newNode;

        else{
            last->next = newNode;
            newNode->next = first;
            first = newNode;
        }
        length++;
}


template<class T>
void CircularLinkedList<T> :: insertAtEnd(T element)
{
        Node *newNode = new Node();
        newNode->item = element;
        if(length == 0)
            first = last = newNode;
        else
        {
            last->next = newNode;
            newNode->next = first;
            last = newNode;
        }
        length++;
}


template<class T>
void CircularLinkedList<T> :: insertAt(T element, int index)
{
        Node* newNode = new Node ;
        newNode->item = element ;

        if(index == 0)
            insertAtHead(element);
        else if(index == length)
            insertAtEnd(element);
        else
        {
            Node *Curr = first;
            for(int i = 0 ; i < index - 1 ; i++)
                Curr = Curr->next;

            newNode->next = Curr->next;
            Curr->next = newNode;
        }
            length++;
}


template<class T>
void CircularLinkedList<T> :: replaceAt(T element , int index)
{

        if (index == 0)
            first->item = element;
        else if(index == length - 1)
            last->item = element;
        else{
            Node *Curr = first;
            for(int i = 0 ; i < index ; i++)
                Curr = Curr->next;

            Curr->item = element;
        }
}


template<class T>
void CircularLinkedList<T> :: removeAtHead()
{
        if(length == 0)
            return;
        else if (length == 1)
        {
            delete first;
            first = last = NULL;
            length--;
        }
        else
        {
            Node* Curr = first;
            first = first->next;
            last->next = first;
            delete Curr;
            length--;
        }
}


template<class T>
void CircularLinkedList<T> :: removeAtEnd()
{
        if(length == 0)
            return;
        else if (length == 1)
        {
            delete first;
            first = last = NULL;
            length--;
        }
        else
        {
            Node* Curr = first;
            for(int i = 0 ; i < length - 2 ; i++)
                Curr = Curr->next;

            delete last;
            last = Curr;
            last->next = first;
            length--;
        }
}


template<class T>
void CircularLinkedList<T> :: removeAt(int index)
{
        if (index == 0)
            removeAtHead();
        else if(index == length - 1)
            removeAtEnd();
        else{
            Node *Curr = first;
            for(int i = 0 ; i < index - 1 ; i++)
                Curr = Curr->next;

            Node *temp = Curr->next;
            Curr->next = temp->next;
            delete temp;
            length--;
        }
}


template<class T>
T  CircularLinkedList<T> ::retrieveAt(int index) {
    if(index == 0)
            return first->item;
        else if(index == length - 1)
            return last->item;
        else{
            Node *Curr = first;
            for (int i = 0 ; i < index ; i++)
                Curr = Curr->next;

            return Curr->item;
        }
}


template<class T>
bool CircularLinkedList<T> :: isItemAtEqual(T element , int index)
{
        if (index == 0)
        {
            if(first->item == element)
                return true;
        }
        else if (index == length - 1)
        {
            if(last->item == element)
                return true;
        }
        else
        {
            Node *Curr = first;
            for (int i = 0 ; i < index ; i++)
                Curr = Curr->next;

            if(Curr->item == element)
                return true;
        }
        return false;
}


template<class T>
bool CircularLinkedList<T> :: isExist(T element)
{
        Node *Curr = first;
        if (length == 0)
            return false;
        else{
            while (Curr){
                if (Curr->item == element)
                    return true;
                Curr = Curr->next;
                if (Curr == first)
                    break;
            }
        }
        return false;
}


template<class T>
void CircularLinkedList<T> :: swap(int firstItemIdx , int secondItemIdx)
{
        T temp = retrieveAt(firstItemIdx);
        replaceAt(retrieveAt(secondItemIdx) , firstItemIdx);
        replaceAt(temp , secondItemIdx);
}


template<class T>
void CircularLinkedList<T> :: print()
{
        Node *Curr = first;
        if (length == 0)
            cout << "Empty List" << endl;
        else{
            while (Curr){
                cout << Curr->item << " ";
                Curr = Curr->next;
                if (Curr == first)
                    break;
            }
        }
}







