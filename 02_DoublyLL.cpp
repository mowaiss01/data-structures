#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *prev;
   Node *next;
};

int isEmpty(Node *head)
{
   return head == NULL;
}

int counter(Node *head)
{
   int count = 0;

   Node *temp = head;
   while (head != nullptr)
   {
      count++;
      temp = temp->next;
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
   newNode->next = head;
   newNode->prev = nullptr;

   if (head != nullptr)
      head->prev = newNode;

   head = newNode;

   return head;
}

// INSERT AT END
Node *insertAtEnd(Node *head, int value)
{
   Node *newNode = new Node;
   newNode->data = value;
   newNode->next = nullptr;

   if (head == nullptr)
   {
      newNode->prev = nullptr;
      return newNode;
   }

   Node *temp = head;

   while (temp->next != nullptr)
      temp = temp->next;

   temp->next = newNode;
   newNode->prev = temp;

   return head;
}

// INSERT AT ANY POSITION
Node *insertAtPosition(Node *head, int value, int position)
{
   if (position == 1)
      return insertAtBeginning(head, value);

   Node *temp = head;

   for (int i = 1; i < position - 1 && temp != NULL; i++)
   {
      temp = temp->next;
   }

   if (temp == NULL)
   {
      cout << "Invalid Position\n";
      return head;
   }

   Node *newNode = new Node;

   newNode->data = value;
   newNode->prev = temp;
   newNode->next = temp->next;

   if (temp->next != NULL)
      temp->next->prev = newNode;

   temp->next = newNode;

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
Node *deleteAtPosition(Node *head, int value)
{
   if (head == NULL)
      return NULL;

   Node *temp = head;

   while (temp != NULL && temp->data != value)
   {
      temp = temp->next;
   }

   if (temp == NULL)
   {
      cout << "Value Not Found\n";
      return head;
   }

   if (temp == head)
      return deleteAtBeginning(head);

   if (temp->next != NULL)
      temp->next->prev = temp->prev;

   temp->prev->next = temp->next;

   delete temp;

   return head;
}

// Search

int search(Node *head, int key)
{
   int position = 1;

   Node *temp = head;

   while (temp != NULL)
   {
      if (temp->data == key)
         return position;

      temp = temp->next;
      position++;
   }

   return -1;
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