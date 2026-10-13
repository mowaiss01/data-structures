
#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *next;
   Node *prev;
};

Node *top = NULL;

// PUSH: Insert a new node at the top
void push(int value)
{
   Node *newNode = new Node;

   newNode->data = value;
   newNode->next = top;
   newNode->prev = NULL;

   if (top != NULL)
   {
      top->prev = newNode;
   }

   top = newNode;

   cout << value << " pushed into stack." << endl;
}

// POP: Remove the top node
void pop()
{
   if (top == NULL)
   {
      cout << "Underflow: Stack is empty!" << endl;
      return;
   }

   Node *temp = top;

   cout << "Popped element: " << temp->data << endl;

   top = top->next;

   if (top != NULL)
   {
      top->prev = NULL;
   }

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

// DISPLAY: Print all nodes from top to bottom
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

// MAIN FUNCTION
int main()
{
   push(10);
   push(20);
   push(30);
   push(40);

   cout << "\nInitial stack:" << endl;
   display();

   push(50);

   cout << "\nAfter PUSH:" << endl;
   display();

   peek();

   pop();

   cout << "\nAfter POP:" << endl;
   display();

   return 0;
}