#ifndef DLINKED_LIST_HPP
#define DLINKED_LIST_HPP


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
    void pop_front();
    
    int size() const noexcept;
};

#endif // DLINKED_LIST_HPP


template<class T>
DLinkedList<T>::DLinkedList() : _size(0), head(nullptr), tail(nullptr) {}

template<class T>
DLinkedList<T>::~DLinkedList(){}


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
void DLinkedList<T>::pop_front()
{
    Node* temp = head;

    head = head->next;

    delete temp;

    _size--;
}



template<class T>
int DLinkedList<T>::size() const noexcept {return this->_size;}

