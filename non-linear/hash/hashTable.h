#include <iostream>
#include <list>

class HashTable{

    int buckets;
    std::list<int> *table;
    public: 
    HashTable(int n);
    void insert(int n);
    void deleteEm(int n);
    int hash(int n);
    void print();
};