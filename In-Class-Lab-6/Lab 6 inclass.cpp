// Lab 6 inclass.cpp : This file contains code to stack implementation using an array and a linkedList.

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;


// code to implement stack using a array
// ARRAY_SIZE is set to 10 and it can be changed accordingly.
class Array_Stack {
private:
    const static int ARRAY_SIZE = 10;

    int top = -1;
    int arr[ARRAY_SIZE];

public:
    void push(int e)
    {
        if (this -> isFull())
        {
            throw 0;
        }
        top++;
        arr[top] = e;
        
    }
    int pop()
    {
        if (this -> isEmpty())
        {
            throw 1;
        }
        top--;
        return arr[top + 1];
    }
    int StackTop()
    {
        if (this->isEmpty())
        {
            throw 3;
        }
        return arr[top];
    }
    void Display()
    {
        for (int i = top; i >= 0; --i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (top == ARRAY_SIZE - 1)
        {
            return true;
        }
        return false;
    }

};

class Node {
public:
    int data;
    Node* next;

    Node(int e)
    {
        this->data = e;
        next = nullptr;
    }
};

// Stack implementation using LinkedList
class LinkedList_Stack {
private:
    Node* top;
public:
    LinkedList_Stack()
    {
        this->top = nullptr;
    }

    void push(int e)
    {
        Node* nextItem = new Node(e);
        nextItem->next = top;
        top = nextItem;
    }
    int pop()
    {
        if (this -> isEmpty())
        {
            throw 1;
        }
        int e = this->top->data;
        this->top = top->next;
        return e;
    }
    bool isEmpty()
    {
        if (top == nullptr)
        {
            return true;
        }
        return false;
    }
    int StackTop()
    {
        if (this->isEmpty())
        {
            throw 2;
        }
        return top->data;
    }
    void Display()
    {
        if (!this->isEmpty())
        {
            Node* thisItem = this->top;
            while (thisItem != nullptr)
            {
                cout << thisItem->data << " ";
                thisItem = thisItem->next;
            }
            cout << endl;
        }
    }
};


int main()
{
    auto start1 = high_resolution_clock::now();
    Array_Stack myArrayStack;
    myArrayStack.push(8);
    myArrayStack.push(10);
    myArrayStack.push(5);
    myArrayStack.push(11);
    myArrayStack.push(15);
    myArrayStack.push(23);
    myArrayStack.push(6);
    myArrayStack.push(18);
    myArrayStack.push(20);
    myArrayStack.push(17);
    myArrayStack.Display();
    for (size_t i = 0; i < 5; i++)
    {
        myArrayStack.pop();
    }
    myArrayStack.Display();
    myArrayStack.push(4);
    myArrayStack.push(30);
    myArrayStack.push(3);
    myArrayStack.push(1);
    myArrayStack.Display();

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<chrono::nanoseconds>(end1 - start1);
    cout << "Array stack running time : " << duration1.count() << " ns" << endl;


    auto start = high_resolution_clock::now();

    LinkedList_Stack myStack;
    myStack.push(8);
    myStack.push(10);
    myStack.push(5);
    myStack.push(11);
    myStack.push(15);
    myStack.push(23);
    myStack.push(6);
    myStack.push(18);
    myStack.push(20);
    myStack.push(17);
    myStack.Display();
    for (size_t i = 0; i < 5; i++)
    {
        myStack.pop();
    }
    myStack.Display();
    myStack.push(4);
    myStack.push(30);
    myStack.push(3);
    myStack.push(1);
    myStack.Display();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<chrono::nanoseconds>(end - start);
    cout << "LinkedList stack running time : " << duration.count() << " ns" << endl;
}
