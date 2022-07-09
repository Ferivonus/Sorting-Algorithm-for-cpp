#ifndef DoubleLinkedlist_H_
#define DoubleLinkedlist_H_

#include <iostream>
#include <cassert>

namespace std {

struct Node {
    int data;
    Node *next;
    Node *prev;
};
//double linked list
class DoubleLinkedList {
    Node *head;
    Node *tail;
    int size;
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    //sorted list shorted by data
    void add(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            Node *AddedModes = head;
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
    
    void print() {
        Node *newNode = head;
        while (newNode != NULL) {
            cout << newNode->data << " ";
            newNode = newNode->next;
        }
        cout << endl;
    }
    //reverse print list
    void reversePrint() {
        Node *newNode = tail;
        while (newNode != NULL) {
            cout << newNode->data << " ";
            newNode = newNode->prev;
        }
        cout << endl;
    }
    void deleteNode(int data) {
        Node *newNode = head;
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
    void deleteList() {
        Node *newNod = head;
        while (newNod != NULL) //while temp is not null when there are nodes in the list
        {
            Node *Delater_Node = newNod;
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








