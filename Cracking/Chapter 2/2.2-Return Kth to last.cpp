// 2.2-Return Kth to last: Implement an algorithm to find the kth to 
// last element of a singly linked list

#include <list>
#include <iterator>
#include <iostream>
#include <cstdlib>

void show_list(std::list<int> list)
{
    std::list<int>::iterator it;
    for(it = list.begin(); it != list.end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl;
}

// Time: O(n), Memory: O(1)
int k_to_last_number(std::list<int> list, int position)
{
    std::list<int>::iterator initial;
    std::list<int>::iterator last;
    int i = 0;

    initial = list.begin();
    for(last = list.begin(); i < position; i++){
        if(last == list.end())
            return -1;
        
        last++;
    }

    for(last; last != list.end(); last++)
        initial++;

    return *initial;
}

int main(int argc, char const *argv[])
{
    int result;
    int list_size = 30;
    int position = 5;
    std::list<int> buffer;
    srand(time(NULL));

    for (int i = 0; i < list_size; i++)
        buffer.push_back(rand() % 15 + i);

    show_list(buffer);
    result = k_to_last_number(buffer, position);

    std::cout << "Result: " << result << std::endl;
    
    return 0;
}
