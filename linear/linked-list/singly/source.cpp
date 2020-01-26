#include <iostream>

struct Node{
    int data;
    struct Node *next;

}; 

void insert(int data, struct Node **head)
{
    struct Node *new_node = new Node;
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}
void deleteEm(int data, struct Node **head)
{
    struct Node *current = new Node;
    struct Node *previous = new Node;
    current = *head;
    while(current != NULL && current->data != data)
    {
        previous = current;
        current = current->next;
    }
    if(current != NULL)
    {
        previous->next = current->next;
        delete(current);
    }
    else
    {
        std::cout << "there was nothing matching " << data << " in the list" << std::endl;
    }
    
}
void printem(struct Node **head)
{
    struct Node *current;
    current = *head;
    while(current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "All done" << std::endl;
}

int main()
{
    struct Node *head = NULL;
    std::cout << "inserting into list" << std::endl;
    
    for (int i = 0; i < 10; i++)insert(i, &head);
    printem(&head);

    deleteEm(3,&head);
    deleteEm(6,&head);
    deleteEm(29,&head);

    printem(&head);

}