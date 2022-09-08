#include "split.h"
#include <iostream>

void printNodes(struct Node* node) {
    while (node) {
        std::cout << "value: " << node->value << std::endl;
        node = node->next;
    }
}

int main()
{
    std::cout << "Hello World!\n";
    Node* n = new Node(1, new Node(2, new Node(3, nullptr)));
    Node* e = nullptr;
    Node* o = nullptr;
    split(n, o, e);
    std::cout << "input: ";
    printNodes(n);
    std::cout << "evens: ";
    printNodes(e);
    std::cout << "odds: ";
    printNodes(o);

    delete e;
    delete o->next;
    delete o;
}