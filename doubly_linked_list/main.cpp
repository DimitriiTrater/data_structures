#include "dlinked_list.hpp"


int main()
{
    DLinkedList<int> l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);

    l.pop_front();
    l.pop_front();

    return 0;
}