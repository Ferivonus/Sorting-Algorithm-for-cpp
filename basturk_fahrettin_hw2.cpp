//author: Fahrettin Basturk
//date: 10/07/2022
//description: This program is a code that making lists and sorting them, and there are also some of functions like ascending and descending print with delate and add functions.
//version: Possible Final.
//language: cpp
//path: basturk_fahrettin_hw2.cpp


#include <iostream>
#include "doubleLinkedList.h"

using namespace  std;


int main(){
    DoubleLinkedList<int> list; 

    // add some info
    list.add(20);
    list.add(90);
    list.add(70);
    list.add(60);
    list.add(30);

    // print the list
    cout <<"Created SortedLinkedList is:" <<endl;
    cout <<"Print all values in ascending order" << endl;
    list.print_ascending();
    cout <<"Print all values in descending order" << endl;
    list.print_descending();
    
    // show forward and backward index of the data and showing how much data is in the list.
    list.index(30);
    cout <<"SortedLinkedList includes " << list.getSize() << " number of nodes" << endl;

    /*

        create a node to delate with data 70:
        Node<int> *newNode = new Node<int>;

        newNode->data = 70;
        newNode->next = NULL;
        newNode->prev = NULL; 

        use remove function and use it a node to remove:

        if (list.Remove(newNode->data) == 0) {
            cout << "Removed node with data " << newNode->data << endl;
        } else {
            cout << "Could not remove node with data " << newNode->data << endl;
        }

        or just use the remove function with data 70:

        if (list.Remove(70) == 0) {
            cout << "Removed node with data " << 70 << endl;
        } else {
            cout << "Could not remove node with data " << 70 << endl;
        }

    */
    return 0;
}
