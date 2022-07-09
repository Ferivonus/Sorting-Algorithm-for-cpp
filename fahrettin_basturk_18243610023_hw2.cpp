#include <iostream>
#include "doubleLinkedList.h"

using namespace  std;


int main(){
    DoubleLinkedList dll;
    dll.add(1);
    dll.add(5);
    dll.add(7);
    dll.add(2);
    dll.add(3);
    dll.add(4);
    dll.add(6);
    cout <<"created shorted list is:" <<endl;
    cout <<"Print all values in ascending order" << endl;
    dll.print();
    cout <<"Print all values in descending order" << endl;
    dll.reversePrint();
    /*
    Forward Index of 30 is: 2
    Backward Index of 30 is: 4
    */
    //cout <<"forward index of 30 is: " << dll.forwardIndex(30) << endl;
   // cout <<"backward index of 30 is: " << dll.backwardIndex(30) << endl;
    cout <<"SortedLinkedList includes " << dll.getSize() << " number of nodes" << endl;
    return 0;
}
