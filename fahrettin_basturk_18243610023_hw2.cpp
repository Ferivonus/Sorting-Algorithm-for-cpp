#include <iostream>
#include "doubleLinkedList.h"

using namespace  std;


int main(){
    DoubleLinkedList dll;
    dll.insert(1);
    dll.insert(5);
    dll.insert(7);
    dll.insert(2);
    dll.insert(3);
    dll.insert(4);
    dll.insert(6);
    dll.print();
    dll.reversePrint();
    return 0;
}
