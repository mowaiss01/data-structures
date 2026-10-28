#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *left;
   Node *right;
};

// 1. CREATE / INSERTION
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
      root->left = insert(root->left, value);
   else if (value > root->data)
      root->right = insert(root->right, value);

   return root;
}

// 2. CHECK EMPTY
bool isEmpty(Node *root)
{
   return root == NULL;
}

// 3. SEARCH
Node *search(Node *root, int key)
{
   if (root == NULL || root->data == key)
      return root;

   if (key < root->data)
      return search(root->left, key);

   return search(root->right, key);
}

// 4. LEFT CHILD
Node *leftChild(Node *root, int key)
{
   Node *parent = search(root, key);

   if (parent == NULL)
      return NULL;

   return parent->left;
}

// 5. RIGHT CHILD
Node *rightChild(Node *root, int key)
{
   Node *parent = search(root, key);

   if (parent == NULL)
      return NULL;

   return parent->right;
}

// 6. FIND PARENT
Node *findParent(Node *root, int key)
{
   if (root == NULL || root->data == key)
      return NULL;

   if ((root->left != NULL && root->left->data == key) ||
       (root->right != NULL && root->right->data == key))
      return root;

   if (key < root->data)
      return findParent(root->left, key);

   return findParent(root->right, key);
}

// 7. FIND SIBLING
Node *findSibling(Node *root, int key)
{
   Node *parent = findParent(root, key);

   if (parent == NULL)
      return NULL;

   if (parent->left != NULL && parent->left->data == key)
      return parent->right;

   return parent->left;
}

// 8. PREORDER
void preorder(Node *root)
{
   if (root == NULL)
      return;

   cout << root->data << " ";
   preorder(root->left);
   preorder(root->right);
}

// 9. INORDER
void inorder(Node *root)
{
   if (root == NULL)
      return;

   inorder(root->left);
   cout << root->data << " ";
   inorder(root->right);
}

// 10. POSTORDER
void postorder(Node *root)
{
   if (root == NULL)
      return;

   postorder(root->left);
   postorder(root->right);
   cout << root->data << " ";
}

// 11. FIND MINIMUM
Node *findMin(Node *root)
{
   if (root == NULL)
      return NULL;

   while (root->left != NULL)
      root = root->left;

   return root;
}

// 12. FIND MAXIMUM
Node *findMax(Node *root)
{
   if (root == NULL)
      return NULL;

   while (root->right != NULL)
      root = root->right;

   return root;
}

// 13. DELETION
Node *deleteNode(Node *root, int key)
{
   if (root == NULL)
      return NULL;

   if (key < root->data)
      root->left = deleteNode(root->left, key);

   else if (key > root->data)
      root->right = deleteNode(root->right, key);

   else
   {
      // CASE 1: NO CHILD
      if (root->left == NULL && root->right == NULL)
      {
         delete root;
         return NULL;
      }

      // CASE 2: ONLY RIGHT CHILD
      else if (root->left == NULL)
      {
         Node *temp = root->right;
         delete root;
         return temp;
      }

      // CASE 2: ONLY LEFT CHILD
      else if (root->right == NULL)
      {
         Node *temp = root->left;
         delete root;
         return temp;
      }

      // CASE 3: TWO CHILDREN
      Node *temp = findMin(root->right);

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
   }

   return root;
}

// 14. COPY TREE
Node *copyTree(Node *root)
{
   if (root == NULL)
      return NULL;

   Node *newNode = new Node;
   newNode->data = root->data;

   newNode->left = copyTree(root->left);
   newNode->right = copyTree(root->right);

   return newNode;
}

int main()
{
   Node *root = NULL;

   // CREATE TREE
   root = insert(root, 50);
   root = insert(root, 30);
   root = insert(root, 70);
   root = insert(root, 20);
   root = insert(root, 40);
   root = insert(root, 60);
   root = insert(root, 80);

   cout << "Tree created successfully.\n";

   // CHECK EMPTY
   if (isEmpty(root))
      cout << "Tree is empty.\n";
   else
      cout << "Tree is not empty.\n";

   // LEFT CHILD
   Node *temp = leftChild(root, 30);

   if (temp != NULL)
      cout << "Left Child of 30: " << temp->data << endl;

   // RIGHT CHILD
   temp = rightChild(root, 30);

   if (temp != NULL)
      cout << "Right Child of 30: " << temp->data << endl;

   // PARENT
   temp = findParent(root, 40);

   if (temp != NULL)
      cout << "Parent of 40: " << temp->data << endl;

   // SIBLING
   temp = findSibling(root, 20);

   if (temp != NULL)
      cout << "Sibling of 20: " << temp->data << endl;

   // PREORDER
   cout << "Preorder: ";
   preorder(root);

   // INORDER
   cout << "\nInorder: ";
   inorder(root);

   // POSTORDER
   cout << "\nPostorder: ";
   postorder(root);

   // SEARCH
   if (search(root, 60) != NULL)
      cout << "\n60 found in tree.\n";
   else
      cout << "\n60 not found in tree.\n";

   // FIND MINIMUM
   temp = findMin(root);

   if (temp != NULL)
      cout << "Minimum value: " << temp->data << endl;

   // FIND MAXIMUM
   temp = findMax(root);

   if (temp != NULL)
      cout << "Maximum value: " << temp->data << endl;

   // INSERTION
   root = insert(root, 25);

   cout << "After inserting 25: ";
   inorder(root);

   // DELETION
   root = deleteNode(root, 30);

   cout << "\nAfter deleting 30: ";
   inorder(root);

   // COPY TREE
   Node *copiedRoot = copyTree(root);

   cout << "\nCopied tree: ";
   inorder(copiedRoot);

   return 0;
}