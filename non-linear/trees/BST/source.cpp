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

    std::cout << std::endl << "inorder" << std::endl;
    bst.inorder(bst.root);
    std::cout << std::endl << "preorder" << std::endl;
    bst.preorder(bst.root);
    std::cout << std::endl << "postorder" << std::endl;
    bst.postorder(bst.root);

    bst.deleteEm(bst.root, 35);

    
    std::cout << std::endl << "inorder" << std::endl;
    bst.inorder(bst.root);
    std::cout << std::endl << "preorder" << std::endl;
    bst.preorder(bst.root);
    std::cout << std::endl << "postorder" << std::endl;
    bst.postorder(bst.root);
    std::cout << std::endl;

}