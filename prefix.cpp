//Assignment 2
// Stack ADT using Singly Linked List: Infix to Prefix
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Node for Linked List
class Node
{
public:
    char data;
    Node *next;

    Node(char x)
    {
        data = x;
        next = NULL;
    }
};

// Stack ADT using Linked List
class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    ~Stack() // free remaining nodes
    {
        while (top != NULL)
            pop();
    }

    void push(char x)
    {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (top == NULL)
            return '\0';

        char x = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    char peek()
    {
        if (top == NULL)
            return '\0';
        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

// Function to check precedence
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Should the operator on stack top be popped before pushing ch?
// Works on the reversed string: equal precedence pops only for '^'.
bool shouldPop(char top, char ch)
{
    int a = precedence(top), b = precedence(ch);
    if (a != b)
        return a > b;
    return ch == '^';
}

// Infix to Prefix
string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());

    for (size_t i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    Stack s;
    string prefix = "";

    for (size_t i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            prefix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
                prefix += s.pop();

            s.pop(); // Remove '('
        }
        else
        {
            while (!s.isEmpty() && shouldPop(s.peek(), ch))
            {
                prefix += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty())
        prefix += s.pop();

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string infix;

    cout << "Enter Infix Expression : ";
    cin >> infix;

    cout << "\nPrefix Expression : "
         << infixToPrefix(infix);

    return 0;
}
