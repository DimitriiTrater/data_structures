// Main file for linked list

#include <iostream>
#include "linked_list.hpp"


int main(int, char**) 
{
    LinkedList<int> t;
    std::cout << t.size() << std::endl;
    t.push_back(20);
    t.push_back(20);
    std::cout << t.size() << std::endl;
    std::cout << t[0] << std::endl;
    std::cout << t[1] << std::endl;
    t.pop_front();
    std::cout << t.size() << std::endl;
    std::cout << t[0] << std::endl;

    return 0;
}
