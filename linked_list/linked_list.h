#pragma once

template<class T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(T data=T(), Node* next=nullptr) : data(data), next(next) {}
    };

    int _size;
    Node *head;

public:
    LinkedList();
    ~LinkedList();

    void push_back(T data);
    int size() const noexcept {return this->_size;}
    T& operator[](const int index);
};