#include <iostream>
#include "Queue.h"

void Queue::printAllValues() const
{
    Node *temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->getVal() << " ";
        temp = temp->getNext();
    }
    std::cout << std::endl;
}

void Queue::push_back(Node *node)
{
    if (getSize() == capacity)
    {
        capacity *= 2; // double the queue capacity
    }
    if (tail != nullptr)
    {
        tail->setNext(node);
    }
    tail = node;
    if (head == nullptr)
    {
        head = node;
    }
    size++;
}

int Queue::getSize() const
{
    return size;
}

int Queue::getCapacity() const
{
    return capacity;
}

Node *Queue::pop()
{

    if (head == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    head = head->getNext();
    if (head == nullptr)
    {
        tail = nullptr;
    }
    int value = temp->getVal();
    delete temp;
    size--;
    return new Node(value);
}

void Queue::clear()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->getNext();
        delete temp;
    }
    tail = nullptr;
}

// int main()
// {
//     Node *a = new Node(5);
//     Node *b = new Node(6);
//     Node *c = new Node(7);
//     Queue *q = new Queue(10);
//     std::cout << "the capacity of queue is: " << q->getCapacity() << "\n"
//               << "size is: " << q->getSize() << std::endl;

//     std::cout << "// insert a node " << std::endl;
//     q->push_back(a);
//     std::cout << "the capacity of queue is: " << q->getCapacity() << "\n"
//               << "size is: " << q->getSize() << std::endl;

//     std::cout << "// insert another  node " << std::endl;
//     q->push_back(b);
//     std::cout << "the capacity of queue is: " << q->getCapacity() << "\n"
//               << "size is: " << q->getSize() << std::endl;

//     std::cout << "// insert and then popup a node " << std::endl;
//     q->push_back(c);
//     q->printAllValues();
//     Node *temp = q->pop();
//     std::cout << "the value of the poped up node is: " << temp->getVal() << std::endl;
//     q->printAllValues();
//     delete a;
//     delete b;
//     delete c;
//     delete q;
//     return 0;
// }