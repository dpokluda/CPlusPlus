#include <iostream>

#include "Trie.h"

int main()
{
    Trie trie;
    trie.Insert("apple");
    trie.Insert("app");

    std::cout << "apple: " << (trie.Search("apple") ? " true" : "false") << std::endl; 
    std::cout << "app: " << (trie.Search("app") ? " true" : "false") << std::endl;
    std::cout << "appl: " << (trie.Search("appl") ? " true" : "false") << std::endl;

    return 0;
}
