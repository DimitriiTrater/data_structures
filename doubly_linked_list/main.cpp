#include "dlinked_list.hpp"
#include <iostream>


int main()
{
    DLinkedList<int> l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);

    std::cout << l[0] << std::endl;

    return 0;
}