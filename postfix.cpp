#include <iostream>
#include <string>
#include <cctype>
using namespace std;
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
class Stack
{
Node *top;
public:
Stack()
{
top = NULL;
}
~Stack() 
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
bool shouldPop(char top, char ch)
{
int a = precedence(top), b = precedence(ch);
if (a != b)
return a > b;
return ch != '^';
}
string infixToPostfix(string infix)
{
Stack s;
string postfix = "";
for (size_t i = 0; i < infix.length(); i++)
{
char ch = infix[i];
if (isalnum(ch))
{
postfix += ch;
}
else if (ch == '(')
{
s.push(ch);
}
else if (ch == ')')
{
while (!s.isEmpty() && s.peek() != '(')
postfix += s.pop();
s.pop(); 
}
else
{
while (!s.isEmpty() && shouldPop(s.peek(), ch))
{
postfix += s.pop();
}
s.push(ch);
}
}
while (!s.isEmpty())
postfix += s.pop();
return postfix;
}
int main()
{
string infix;
cout << "Enter Infix Expression : ";
cin >> infix;
cout << "\nPostfix Expression : "
     << infixToPostfix(infix);
return 0;
}
