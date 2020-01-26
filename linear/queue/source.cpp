#include <iostream>

class Queue {
    int *Arr; // array to store the queue values
    int capacity; // maximum capacity of the queue
    int front;
    int rear;
    int count;

    public:

    Queue(int size)
    {
        Arr = (int*) malloc(sizeof(int)*size);
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    bool isEmpty()
    {
        return count == 0;
    }
    bool isFull()
    {
        return count == capacity;
    }
    void enqueue(int n){
        if(isFull())
        {
            std::cout << "can not engueue queue is full" << std::endl;
            return;
        }
        std::cout << "adding " << n << " to the queue" << std::endl;
        rear = (rear+1)%capacity; // for a circular queue you would use (rear +1)%capacity
        Arr[rear] = n;
        count++;
    }
    int dequeue(){
        if(isEmpty())
        {
            std::cout << "can not dequeue queue is empty" << std::endl;
            return -1;
        }

        int data = Arr[front];
        std::cout << "removing " << data << " from the queue" << std::endl;
        Arr[front] = -1;
        front++;
        count--;
        return data;
    }

    void print()
    {
        int current = front;
        while(current != rear+1)
        {
            std::cout << Arr[current] << " ";
            current++;
        }

        std::cout << std::endl;
    }
};


int main()
{
    Queue q(10);

    for(int i = 0; i < 11; i++) q.enqueue(i);
    q.print();
    for(int i = 0; i < 11; i++)
    {
        int data = q.dequeue();
    } 
    std::cout << std::endl;
}