#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *next;
};

Node *top = NULL;

void push(int value)
{
   Node *newNode = new Node;

   newNode->data = value;
   newNode->next = top;
   top = newNode;
}

void pop()
{
   if (top == NULL)
   {
      cout << "Underflow: Stack is empty!" << endl;
      return;
   }

   Node *temp = top;
   // cout << "Popped element: " << temp->data << endl;

   top = top->next;
   delete temp;
}

// PEEK: Display the top value
void peek()
{
   if (top == NULL)
   {
      cout << "Stack is empty!" << endl;
      return;
   }

   cout << "Top element: " << top->data << endl;
}

void display()
{
   if (top == NULL)
   {
      cout << "Stack is empty!" << endl;
      return;
   }

   Node *temp = top;

   cout << "Stack (top to bottom): ";

   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }

   cout << endl;
}

int main()
{
   push(10);
   push(20);
   push(30);
   push(40);

   display();

   peek();

   pop();

   cout << "\nAfter POP:" << endl;
   display();

   return 0;
}