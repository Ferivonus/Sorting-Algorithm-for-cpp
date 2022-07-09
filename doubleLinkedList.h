#ifndef DoubleLinkedlist_H_
#define DoubleLinkedlist_H_

#include <iostream>
#include <cassert>

namespace std {
template <class T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *prev;
};

//double linked list
template <class T>
class DoubleLinkedList {
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    //sorted list shorted by data
    void add(T data) {
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            Node<T> *AddedModes = head;
            while (AddedModes->next != NULL && AddedModes->data < data) {
                AddedModes = AddedModes->next;
            }
            if (AddedModes->data < data) {
                AddedModes->next = newNode;
                newNode->prev = AddedModes;
                tail = newNode;
            } else {
                newNode->next = AddedModes;
                newNode->prev = AddedModes->prev;
                AddedModes->prev->next = newNode;
                AddedModes->prev = newNode;
                if (AddedModes == head) {
                    head = newNode;
                }
            }
        }
        size++;
    }
    
    void print_ascending() {
        Node<T> *newNode = head;
        while (newNode != NULL) {
            cout << newNode->data << " ";
            newNode = newNode->next;
        }
        cout << endl;
    }
    //reverse print list
    void print_descending() {
        Node<T> *newNode = tail;
        while (newNode != NULL) {
            cout << newNode->data << " ";
            newNode = newNode->prev;
        }
        cout << endl;
    }
    void deleteNode(T data) {
        Node<T> *newNode = head;
        while (newNode != NULL) {
            if (newNode->data == data) {
                if (newNode == head) {
                    head = newNode->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                } else if (newNode == tail) {
                    tail = newNode->prev;
                    if (tail != NULL) {
                        tail->next = NULL;
                    }
                } else {
                    newNode->prev->next = newNode->next;
                    newNode->next->prev = newNode->prev;
                }
                delete newNode;
                size--;
                return; // to exit the loop after deleting the node
            }
            newNode = newNode->next;
        }
    }

    int forwardIndex(T data) {
        Node<T> *newNode = head;
        int index = 0;
        while (newNode != NULL) {
            if (newNode->data == data) {
                index ++; // to fix the bug of forward index according to the school's example
                return index;
            }
            newNode = newNode->next;
            index++;
        }
        cout <<"I could't find the data inside of double linked list" << endl;
        return -1; // I think there should be a return value of -1 if the data is not found in the list
    }

    int backwardIndex(T data) {
        Node<T> *newNode = tail;
        int index = 0;
        while (newNode != NULL) {
            if (newNode->data == data) {
                index ++; // to fix the bug of backward index according to the school's example
                return index;
            }
            newNode = newNode->prev;
            index++;
        }
        cout <<"I could't find the data inside of double linked list" << endl;
        return -1; // I think there should be a return value of -1 if the data is not found in the list
    }
    void deleteList() {
        Node<T> *newNod = head;
        while (newNod != NULL) //while temp is not null when there are nodes in the list
        {
            Node<T> *Delater_Node = newNod;
            newNod = newNod->next;
            delete Delater_Node;
        }
        head =tail =NULL;
        size = 0;
    }
    int getSize() {
        return size;
    }
};
} /* namespace std */

#endif /* DoubleLinkedList_H_ */

