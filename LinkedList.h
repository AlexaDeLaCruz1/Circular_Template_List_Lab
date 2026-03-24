#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H

#include "Media.h"
#include <iostream>

//Templatize the Node
template <typename T>
struct Node {
    T* data;         
    Node<T>* next;

    Node(T* value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;        
    Node<T>* currentPlay; 
public:
    LinkedList() : head(nullptr), tail(nullptr), currentPlay(nullptr) {}

    ~LinkedList() {
        if (head == nullptr) return;

        tail->next = nullptr; 
        
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current->data; 
            delete current;       
            current = nextNode;
        }
        
        head = tail = currentPlay = nullptr;
        std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
    }

    void insert(T* newData) {
        Node<T>* newNode = new Node<T>(newData);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;    
            currentPlay = head;   
        } else {
            tail->next = newNode; 
            tail = newNode;       
            tail->next = head;    
        }
    }

    void displayList() const {
        if (head == nullptr) {
            std::cout << "\n[Playlist is empty.]" << std::endl;
            return;
        }

        std::cout << "\n--- Current Playlist (Circular) ---" << std::endl;
        Node<T>* temp = head;
        int index = 1;
        
        do {
            std::cout << index++ << ". " << temp->data->toString() << std::endl;
            temp = temp->next;
        } while (temp != head);
        
        std::cout << "-----------------------------------" << std::endl;
    }

    //Implement playNext() logic
    void playNext() {
        if (currentPlay != nullptr) {
            std::cout << "Now Playing: ";
            currentPlay->data->play();
            currentPlay = currentPlay->next; 
        } else {
            std::cout << "[Nothing to play.]" << std::endl;
        }
    }

    void playCurrent() const {
        if (currentPlay != nullptr) {
            currentPlay->data->play();
        } else {
            std::cout << "[Playlist is empty.]" << std::endl;
        }
    }
};

#endif
