#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *prev;
   Node *next;
};

int counter(Node *head)
{
   int count = 0;

   while (head != nullptr)
   {
      count++;
      head = head->next;
   }

   return count;
}

void display(Node *head)
{
   while (head != nullptr)
   {
      cout << head->data << " ";
      head = head->next;
   }

   cout << endl;
}

void displayBackward(Node *head)
{
   if (head == nullptr)
   {
      cout << endl;
      return;
   }

   while (head->next != nullptr)
      head = head->next;

   while (head != nullptr)
   {
      cout << head->data << " ";
      head = head->prev;
   }

   cout << endl;
}

// INSERT AT BEGINNING
Node *insertAtBeginning(Node *head, int value)
{
   Node *newNode = new Node;
   newNode->data = value;
   newNode->prev = nullptr;
   newNode->next = head;

   if (head != nullptr)
      head->prev = newNode;

   return newNode;
}

// INSERT AT END
Node *insertAtEnd(Node *head, int value)
{
   Node *newNode = new Node;
   newNode->data = value;
   newNode->prev = nullptr;
   newNode->next = nullptr;

   if (head == nullptr)
      return newNode;

   Node *current = head;

   while (current->next != nullptr)
      current = current->next;

   current->next = newNode;
   newNode->prev = current;

   return head;
}

// INSERT AT ANY POSITION
Node *insertAtPosition(Node *head, int value, int pos)
{
   int n = counter(head);

   if (pos < 1 || pos > n + 1)
   {
      cout << "Invalid position\n";
      return head;
   }

   if (pos == 1)
      return insertAtBeginning(head, value);

   if (pos == n + 1)
      return insertAtEnd(head, value);

   Node *current = head;

   for (int i = 1; i < pos - 1; i++)
      current = current->next;

   Node *newNode = new Node;
   newNode->data = value;

   newNode->prev = current;
   newNode->next = current->next;

   current->next->prev = newNode;
   current->next = newNode;

   return head;
}

// DELETE AT BEGINNING
Node *deleteAtBeginning(Node *head)
{
   if (head == nullptr)
   {
      cout << "List is empty\n";
      return head;
   }

   Node *temp = head;
   head = head->next;

   if (head != nullptr)
      head->prev = nullptr;

   delete temp;

   return head;
}

// DELETE AT END
Node *deleteAtEnd(Node *head)
{
   if (head == nullptr)
   {
      cout << "List is empty\n";
      return head;
   }

   if (head->next == nullptr)
   {
      delete head;
      return nullptr;
   }

   Node *current = head;

   while (current->next != nullptr)
      current = current->next;

   current->prev->next = nullptr;

   delete current;

   return head;
}

// DELETE AT ANY POSITION
Node *deleteAtPosition(Node *head, int pos)
{
   int n = counter(head);

   if (pos < 1 || pos > n)
   {
      cout << "Invalid position\n";
      return head;
   }

   if (pos == 1)
      return deleteAtBeginning(head);

   if (pos == n)
      return deleteAtEnd(head);

   Node *current = head;

   for (int i = 1; i < pos; i++)
      current = current->next;

   current->prev->next = current->next;
   current->next->prev = current->prev;

   delete current;

   return head;
}

// UPDATE AT BEGINNING
Node *updateAtBeginning(Node *head, int value)
{
   if (head == nullptr)
   {
      cout << "List is empty\n";
      return head;
   }

   head->data = value;
   return head;
}

// UPDATE AT END
Node *updateAtEnd(Node *head, int value)
{
   if (head == nullptr)
   {
      cout << "List is empty\n";
      return head;
   }

   Node *current = head;

   while (current->next != nullptr)
      current = current->next;

   current->data = value;

   return head;
}

// UPDATE AT ANY POSITION
Node *updateAtPosition(Node *head, int value, int pos)
{
   if (pos < 1 || pos > counter(head))
   {
      cout << "Invalid position\n";
      return head;
   }

   Node *current = head;

   for (int i = 1; i < pos; i++)
      current = current->next;

   current->data = value;

   return head;
}

void clearList(Node *head)
{
   while (head != nullptr)
   {
      Node *temp = head;
      head = head->next;
      delete temp;
   }
}

int main()
{
   Node *head = nullptr;

   head = insertAtBeginning(head, 20);
   head = insertAtBeginning(head, 10);
   head = insertAtEnd(head, 40);
   head = insertAtPosition(head, 30, 3);

   cout << "Forward: ";
   display(head);

   cout << "Backward: ";
   displayBackward(head);

   head = deleteAtBeginning(head);
   head = deleteAtEnd(head);
   head = insertAtEnd(head, 50);
   head = insertAtPosition(head, 35, 2);

   cout << "After deletion and insertion: ";
   display(head);

   head = updateAtBeginning(head, 100);
   head = updateAtEnd(head, 500);
   head = updateAtPosition(head, 300, 2);

   cout << "After updating: ";
   display(head);

   cout << "Total nodes: " << counter(head) << endl;

   clearList(head);

   return 0;
}