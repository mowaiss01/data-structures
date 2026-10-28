#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *left;
   Node *right;

   Node(int val)
   {
      data = val;
      left = right = NULL;
   }
};

bool isValidBST(Node *root, int min, int max)
{
   if (root == NULL)
      return true;

   if (root->data <= min || root->data >= max)
      return false;

   return isValidBST(root->left, min, root->data) &&
          isValidBST(root->right, root->data, max);
}

int main()
{
   Node *root = new Node(40);
   root->left = new Node(20);
   root->right = new Node(60);
   root->left->left = new Node(10);
   root->left->right = new Node(30);

   if (isValidBST(root, -1000, 1000))
      cout << "Valid BST";
   else
      cout << "Invalid BST";

   return 0;
}
