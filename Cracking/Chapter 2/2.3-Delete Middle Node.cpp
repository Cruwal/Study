/*
2.3: Delete Middle Node: Implement an algorithm to delete a node in the middle 
(i.e., any node but the first and last node, not necessarily the exact middle) of a singly
linked list, given only acces to that node. 
*/

#include <iostream>
#include <iterator>
#include <cstdlib>
#include <list>

void show_list(std::list<int> list)
{
    std::list<int>::iterator it;
    for(it = list.begin(); it != list.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// Time: O(1), memory: O(1).
void delete_middle_node(std::list<int>& list, std::list<int>::iterator value)
{
    std::list<int>::iterator it;
    it = list.begin();

    std::cout << "Removing: " << *value << std::endl;
    
    list.erase(value);
}

std::list<int>::iterator select_node(std::list<int>& list)
{
    std::list<int>::iterator it;
    it = list.begin();

    for(int i = 0; i < 1; i++)
        it++;

    if(it == list.begin()) it++;
    else if(it == list.end()) it--;

    return it;
}

int main(int argc, char const *argv[])
{
    int list_size = 10;
    std::list<int> buffer;
    std::list<int>::iterator node;

    srand(time(NULL));

    for(int i = 0; i < list_size; i++)
        buffer.push_back(rand() % list_size/2 + i);

    show_list(buffer);

    node = select_node(buffer);
    delete_middle_node(buffer, node);

    show_list(buffer);

    return 0;
}
