#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* previous;
};

class doubleList {
    private:

    struct Node *head;
    struct Node *tail;

    public:
    
    doubleList()
    {
        head = NULL;
        tail = NULL;
    }

    int insertEm(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        if( head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->previous = new_node;
            new_node->previous = NULL;
            head = new_node; 
        }
    }
    int deleteEm(int data)
    {
        Node *current = new Node;
        Node *previous= new Node;
        Node *next = new Node;
        current = head;
        previous = NULL;
        while( current != NULL && current->data != data)
        {
            current = current->next;
        }
        if( current != NULL)
        {
            previous = current->previous;
            next = current->next;
            if(current == head )
            {
                next->previous = NULL;
                head = next;
            }
            else if(current == tail) 
            {
                previous->next == NULL;
                tail = previous;   
            }
            else
            {
                previous->next = next;
                next->previous = previous;
            }
            delete(current);
        }
        else 
        {
            std::cout << "Could not delete " << data << " because it was not found in the list" << std::endl;
        }

    }
    int printemForward()
    {
        Node *current;
        current = head;
        while(current != NULL)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void printemBackward()
    {
        Node *current;
        current = tail;
        while(current != NULL)
        {
            std::cout << current->data << " ";
            current = current->previous;
        }
        std::cout << std::endl;
    }
};

int main()
{
    doubleList DL;
    for(int i = 0; i < 10; i++)
    {
        DL.insertEm(i);
    }
    DL.printemForward();
    DL.printemBackward();
    DL.deleteEm(1);
    DL.deleteEm(4);
    DL.deleteEm(9);
    DL.deleteEm(232);

    DL.printemForward();
    DL.printemBackward();
}