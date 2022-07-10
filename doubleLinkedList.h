#ifndef DoubleLinkedlist_H_
#define DoubleLinkedlist_H_

#include <iostream>
#include <cassert>

namespace std {
template <typename T>
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

    int Remove(T data);

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
    void Clear() {
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

    ~DoubleLinkedList() {
        Clear();
    }
    protected:
    void removeAccordingToNode(Node<T> *node);

};  
    template <class T>
    int DoubleLinkedList<T>::Remove(T data) {     // Returns 0 upon successful deletion, if there is not any node with the given data, returns -1 and use the remove function to delete the node
        Node<T> *newNode = head;
        while (newNode != NULL) {
            if (newNode->data == data) {
                removeAccordingToNode(newNode);
                return 0;
            }
            newNode = newNode->next;
        }
        return -1;
    }
    template <class T>
    void DoubleLinkedList<T>::removeAccordingToNode(Node<T> *node) {
        if (node == head) { // if the node is the head, then we need to change the head to the next node
            head = node->next;
        } else if (node == tail) { // if the node is the tail, we need to change the tail to the previous node
            tail = node->prev;
        } else { // if the node is in the middle of the list
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
        size--;
    }

} /* namespace std */

#endif /* DoubleLinkedList_H_ */

