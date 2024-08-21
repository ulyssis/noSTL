// Node has integer value
class Node
{
    int val;
    Node *next;

public:
    Node(int value) : val(value), next(nullptr) {}
    void copyNode(Node *node)
    {
        val = node->val;
        next = node->next;
    }
    Node *getNext() const
    {
        return next;
    }
    void setNext(Node *node)
    {
        next = node;
    }
    void setVal(int value)
    {
        val = value;
    }
    int getVal()
    {
        return val;
    }
};

// This queue consists of node with integer values
class Queue
{
    int capacity;
    Node *head;
    Node *tail;
    int size;

public:
    Queue(int capacity) : capacity(capacity), head(nullptr), tail(nullptr), size(0) {}
    void push_back(Node *node); // add a new node at the end
    Node *pop();                // retrive the head node
    void clear();               // clear the queue
    int getSize() const;        // return the number of nodes in the queue
    int getCapacity() const;    // capacity
    void printAllValues() const;
};