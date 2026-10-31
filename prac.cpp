#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *left;
   Node *right;
};

Node *insert(Node *root, int value)
{
   if (root == NULL)
   {
      Node *newNode = new Node;
      newNode->data = value;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
   }

   if (value < root->data)
   {
      root->left = insert(root->left, value);
   }
   else if (value < root->data)
   {
      root->right = insert(root->right, value);
   }

   return root;
}

bool isEmpty(Node *root)
{
   return root == NULL;
}

Node *search(Node *root, int key)
{
   if (root == NULL || root->data == key)
   {
      return root;
   }

   if (key < root->data)
      return search(root->left, key);

   return search(root->right, key);
}