#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *prev;
   Node *next;
};

// Insert at Beginning
Node *insertBeginning(Node *head, int value)
{
   Node *newNode = new Node;

   newNode->data = value;
   newNode->prev = NULL;
   newNode->next = head;

   if (head != NULL)
      head->prev = newNode;

   head = newNode;

   return head;
}

// Insert at End
Node *insertEnd(Node *head, int value)
{
   Node *newNode = new Node;

   newNode->data = value;
   newNode->next = NULL;

   if (head == NULL)
   {
      newNode->prev = NULL;
      return newNode;
   }

   Node *temp = head;

   while (temp->next != NULL)
   {
      temp = temp->next;
   }

   temp->next = newNode;
   newNode->prev = temp;

   return head;
}

// Insert at Specific Position
Node *insertPosition(Node *head, int value, int position)
{
   if (position == 1)
      return insertBeginning(head, value);

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

// Delete from Beginning
Node *deleteBeginning(Node *head)
{
   if (head == NULL)
      return NULL;

   Node *temp = head;

   head = head->next;

   if (head != NULL)
      head->prev = NULL;

   delete temp;

   return head;
}

// Delete from End
Node *deleteEnd(Node *head)
{
   if (head == NULL)
      return NULL;

   if (head->next == NULL)
   {
      delete head;
      return NULL;
   }

   Node *temp = head;

   while (temp->next != NULL)
   {
      temp = temp->next;
   }

   temp->prev->next = NULL;

   delete temp;

   return head;
}

// Delete by Value
Node *deleteValue(Node *head, int value)
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
      return deleteBeginning(head);

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

// Display Forward
void displayForward(Node *head)
{
   Node *temp = head;

   while (temp != NULL)
   {
      cout << temp->data << " <-> ";
      temp = temp->next;
   }

   cout << "NULL\n";
}

// Display Backward
void displayBackward(Node *head)
{
   if (head == NULL)
      return;

   Node *temp = head;

   while (temp->next != NULL)
   {
      temp = temp->next;
   }

   while (temp != NULL)
   {
      cout << temp->data << " <-> ";
      temp = temp->prev;
   }

   cout << "NULL\n";
}

// Check Empty
int isEmpty(Node *head)
{
   return head == NULL;
}

// Count Nodes
int countNodes(Node *head)
{
   int count = 0;

   Node *temp = head;

   while (temp != NULL)
   {
      count++;
      temp = temp->next;
   }

   return count;
}

// Copy List
Node *copyList(Node *head)
{
   Node *newHead = NULL;
   Node *temp = head;

   while (temp != NULL)
   {
      newHead = insertEnd(newHead, temp->data);
      temp = temp->next;
   }

   return newHead;
}

// Clear Complete List
Node *clearList(Node *head)
{
   while (head != NULL)
   {
      Node *temp = head;
      head = head->next;
      delete temp;
   }

   return NULL;
}

int main()
{
   Node *head = NULL;

   head = insertBeginning(head, 20);
   head = insertBeginning(head, 10);

   head = insertEnd(head, 30);
   head = insertEnd(head, 40);

   cout << "Original List: ";
   displayForward(head);

   head = insertPosition(head, 25, 3);

   cout << "After Insertion: ";
   displayForward(head);

   head = deleteBeginning(head);

   cout << "After Delete Beginning: ";
   displayForward(head);

   head = deleteEnd(head);

   cout << "After Delete End: ";
   displayForward(head);

   head = deleteValue(head, 25);

   cout << "After Delete Value: ";
   displayForward(head);

   cout << "Backward Display: ";
   displayBackward(head);

   cout << "Search 30: Position " << search(head, 30) << endl;

   cout << "Total Nodes: " << countNodes(head) << endl;

   Node *copiedList = copyList(head);

   cout << "Copied List: ";
   displayForward(copiedList);

   head = clearList(head);

   cout << "Original List Cleared: ";
   displayForward(head);

   copiedList = clearList(copiedList);

   return 0;
}