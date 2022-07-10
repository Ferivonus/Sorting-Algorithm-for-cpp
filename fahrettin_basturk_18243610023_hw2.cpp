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
    
    
    cout <<"forward index of 30 is: " << list.forwardIndex(30) << endl;
    cout <<"backward index of 30 is: " << list.backwardIndex(30) << endl;
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
