#include <iostream>
#include "doubleLinkedList.h"

using namespace  std;


int main(){
    DoubleLinkedList<int> list;
    list.add(20);
    list.add(90);
    list.add(70);
    list.add(60);
    list.add(30);
    
    cout <<"created shorted list is:" <<endl;
    cout <<"Print all values in ascending order" << endl;
    list.print_ascending();
    cout <<"Print all values in descending order" << endl;
    list.print_descending();
    /*
    Forward Index of 30 is: 2
    Backward Index of 30 is: 4
    */
    //cout <<"forward index of 30 is: " << dll.forwardIndex(30) << endl;
    //cout <<"backward index of 30 is: " << dll.backwardIndex(30) << endl;
    cout <<"forward index of 30 is: " << list.forwardIndex(30) << endl;
    cout <<"backward index of 30 is: " << list.backwardIndex(30) << endl;
    cout <<"SortedLinkedList includes " << list.getSize() << " number of nodes" << endl;
    return 0;
}
