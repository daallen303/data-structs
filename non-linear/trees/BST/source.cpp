#include "BST.cpp"
#include <fstream>

int main()
{
    BST bst(20);
    int key;

    std::ifstream fin;
    fin.open("./input.txt");
    bool done = false;

    fin >> key;
    while(!done)
    {
        bst.insert(key);
        if(fin.eof()) break;
        fin >> key;
    }

    bst.inorder(bst.root);

    bst.deleteEm(16);
    bst.deleteEm(0);
    bst.deleteEm(20);
    
    bst.inorder(bst.root);

}