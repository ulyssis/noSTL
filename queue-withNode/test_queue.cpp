#include <iostream>
#include "Queue.h"

void testPushBackAndGetSize()
{
    Queue queue(10);
    Node *a = new Node(5);
    Node *b = new Node(6);
    queue.push_back(a);
    queue.push_back(b);
    if (queue.getSize() == 2)
    {
        std::cout << "testPushBackAndGetSize passed." << std::endl;
    }
    else
    {
        std::cout << "testPushBackAndGetSize failed." << std::endl;
    }
    delete a;
    delete b;
}

void testPop()
{
    Queue queue(10);
    Node *a = new Node(5);
    Node *b = new Node(6);
    queue.push_back(a);
    queue.push_back(b);
    Node *popped = queue.pop();
    if (popped->getVal() == 5 && queue.getSize() == 1)
    {
        std::cout << "testPop passed." << std::endl;
    }
    else
    {
        std::cout << "testPop failed." << std::endl;
    }
    delete popped;
    delete a;
    delete b;
}

void testClear()
{
    Queue queue(10);
    Node *a = new Node(5);
    Node *b = new Node(6);
    queue.push_back(a);
    queue.push_back(b);
    queue.clear();
    if (queue.getSize() == 0 && queue.pop() == nullptr)
    {
        std::cout << "testClear passed." << std::endl;
    }
    else
    {
        std::cout << "testClear failed." << std::endl;
    }
    delete a;
    delete b;
}

void testGetCapacity()
{
    Queue queue(10);
    if (queue.getCapacity() == 10)
    {
        std::cout << "testGetCapacity passed." << std::endl;
    }
    else
    {
        std::cout << "testGetCapacity failed." << std::endl;
    }
    for (int i = 0; i < 10; ++i)
    {
        queue.push_back(new Node(i));
    }
    if (queue.getCapacity() == 20)
    { // Capacity should double
        std::cout << "testGetCapacity passed." << std::endl;
    }
    else
    {
        std::cout << "testGetCapacity failed." << std::endl;
    }
}

void testPrintAllValues()
{
    Queue queue(10);
    Node *a = new Node(5);
    Node *b = new Node(6);
    queue.push_back(a);
    queue.push_back(b);
    std::cout << "Expected output: 5 6" << std::endl;
    std::cout << "Actual output: ";
    queue.printAllValues();
    delete a;
    delete b;
}

int main()
{
    testPushBackAndGetSize();
    testPop();
    testClear();
    testGetCapacity();
    testPrintAllValues();
    return 0;
}