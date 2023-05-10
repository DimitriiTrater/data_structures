#ifndef DLINKED_LIST_HPP
#define DLINKED_LIST_HPP


#include <type_traits>


template<class T>
class DLinkedList
{


struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(T data=T(), Node* next=nullptr, Node* prev=nullptr) : data(data), next(next), prev(prev) {}
};

int _size;
Node* head;
Node* tail;

public:
    DLinkedList();
    ~DLinkedList();

    int size() const noexcept;
};

#endif // DLINKED_LIST_HPP


template<class T>
DLinkedList<T>::DLinkedList() : _size(0), head(nullptr), tail(nullptr) {}



template<class T>
int DLinkedList<T>::size() const noexcept {return this->_size;}

