#ifndef DLINKED_LIST_HPP
#define DLINKED_LIST_HPP


#include <stdexcept>
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

    void push_front(T data);
    void push_back(T data);
    void pop_back();
    void pop_front();
    
    void insert(int index, T data);
    void remove(int index);


    void clear();

    int size() const noexcept;
    T& operator[](const int index); // its throw out of range exception

};

#endif // DLINKED_LIST_HPP


template<class T>
DLinkedList<T>::DLinkedList() : _size(0), head(nullptr), tail(nullptr) {}

template<class T>
DLinkedList<T>::~DLinkedList(){ clear();}


template<class T>
void DLinkedList<T>::push_front(T data)
{   
    if(!head) 
    {
        head = new Node(data, nullptr, nullptr);
        tail = head;
    }
    else 
    {
        head = new Node(data, head);

        if(!head->next->prev)
            head->next->prev = head;
        
    }
    _size++;
}



template<class T>
void DLinkedList<T>::push_back(T data)
{

    if (!head)
    {
        head = new Node(data);
        tail = head;
    }
    else 
    {
        Node* current = this->head;
        while(current->next)
            current = current->next;
        current->next = new Node(data);
        current->next->prev = this->tail;
        tail = current->next;
    }
    _size++;
}

template<class T>
void DLinkedList<T>::pop_back()
{
    Node* temp = tail;

    tail = tail->prev;
    tail->next = nullptr;

    delete temp;

    _size--;
}


template<class T>
void DLinkedList<T>::pop_front()
{
    
    Node* temp = head;

    if (head != tail)
    {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;

    _size--;
}

template<class T>
void DLinkedList<T>::insert(int index, T data)
{
    if (!index)
    { 
        push_front(data);
        return;
    }

    Node* prev = this->head;

    for (int i = 0; i < index; i++) 
        prev = prev->next;
    
    Node* new_node = new Node(data, prev, prev->prev);
    prev->prev->next = new_node;
    prev->prev = new_node;

    _size++;
}


template <class T>
void DLinkedList<T>::remove(int index)
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
    temp->next->prev = prev;

    delete temp;

    _size--;
}





template<class T>
void DLinkedList<T>::clear() { while (_size) pop_front(); }


template<class T>
int DLinkedList<T>::size() const noexcept {return this->_size;}



template<class T>
T& DLinkedList<T>::operator[](const int index)
{
    int counter = 0;
    Node* current = this->head;
    while (current)
    {
        if (counter == index) return current->data;
        current = current->next;
        counter++;
    }
    throw std::out_of_range("index out of range");
}

