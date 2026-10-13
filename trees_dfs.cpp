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
   Node *A = new Node;
   Node *B = new Node;
   Node *C = new Node;
   Node *D = new Node;
   Node *E = new Node;

   A->data = 1;
   B->data = 2;
   C->data = 3;
   D->data = 4;
   E->data = 5;

   A->left = B;
   A->right = C;

   B->left = D;
   B->right = E;

   C->left = NULL;
   C->right = NULL;

   D->left = NULL;
   D->right = NULL;

   E->left = NULL;
   E->right = NULL;

   cout << A->data << endl;
   cout << A->left->data << endl;
   cout << A->right->data << endl;
   cout << B->left->data << endl;
   cout << B->right->data << endl;

   return 0;
}