#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node  {
    char val;
    unordered_map<char, Node*> children;
    int wordend;

    Node(char c)
    {
        val = c;
        wordend = 0;
        children;
    }
};

class Trie {
    Node* root;
   
    public:
    Trie(Node *root)
    {
        this->root = root;
    }

    Node* insert(Node * root, string word, int index)
    {
        char cur = word[index];
        if(root->children.find(cur) == root->children.end())
        {
            Node* new_node = new Node(cur);
            root->children[cur] = new_node;
        }

        if(index == word.length()-1)
        {
            root->children[cur]->wordend = 1;
            return root;
        }

        root->children[cur] = insert(root->children[cur], word, index+1);
        return root;
    }

    bool isWord(Node* root, string word, int index)
    {
            if(index == word.length())
            {
                return (root->wordend > 0) ? true : false;
            }
            char cur = word[index];
            if(root->children.find(cur) == root->children.end())
                return false;
            else 
                return isWord(root->children[cur], word, ++index);
    }
};

int main()
{
    ifstream fin("./dictionary.txt");
    

    if(fin.is_open())
    {
        string temp;

        Node* root = new Node(' ');
        Trie trie(root);

        while(!fin.eof())
        {
            fin >> temp;
            root = trie.insert(root, temp, 0);
        }

        string new_word;
        while(new_word != "exit")
        {
            cout << "Enter a new word or 'exit' to quit" << endl << endl;
            cin >> new_word;
            bool word = trie.isWord(root,new_word,0);
            cout << new_word << (word ? " is a word " : " is not a word");
            cout << endl << endl;
        }
        
    }
    else
    {
        throw("input stream invalid");
    }
    
}