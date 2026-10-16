
#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *next;
   Node *prev;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value)
{
   Node *newNode = new Node;

   newNode->data = value;
   newNode->next = NULL;
   newNode->prev = rear;

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
   else
   {
      front->prev = NULL;
   }

   delete temp;
}

void peek()
{
   if (front == NULL)
   {
      cout << "Queue is empty!" << endl;
      return;
   }

   cout << "Front element: " << front->data << endl;
}

void display()
{
   if (front == NULL)
   {
      cout << "Queue is empty!" << endl;
      return;
   }

   Node *temp = front;

   cout << "Queue (front to rear): ";

   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }

   cout << endl;
}

void displayReverse()
{
   if (rear == NULL)
   {
      cout << "Queue is empty!" << endl;
      return;
   }

   Node *temp = rear;

   cout << "Queue (rear to front): ";

   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->prev;
   }

   cout << endl;
}

int main()
{
   enqueue(10);
   enqueue(20);
   enqueue(30);
   enqueue(40);

   cout << "\nInitial queue:" << endl;
   display();

   peek();

   dequeue();

   cout << "\nAfter DEQUEUE:" << endl;
   display();

   cout << "\nReverse display:" << endl;
   displayReverse();

   enqueue(50);

   cout << "\nAfter ENQUEUE:" << endl;
   display();

   // Free all remaining nodes
   while (front != NULL)
   {
      Node *temp = front;
      front = front->next;
      delete temp;
   }

   rear = NULL;

   return 0;
}
