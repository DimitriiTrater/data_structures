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
    void push_front(T data);

    void pop_back();
    void pop_front();
    
    void insert(int index, T data);
    void remove(int index);

    void clear();


    int size() const noexcept;
    T& operator[](const int index); // its trow out of range exception
};




template<class T>
LinkedList<T>::LinkedList() : _size(0), head(nullptr)
{}


template<class T>
LinkedList<T>::~LinkedList() { clear(); }


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
void LinkedList<T>::push_front(T data)
{
    head = new Node(data, head);
    _size++;
}

template<class T>
void LinkedList<T>::pop_back()
{
    if (!head) throw std::out_of_range("List is empty");
    remove(_size - 1);
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
void LinkedList<T>::insert(int index, T data)
{
    if (!index)
    { 
        push_front(data);
        return;
    }

    Node* prev = this->head;

    for (int i = 0; i < index - 1; i++) 
        prev = prev->next;
    
    Node* new_node = new Node(data, prev->next);
    prev->next = new_node;

    _size++;
}

template <class T>
void LinkedList<T>::remove(int index)
{
    if(!index)
    {
        pop_front();
        return;
    }

    Node* prev = this->head;

    for (int i = 0; i < index - 1; i++)
        prev = prev->next;
    
    Node* temp = prev->next;

    prev->next = temp->next;

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

