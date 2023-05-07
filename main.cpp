#include <iostream>
#include "linked_list/linked_list.h"


class linked_list_test
{
    LinkdeList<int> list;

    int push_back_test()
    {
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        list.push_back(4);
        list.push_back(5);
        list.push_back(6);
        list.push_back(7);
        list.push_back(8);
        list.push_back(9);
        list.push_back(10);
        list.push_back(11);
        list.push_back(12);
        list.push_back(13);
        list.push_back(14);
        list.push_back(15);
        list.push_back(16);
        list.push_back(17);
        list.push_back(18);
        list.push_back(19);
        return 0;
    }

};


int main(int, char**) {
    std::cout << "Hello, world!\n";
    
}
