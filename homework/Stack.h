#pragma once

#include <iostream>

using namespace std;

class Stack
{
    struct Node
    {
        char data;
        Node* next;
    };

    Node* top;

public:

    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    void push(char val)
    {
        Node* newNode = new Node;

        newNode->data = val;
        newNode->next = top;

        top = newNode;
    }

    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }

        Node* temp = top;
        char value = top->data;

        top = top->next;

        delete temp;

        return value;
    }

    char peek() const
    {
        if (isEmpty())
        {
            return '\0';
        }

        return top->data;
    }

    bool isOpenBracket(char c)
    {
        return c == '(' || c == '[' || c == '{';
    }

    bool isCloseBracket(char c)
    {
        return c == ')' || c == ']' || c == '}';
    }

    bool isCorrectBracket(char open, char close)
    {
        if (open == '(' && close == ')')
        {
            return true;
        }

        if (open == '[' && close == ']')
        {
            return true;
        }

        if (open == '{' && close == '}')
        {
            return true;
        }

        return false;
    }

    bool checkBrackets()
    {
        char c;

        while (cin.get(c))
        {
            if (c == ';')
            {
                break;
            }

            if (isOpenBracket(c))
            {
                push(c);
            }
            else if (isCloseBracket(c))
            {
                if (isEmpty())
                {
                    return false;
                }

                char open = pop();

                if (!isCorrectBracket(open, c))
                {
                    return false;
                }
            }
        }

        if (!isEmpty())
        {
            return false;
        }

        return true;
    }
};