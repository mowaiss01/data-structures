#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *next;
};

int counter(Node *top)
{
   int count = 0;

   while (top != nullptr)
   {
      count++;
      top = top->next;
   }

   return count;
}

void display(Node *top)
{
   if (top == nullptr)
   {
      cout << "Stack is empty\n";
      return;
   }

   Node *current = top;

   cout << "TOP -> ";

   while (current != nullptr)
   {
      cout << current->data << " ";
      current = current->next;
   }

   cout << endl;
}

// INSERT: PUSH AT TOP
Node *push(Node *top, int value)
{
   Node *newNode = new Node;
   newNode->data = value;
   newNode->next = top;

   return newNode;
}

// DELETE: POP FROM TOP
Node *pop(Node *top)
{
   if (top == nullptr)
   {
      cout << "Stack underflow: stack is empty\n";
      return top;
   }

   Node *temp = top;

   cout << "Popped value: " << temp->data << endl;

   top = top->next;

   delete temp;

   return top;
}

// READ TOP VALUE
void peek(Node *top)
{
   if (top == nullptr)
   {
      cout << "Stack is empty\n";
      return;
   }

   cout << "Top value: " << top->data << endl;
}

// UPDATE AT TOP
Node *updateAtBeginning(Node *top, int value)
{
   if (top == nullptr)
   {
      cout << "Stack is empty\n";
      return top;
   }

   top->data = value;

   return top;
}

// UPDATE AT BOTTOM
Node *updateAtEnd(Node *top, int value)
{
   if (top == nullptr)
   {
      cout << "Stack is empty\n";
      return top;
   }

   Node *current = top;

   while (current->next != nullptr)
      current = current->next;

   current->data = value;

   return top;
}

// UPDATE AT ANY POSITION FROM TOP
Node *updateAtPosition(Node *top, int value, int pos)
{
   if (pos < 1 || pos > counter(top))
   {
      cout << "Invalid position\n";
      return top;
   }

   Node *current = top;

   for (int i = 1; i < pos; i++)
      current = current->next;

   current->data = value;

   return top;
}

// FREE ALL MEMORY
void clearStack(Node *top)
{
   while (top != nullptr)
   {
      Node *temp = top;
      top = top->next;
      delete temp;
   }
}

int main()
{
   Node *top = nullptr;

   // Insertion
   top = push(top, 10);
   top = push(top, 20);
   top = push(top, 30);
   top = push(top, 40);

   cout << "Stack after pushing:\n";
   display(top);

   // Read top
   peek(top);

   // Updating
   top = updateAtBeginning(top, 100);
   top = updateAtEnd(top, 400);
   top = updateAtPosition(top, 200, 2);

   cout << "Stack after updating:\n";
   display(top);

   // Deletion
   top = pop(top);

   cout << "Stack after popping:\n";
   display(top);

   cout << "Total nodes: " << counter(top) << endl;

   clearStack(top);

   return 0;
}