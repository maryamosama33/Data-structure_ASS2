#include "QueueWithLinkedList.h"

template<class T>
QueueWithLinkedList<T>:: QueueWithLinkedList()
{
        first = last = NULL;
        length = 0;
}

template<class T>
bool QueueWithLinkedList<T> :: isEmpty()
{
    return first == NULL;
}

template<class T>
T QueueWithLinkedList<T> :: getFirst()
{
        if(!isEmpty())
            return first->item;
}

template<class T>
T QueueWithLinkedList<T> :: getLast()
{
        if(!isEmpty())
            return last->item;
}

template<class T>
void QueueWithLinkedList<T> :: enQueue(T element)
    {
        Node *newNode = new Node;
        newNode->item = element;
        newNode->next = NULL ;

        if(isEmpty())
        {
            first = newNode;
            last = first ;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }


template<class T>
void QueueWithLinkedList<T> :: deQueue()
{
        if(isEmpty())
            cout << "Queue is Empty";
        else
        {
            if (length == 1)
            {
                first = last = NULL ;
                length--;
            }

            else
            {
                Node *temp = first;
                first = first->next;
                temp->next = NULL;
                delete temp;
                length--;
            }
        }
}

template<class T>
void QueueWithLinkedList<T> :: clear()
{
        Node* curr = first;
        while (first != NULL)
        {
            first = first->next;
            delete curr;
            curr = first;
        }
        last = NULL;
        length = 0;
}

template<class T>
int QueueWithLinkedList<T> :: QueueSize()
{
        return length;
}

template<class T>
void QueueWithLinkedList<T> :: print()
    {
        Node *curr = first;
        if (isEmpty())
            cout << "Queue is Empty";
        else
        {
            while (curr != NULL)
            {
                cout << curr->item << ' ';
                curr = curr->next;
            }
        }
    }

