

struct Node{
    int key;
    Node *left, *right;
};

class BST{
    public:

    Node *root;


    BST(int key);
    ~BST();
    bool isEmpty();
    Node* insert(Node *root, int key);
    Node* findMin(Node *root);
    Node* deleteEm(Node *root, int key);
    void inorder(Node *node);
    void preorder(Node *node);
    void postorder(Node *node);

};