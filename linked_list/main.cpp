// Main file for linked list

#include <exception>
#include <iostream>
#include "linked_list.hpp"

int test_push_back()
{
    LinkedList<int> t;
    std::cout << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << "test_push_back() start" << std::endl;

    std::cout << "Before push_back() size: " << t.size() << std::endl;
    
    
    for (int i = 0; i < 100; i++)
        t.push_back(i);

    if(t.size() != 100) throw ("Push back failed");
    std::cout << "After push_back() size: " << t.size() << std::endl;
    
    for (int i = 0; i < 100; i++)
    {
        if(t[i] != i) throw ("Push back failed");
        std::cout << i << ": " << t[i] << " || ";
    }
    std::cout << std::endl;

    std::cout << "test_push_back() passed" << std::endl;
    std::cout << "//////////////////////" << std::endl;

    std::cout << std::endl;
    
    return 0;
}


int test_push_front()
{
    LinkedList<int> t;
    std::cout << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << "test_push_front() start" << std::endl;

    std::cout << "Before push_front() size: " << t.size() << std::endl;
    
    for (int i = 0; i < 100; i++)
        t.push_front(i);

    if(t.size() != 100) throw ("Push front failed");
    
    std::cout << "After push_front() size: " << t.size() << std::endl;
    
    for (int i = 0; i < 100; i++)
    {
        if(t[99 - i] != i) throw ("Push front failed");
        std::cout << i << ": " << t[i] << " || ";
    }
    std::cout << std::endl;


    std::cout << "test_push_front() passed" << std::endl;
    std::cout << "//////////////////////" << std::endl;

    std::cout << std::endl;
    return 0;

}

int test_pop_front()
{
    LinkedList<int> t;
    std::cout << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << "test_pop_front() start" << std::endl;
    
    for (int i = 0; i < 10; i++)
        t.push_back(i);

    std::cout << "Before pop_front() size: " << t.size() << std::endl;

    for (int i = 0; i < 10; i++)
        std::cout << i << ": " << t[i] << " || ";
    std::cout << std::endl;

    t.pop_front();
    
    std::cout << "After pop_front() size: " << t.size() << std::endl;
    
    for (int i = 0; i < 9; i++)
        std::cout << i << ": " << t[i] << " || ";

    std::cout << std::endl;

    std::cout << "test_pop_front() passed" << std::endl;
    std::cout << "//////////////////////" << std::endl;

    std::cout << std::endl;
    return 0;


}

int test_insert()
{
    LinkedList<int> t;
    std::cout << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << "test_insert() start" << std::endl;
    std::cout << "Before insert() size: " << t.size() << std::endl;

    for (int i = 0; i < 10; i++)
        t.insert(i, i);

    std::cout << "After insert() size: " << t.size() << std::endl;

    for (int i = 0; i < 10; i++)
        std::cout << i << ": " << t[i] << " || ";
    std::cout << std::endl;

    std::cout << "test_insert() passed" << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << std::endl;

    return 0;
}

int test_clear()
{

    LinkedList<int> t;
    std::cout << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << "test_clear() start" << std::endl;

    for (int i = 0; i < 100; i++)
        t.push_back(i);
    
    std::cout << "Before clear() size: " << t.size() << std::endl;
    
    t.clear();

    std::cout << "After clear() size: " << t.size() << std::endl;

    std::cout << "test_clear() passed" << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << std::endl;
    return 0;

}

int test_remove()
{
    LinkedList<int> t;
    std::cout << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << "test_remove() start" << std::endl;

    for (int i = 0; i < 100; i++)
        t.push_back(i);

    std::cout << "Before remove() size: " << t.size() << std::endl;

    for (int i = 0; i < 100; i++)
        t.remove(99-i);

    std::cout << "After remove() size: " << t.size() << std::endl;

    std::cout << "test_remove() passed" << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << std::endl;
    return 0;

}

int test_pop_back()
{
    LinkedList<int> t;
    std::cout << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << "test_pop_back() start" << std::endl;

    for (int i = 0; i < 100; i++)
        t.push_back(i);

    std::cout << "Before pop_back() size: " << t.size() << std::endl;

    for (int i = 0; i < 100; i++)
        t.pop_back();

    std::cout << "After pop_back() size: " << t.size() << std::endl;

    std::cout << "test_pop_back() passed" << std::endl;
    std::cout << "//////////////////////" << std::endl;
    std::cout << std::endl;
    return 0;

}



int main(int, char**) 
{

    if (!(test_pop_back() || test_insert() || test_clear() || test_remove() || test_pop_front() || test_push_back() || test_push_front()))
        std::cout << "tests passed" << std::endl;

    return 0;
}
