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

Node* BST::insert(Node *root, int key)
{
    if(root == NULL)
    {
        root = new Node;
        root->key = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(root->key > key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);

}

Node* BST::findMin(Node *root)
{
    if(root->left == NULL) return root;
    else findMin(root);
}

Node* BST::deleteEm(Node *root, int key)
{
    if(root == NULL) return NULL;
    else if(root->key > key) root->left = deleteEm(root->left, key);
    else if(root->key < key) root->right = deleteEm(root->right, key);

    // else key == root->key

    // parent with right child or no child
    else if(root->left == NULL)
    {
        Node *temp = root->right; 
        free(root);
        return temp;
    }
    // parent with left child
    else if(root->right == NULL)
    {
        Node *temp = root->left; 
        free(root); 
        return temp;
    }
    // parent with two children
    else
    {
        Node *temp = findMin(root->right);
        root->key = temp->key;
        deleteEm(root->right, temp->key);
    }
    return root;
}

void BST::inorder(Node *current)
{
    if(current->left != NULL) inorder(current->left);
    std::cout << current->key << " ";
    if(current->right != NULL) inorder(current->right);
}

void BST::preorder(Node *current)
{
    std::cout << current->key << " ";
    if(current->left != NULL) preorder(current->left);
    if(current->right != NULL) preorder(current->right);
}

void BST::postorder(Node *current)
{
    if(current->left != NULL) postorder(current->left);
    if(current->right != NULL) postorder(current->right);
    std::cout << current->key << " ";

}