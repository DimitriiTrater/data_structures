#include <exception>
#include <stdexcept>

#ifndef STACK_HPP
#define STACK_HPP

template<class T>
class Stack
{
    struct Node
    {
        T value;
        Node* next;
        Node(T value=T(), Node* next=nullptr) : value(value), next(next)
        {}
    };

    const unsigned int STACK_CAPACITY = 10000;

    unsigned int _size;
    unsigned int _capacity;
    Node* top;
public:
    Stack();
    ~Stack();

    void push(T value);
    void pop();
    T peek();


    unsigned int size() const {return _size;}
    unsigned int capacity() const {return _capacity;}
};

#endif // STACK_HPP

template<class T>
Stack<T>::Stack() : top(), _size(0), _capacity(STACK_CAPACITY)
{}

template<class T>
Stack<T>::~Stack()
{
    while (top) pop();
}


template<class T>
void Stack<T>::push(T value)
{
    _size++;
    if (top)
    {
        Node* temp = new Node(value, top);
        top = temp;
        return;
    }
    top = new Node(value);

}

template<class T>
void Stack<T>::pop()
{
    if (!top) throw std::out_of_range("Error: Out of range");

    Node* temp = top;
    top = top->next;
    delete temp;
    _size--;
}

template<class T>
T Stack<T>::peek()
{
    if (!top) throw std::out_of_range("Error: Out of range");
    return top->value;
}