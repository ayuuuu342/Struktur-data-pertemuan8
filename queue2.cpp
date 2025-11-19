#include <iostream>
#include "queue2.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = -1;
    Q.tail = -1;
    Q.count = 0;
}

bool isEmpty(queue Q) {
    return (Q.count == 0);
}

bool isFull(queue Q) {
    return (Q.count == MAX_QUEUE);
}

void enqueue(queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
     Q.tail++; //code untuk queue biasa dan alternatif 2
     Q.tail = (Q.tail + 1) % MAX_QUEUE; // code untuk alternatif 3
    }

    Q.info[Q.tail] = x;
    Q.count++;
}

int dequeue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return -1;
    }

    int x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--; //code untuk queue biasa
        Q.tail++; //code untuk alternatif 2
        Q.head = (Q.head + 1) % MAX_QUEUE; // code untuk alternatif 3

    }

    Q.count--;
    return x;
}

void printInfo(queue Q)
{
    cout << Q.head << " - " << Q.tail << "   | ";

    if (isEmpty(Q)) {
        cout << "empty queue\n";
        return;
    }

// code untuk queue biasa dan alternatif 2
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << "\n";

// code untuk alternatif 3
    int i = Q.head;
for (int c = 0; c < Q.count; c++) {
    cout << Q.info[i] << " ";
    i = (i + 1) % MAX_QUEUE;
}

}

