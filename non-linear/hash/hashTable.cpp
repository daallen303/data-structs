#include "hashTable.h"

HashTable::HashTable(int n)
{
    this->buckets = n;
    table = new std::list<int>[buckets];
}
void HashTable::insert(int n)
{
    int index = hash(n);
    table[index].push_back(n);
}
void HashTable::deleteEm(int n)
{
    int index = hash(n);
    std::list<int>::iterator it;
    for(it = table[index].begin(); it != table[index].end(); it++)
    {
        if(*it == n)
        {
            break;
        }
    }

    if(it != table[index].end())
    {
        table[index].erase(it);
    }
}
int HashTable::hash(int n)
{
    return n % buckets;
}
void HashTable::print()
{
    for(int i = 0; i < buckets; i++)
    {
        for(auto &key : table[i])
        {
            std::cout << key << " ";
        }
    }
    std::cout << std::endl;
}

