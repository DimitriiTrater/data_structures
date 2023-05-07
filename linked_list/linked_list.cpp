#include "linked_list.h"

template<class T>
LinkdeList<T>::LinkdeList() : _size(0), head(nullptr)
{}

template<class T>
LinkdeList<T>::~LinkdeList()
{}

template<class T>
void LinkdeList<T>::push_back(T data)
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

template<class T>
int LinkdeList<T>::size() const noexcept
{return this->size;} 