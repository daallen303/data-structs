#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

class Stack{

    std::vector <int> st;
    const int MAX_ELEMENTS = 100;

    public:
    Stack(int size)
    {
        st.reserve(100);
    }

    bool isEmpty()
    {
        return st.size() == 0;
    }

    bool isFull()
    {
        return st.size() == MAX_ELEMENTS;
    }

    void push(int n)
    {
        if(isFull())
        {
            std::cout << "The stack is full, cannot add " << n << " \n";
            return;
        }
        st.push_back(n);
    }

    int pop()
    {
        if(isEmpty())
        {
            std::cout << "stack is empty, cannot pop off the stack \n";
            return -1;
        }
        int data = st[st.size()-1];
        std::cout << "removing " << data << " from the stack \n";
        st.pop_back();
    }

    void print()
    {
        for(auto& ax : st)
        {
            std::cout << ax << " ";
        }
        std::cout << " \n";
    }
};


int main(int argc, char **argv)
{
    int size = std::strtol(argv[1], NULL, 10);
    Stack stack(size);

    for(int i = 0; i < size+1; i++) 
    {
        stack.push(i);
    }

    stack.print();

    for(int i = 0; i < size; i++)
    {
        stack.pop();
    }

    stack.print();

    for(int i = 0; i < 3; i++)
    {
        stack.pop();
    }



}