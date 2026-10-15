
#include <iostream>
using namespace std;

const int SIZE = 5;

int queue[SIZE];
int front = -1;
int rear = -1;

// ENQUEUE: Insert at rear
void enqueue(int value)
{
   // Check if queue is full
   if ((rear + 1) % SIZE == front)
   {
      cout << "Overflow: Circular queue is full!" << endl;
      return;
   }

   // First element
   if (front == -1)
   {
      front = rear = 0;
   }
   else
   {
      rear = (rear + 1) % SIZE;
   }

   queue[rear] = value;

   cout << value << " inserted into queue." << endl;
}

// DEQUEUE: Remove from front
void dequeue()
{
   if (front == -1)
   {
      cout << "Underflow: Queue is empty!" << endl;
      return;
   }

   cout << "Removed element: " << queue[front] << endl;

   // Only one element exists
   if (front == rear)
   {
      front = rear = -1;
   }
   else
   {
      front = (front + 1) % SIZE;
   }
}

// PEEK: Display front element
void peek()
{
   if (front == -1)
   {
      cout << "Queue is empty!" << endl;
      return;
   }

   cout << "Front element: " << queue[front] << endl;
}

// DISPLAY: Print elements in queue order
void display()
{
   if (front == -1)
   {
      cout << "Queue is empty!" << endl;
      return;
   }

   cout << "Circular Queue: ";

   int i = front;

   while (true)
   {
      cout << queue[i] << " ";

      if (i == rear)
      {
         break;
      }

      i = (i + 1) % SIZE;
   }

   cout << endl;
}

int main()
{
   enqueue(10);
   enqueue(20);
   enqueue(30);
   enqueue(40);
   enqueue(50);

   cout << "\nInitial queue:" << endl;
   display();

   dequeue();
   dequeue();

   cout << "\nAfter two DEQUEUE operations:" << endl;
   display();

   enqueue(60);
   enqueue(70);

   cout << "\nAfter inserting 60 and 70:" << endl;
   display();

   peek();

   return 0;
}
