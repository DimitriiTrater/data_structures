#include "dlinked_list.hpp"
#include <iostream>


int main()
{
    DLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);

    l.insert(1, 1000);
    std::cout << l[1] << std::endl;

    return 0;
}