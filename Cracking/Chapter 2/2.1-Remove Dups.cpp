/*
2.1 Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

#include <list>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <unordered_map>

void show_list(std::list<int> source_list)
{

    std::list<int>::iterator it;
    for (it = source_list.begin(); it != source_list.end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl;
}

// Time: BigO(n), Memory: BigO(n) 
void remove_dup(std::list<int> source_list){
    std::unordered_map<int, int> umap;

    std::list<int>::iterator it;
    for(it = source_list.begin(); it != source_list.end(); ){
        umap[*it]++;

        if(umap[*it] > 1)
            source_list.erase(it++);
        else
            it++;
    }

    show_list(source_list);
}

// Time: BigO(n ^ 2), Memory: BigO(1)
void follow_up_remove_dup(std::list<int> source_list)
{
    std::unordered_map<int, int> umap;

    std::list<int>::iterator it;
    for (it = source_list.begin(); it != source_list.end(); it++){
        std::list<int>::iterator it2;
        for(it2 = it, it2++; it2 != source_list.end(); ){
            if(*it2 == *it)
                source_list.erase(it2++);
            else
                it2++;
        }
    }

    show_list(source_list);
}

int main(int argc, char const *argv[])
{
    std::list<int> buffer;
    srand(time(NULL));

    for(int i = 0; i < 30; i++)
        buffer.push_back(rand() % 15 + i);

    show_list(buffer);

    remove_dup(buffer);
    follow_up_remove_dup(buffer);

    return 0;
}
