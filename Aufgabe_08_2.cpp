/*** Aufgabe_08_2.cpp ***/
#include <iostream>
#include "pch.h"

#include "Aufgabe_08_2.h"

int main() {
    unsigned int const n = 7;
    int data[] = { 1, 2, 2, -2, 1, -6, 8 };

    Queue<int> queue1;

    for (unsigned int i = 0; i < n; ++i) {
        queue1.enq(data[i]);
    }

    queue1.print();

    // Testaufruf von insertAfter()
    // Einfuegen nach dem ersten Element
    queue1.insertAfter(queue1.frontObj(), 3);
    queue1.print();

    // Testaufruf von manifold()
    queue1.manifold();
    queue1.print();

    return 0;
}
/*
1, 2, 2, -2, 1, -6, 8
1, 2, 2, -2, 1, -6, 8
1, 2, 2, -2, 1, -6, 8
*/
/********* Ende *********/
