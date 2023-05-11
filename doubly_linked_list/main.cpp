#include "dlinked_list.hpp"
#include <iostream>


int main()
{
    DLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);


    // l.insert(1, 1000);
    l.remove(1);
    std::cout << l[1] << std::endl;

    return 0;
}