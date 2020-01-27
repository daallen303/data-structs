#include "./hashTable.cpp"
#include <stdlib.h>

int main(int argc, char **argv)
{
    int bucket_size = strtol(argv[1], NULL, 10);
    HashTable hashTable(bucket_size);
    for(int i = 0; i < bucket_size; i++) hashTable.insert(i);
    hashTable.print();

    for(int i = 0; i < bucket_size; i+=2)
    {
        hashTable.deleteEm(i);
    }

    hashTable.print();

}