#include "linked_list.h"

template<class T>
LinkedList<T>::LinkedList() : _size(0), head(nullptr)
{}

template<class T>
LinkedList<T>::~LinkedList()
{}

template<class T>
void LinkedList<T>::push_back(T data)
{

    if (!head)
        head = new Node(data);
    else 
    {
        Node* current = this->head;
        while(current->next)
            current = current->next;
        current->next = new Node(data);
    }
    _size++;
}