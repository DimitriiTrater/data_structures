#pragma once
#include <stdexcept>

// Linked List implementation


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
    void pop_front();
    void clear();

    int size() const noexcept;
    T& operator[](const int index); // its trow out of range exception
};




template<class T>
LinkedList<T>::LinkedList() : _size(0), head(nullptr)
{}


template<class T>
LinkedList<T>::~LinkedList()
{


}


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


template<class T>
void LinkedList<T>::pop_front()
{
    Node* temp = head;

    head = head->next;

    delete temp;

    _size--;
}


template<class T>
void LinkedList<T>::clear() { while (_size) pop_front(); }


template<class T>
int LinkedList<T>::size() const noexcept {return this->_size;}


template<class T>
T& LinkedList<T>::operator[](const int index)
{
    int counter = 0;
    Node* current = this->head;
    while (current)
    {
        if (counter == index) return current->data;
        current = current->next;
        counter++;
    }
    throw std::out_of_range("Index out of range");
}

