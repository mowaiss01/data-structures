#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *insertAtEnd(Node *head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
        return head;
    }

    Node *current = head;

    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head;

    return head;
}

Node *insertAtHead(Node *head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;

    if (head == nullptr)
    {
        newNode->next = newNode;
        return newNode;
    }

    Node *current = head;

    while (current->next != head)
    {
        current = current->next;
    }

    newNode->next = head;
    current->next = newNode;

    head = newNode;

    return head;
}

void display(Node *head)
{
    if (head == nullptr)
    {
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != head);
}

int counter(Node *head)
{
    if (head == nullptr)
    {
        return 0;
    }

    int count = 0;
    Node *temp = head;

    do
    {
        count++;
        temp = temp->next;

    } while (temp != head);

    return count;
}

int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    head->data = 14;
    second->data = 15;
    third->data = 16;
    fourth->data = 17;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    head = insertAtEnd(head, 18);
    head = insertAtEnd(head, 19);
    head = insertAtEnd(head, 20);

    head = insertAtHead(head, 13);
    head = insertAtHead(head, 12);

    display(head);

    cout << "\nTotal Count: " << counter(head) << endl;

    return 0;
}