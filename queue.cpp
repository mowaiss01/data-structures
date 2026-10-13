#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *next;
};

struct Queue
{
   Node *front;
   Node *rear;
};

void initialize(Queue &q)
{
   q.front = nullptr;
   q.rear = nullptr;
}

int counter(Queue &q)
{
   int count = 0;
   Node *current = q.front;

   while (current != nullptr)
   {
      count++;
      current = current->next;
   }

   return count;
}

void display(Queue &q)
{
   if (q.front == nullptr)
   {
      cout << "Queue is empty\n";
      return;
   }

   Node *current = q.front;

   cout << "FRONT -> ";

   while (current != nullptr)
   {
      cout << current->data << " ";
      current = current->next;
   }

   cout << "<- REAR" << endl;
}

// INSERT AT REAR
void enqueue(Queue &q, int value)
{
   Node *newNode = new Node;
   newNode->data = value;
   newNode->next = nullptr;

   if (q.front == nullptr)
   {
      q.front = newNode;
      q.rear = newNode;
      return;
   }

   q.rear->next = newNode;
   q.rear = newNode;
}

// DELETE FROM FRONT
void dequeue(Queue &q)
{
   if (q.front == nullptr)
   {
      cout << "Queue is empty\n";
      return;
   }

   Node *temp = q.front;

   cout << "Removed value: " << temp->data << endl;

   q.front = q.front->next;

   if (q.front == nullptr)
      q.rear = nullptr;

   delete temp;
}

// READ FRONT VALUE
void peek(Queue &q)
{
   if (q.front == nullptr)
   {
      cout << "Queue is empty\n";
      return;
   }

   cout << "Front value: " << q.front->data << endl;
}

// UPDATE FRONT
void updateAtBeginning(Queue &q, int value)
{
   if (q.front == nullptr)
   {
      cout << "Queue is empty\n";
      return;
   }

   q.front->data = value;
}

// UPDATE REAR
void updateAtEnd(Queue &q, int value)
{
   if (q.rear == nullptr)
   {
      cout << "Queue is empty\n";
      return;
   }

   q.rear->data = value;
}

// UPDATE AT ANY POSITION FROM FRONT
void updateAtPosition(Queue &q, int value, int pos)
{
   if (pos < 1 || pos > counter(q))
   {
      cout << "Invalid position\n";
      return;
   }

   Node *current = q.front;

   for (int i = 1; i < pos; i++)
      current = current->next;

   current->data = value;
}

// FREE ALL MEMORY
void clearQueue(Queue &q)
{
   while (q.front != nullptr)
   {
      Node *temp = q.front;
      q.front = q.front->next;
      delete temp;
   }

   q.rear = nullptr;
}

int main()
{
   Queue q;
   initialize(q);

   // Insertion
   enqueue(q, 10);
   enqueue(q, 20);
   enqueue(q, 30);
   enqueue(q, 40);

   cout << "Queue after enqueue:\n";
   display(q);

   // Read front
   peek(q);

   // Updating
   updateAtBeginning(q, 100);
   updateAtEnd(q, 400);
   updateAtPosition(q, 200, 2);

   cout << "Queue after updating:\n";
   display(q);

   // Deletion
   dequeue(q);

   cout << "Queue after dequeue:\n";
   display(q);

   cout << "Total nodes: " << counter(q) << endl;

   clearQueue(q);

   return 0;
}