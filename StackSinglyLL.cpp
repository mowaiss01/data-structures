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
   Node *newNode = new Node();

   if (top == NULL)
   {
      newNode->data = value;
      newNode->next = NULL;
      top = newNode;
   }
   else
   {
      newNode->data = value;
      newNode->next = top;
      top = newNode;
   }
}

void pop()
{
   if (top == NULL)
   {
      cout << "Stack is empty!" << endl;
   }
   else
   {
      Node *temp = top;
      cout << "\nPopped: " << temp->data << endl;

      top = top->next;

      delete temp;
   }
}

void display()
{
   Node *temp = top;

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
   push(50);

   cout << "\nStack Using Push: ";
   display();

   pop();
   pop();

   cout << "\nAfter POP: ";
   display();

   return 0;
}