
#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *next;
};

Node *front = NULL;
Node *rear = NULL;

// ENQUEUE: Insert at rear
void enqueue(int value)
{
   Node *newNode = new Node;

   newNode->data = value;
   newNode->next = NULL;

   if (front == NULL)
   {
      front = rear = newNode;
   }
   else
   {
      rear->next = newNode;
      rear = newNode;
   }

   cout << value << " inserted into queue." << endl;
}

// DEQUEUE: Remove from front
void dequeue()
{
   if (front == NULL)
   {
      cout << "Underflow: Queue is empty!" << endl;
      return;
   }

   Node *temp = front;

   cout << "Removed element: " << temp->data << endl;

   front = front->next;

   if (front == NULL)
   {
      rear = NULL;
   }

   delete temp;
}

// PEEK: Display front element
void peek()
{
   if (front == NULL)
   {
      cout << "Queue is empty!" << endl;
      return;
   }

   cout << "Front element: " << front->data << endl;
}

// DISPLAY: Print all nodes
void display()
{
   if (front == NULL)
   {
      cout << "Queue is empty!" << endl;
      return;
   }

   Node *temp = front;

   cout << "Queue: ";

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
   enqueue(10);
   enqueue(20);
   enqueue(30);

   cout << "\nInitial queue:" << endl;
   display();

   dequeue();

   cout << "\nAfter DEQUEUE:" << endl;
   display();

   enqueue(40);

   cout << "\nAfter ENQUEUE:" << endl;
   display();

   peek();

   // Free remaining nodes
   while (front != NULL)
   {
      Node *temp = front;
      front = front->next;
      delete temp;
   }

   rear = NULL;

   return 0;
}
