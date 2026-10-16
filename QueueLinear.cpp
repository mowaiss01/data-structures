
#include <iostream>
using namespace std;

const int SIZE = 5;

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
   //condition for empty queue
   if (rear == SIZE - 1)
   {
      cout << "Overflow: Queue is full!" << endl;
      return;
   }

   //first element
   if (front == -1)
   {
      front = 0;
   }

   rear++;
   queue[rear] = value;

   cout << value << " inserted into queue." << endl;
}

void dequeue()
{
   if (front == -1)
   {
      cout << "Underflow: Queue is empty!" << endl;
      return;
   }
   cout << "Removed element: " << queue[front] << endl;

   if (front == rear)
   {
      front = rear = -1;
   }
   else
   {
      front++;
   }
}

void peek()
{
   if (front == -1)
   {
      cout << "Queue is empty!" << endl;
      return;
   }

   cout << "Front element: " << queue[front] << endl;
}

void display()
{
   if (front == -1)
   {
      cout << "Queue is empty!" << endl;
      return;
   }

   cout << "Queue: ";

   for (int i = front; i <= rear; i++)
   {
      cout << queue[i] << " ";
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

   dequeue();

   cout << "\nAfter DEQUEUE:" << endl;
   display();

   enqueue(50);
   peek();

   cout << "\nFinal queue:" << endl;
   display();

   return 0;
}
