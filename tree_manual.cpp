#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *left;
   Node *right;
};

int main()
{
   Node *root = new Node;

   root->data = 10;
   root->left = NULL;
   root->right = NULL;

   root->left = new Node;
   root->left->data = 20;
   root->left->left = NULL;
   root->left->right = NULL;

   root->right = new Node;
   root->right->data = 30;
   root->right->left = NULL;
   root->right->right = NULL;

   cout << root->data << endl;
   cout << root->left->data << endl;
   cout << root->right->data << endl;

   return 0;
}