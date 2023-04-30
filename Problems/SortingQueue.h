#ifndef PRBLEMS_SORTINGQUEUE_H
#define PRBLEMS_SORTINGQUEUE_H

#include "QueueWithLinkedList.h"

template<class T>
void SortingQueue(QueueWithLinkedList<T> &qu) {
    int n = qu.QueueSize();
   
    for (int i = 0; i < n; i++) {
        T temp = qu.getFirst();
        qu.deQueue();
        for (int j = 0; j < n - 1; j++) {
            if (temp > qu.getFirst()) {
                qu.enQueue(qu.getFirst());
                qu.deQueue();
            } else {
                qu.enQueue(temp);
                temp = qu.getFirst();
                qu.deQueue();
            }
        }

        qu.enQueue(temp);
    }
}
#endif //PRBLEMS_SORTINGQUEUE_H
