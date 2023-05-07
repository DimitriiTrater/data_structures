#pragma once

template<class T>
class LinkdeList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(T data=T(), Node* next=nullptr) : data(data), next(next) {}
    };

    int size;
    Node *head;

public:
    LinkdeList();
    ~LinkdeList();

    void push_back(T data);
};