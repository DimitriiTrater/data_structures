#include "dlinked_list.hpp"


int main()
{
    DLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);

    l.pop_front();
    l.pop_front();

    return 0;
}