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

public:
    DLinkedList();
    ~DLinkedList();
};

#endif // DLINKED_LIST_HPP