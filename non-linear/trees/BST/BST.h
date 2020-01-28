

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
    void insert(int key);
    void deleteEm(int key);
    void deleteLeaf(Node *child, Node *parent);
    void deleteParentWithOneChild(Node *node, Node *parent);
    void deleteParentWithTwoChildren(Node *node);
    void inorder(Node *node);
    void preorder();
    void postorder();

};