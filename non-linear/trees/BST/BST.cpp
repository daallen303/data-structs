#include "./BST.h"
#include <iostream>

BST::BST(int key)
{
    root = new Node;
    root->key = key;
    root->right = NULL;
    root->left = NULL;
}

BST::~BST()
{
}

bool BST::isEmpty()
{
    return root == NULL;
}

void BST::insert(int key)
{
    Node *new_node = new Node;
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    
    if(BST::isEmpty())
    {
        root = new_node;
        return;
    }

    Node *current = root;
    Node *parent;
    while(current!= NULL)
    {
        parent = current;
        if(current->key < new_node->key)current = current->right;
        else if(current->key > new_node->key) current = current->left;
        else 
        {
            std::cout << "error, key is already in the tree" << std::endl;
            return;
        }
    }

        if(parent->key < new_node->key)parent->right = new_node;
        else if(parent->key > new_node->key) parent->left = new_node;

}

void BST::deleteLeaf(Node *child, Node *parent)
{
    if(parent-> left == child) parent->left == NULL;
    else parent->right == NULL;
    delete child;
}
// node is node to delete, parent is node to deletes parent
void BST::deleteParentWithOneChild(Node *node, Node *parent)
{
    // parent key is greater, nodes subtree would be to left of parent
    if(parent->key > node->key)
    {
        if(node->left != NULL) parent->left = node->left;
        else parent->left = node->right;
    }
    else
    {
        if(node->left != NULL) parent->right = node->right;
        else parent->right = node->left;
    }
    delete node;
}
void BST::deleteParentWithTwoChildren(Node *node)
{
    Node *current, *parent;
    current = node->right;
    while( current->left != NULL )
    {
        parent = current;
        current = current->left;
    }
    node->key = current->key;
    
    if(current->right != NULL) deleteParentWithOneChild(current, parent);
    else deleteLeaf(current,parent);
}

void BST::deleteEm(int key)
{
    Node *current = root;
    Node *parent;
    while(current->left != NULL && current->right != NULL && current->key != key)
    {
        parent = current;
        if(current->key < key) current = current->right;
        else current = current->left; 
    }

    if(current->key != key )
    {
        std::cout << "key not found" << std::endl;
        return;
    }

    if(current->left == NULL && current->right == NULL)
    {
        deleteLeaf(current, parent);
    }
    else if(current->left != NULL && current->right != NULL) deleteParentWithTwoChildren(current);
    else deleteParentWithOneChild(current, parent);

}

void BST::inorder(Node *current)
{
    if(current->left != NULL) inorder(current->left);
    std::cout << current->key << " ";
    if(current->right != NULL) inorder(current->right);
}