#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeType::TreeType()
{
  root = NULL;
}

bool TreeType::isEmpty() const
{
  return root == NULL;
}

bool TreeType::isFull() const
{
  TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(bad_alloc exception)
  {
    return true;
  }
}

int CountNodes(TreeNode* tree);

int TreeType::LengthIs() const
{
  return CountNodes(root);
}

int CountNodes(TreeNode* tree)
{
  if (tree == NULL)
    return 0;
  else
    return CountNodes(tree -> left) + CountNodes(tree -> right)  + 1;
}

void Insert(TreeNode*& tree, int item);

void TreeType::InsertItem(int item)
{
  Insert(root, item);
}

void Insert(TreeNode*& tree, int item)
{
  if (tree == NULL)
  {
    tree = new TreeNode;
    tree -> right = NULL;
    tree -> left = NULL;
    tree -> info = item;
  }
  else if (item < tree->info)
    Insert (tree->left, item);
  else
    Insert(tree->right, item);
}

void DeleteNode(TreeNode*& tree);

void Delete(TreeNode*& tree, int item);

void TreeType::DeleteItem(int item)
{
  Delete(root, item);
}

void Delete(TreeNode*& tree, int item)
{
  if (item < tree->info)
    Delete(tree -> left, item);
  else if (item > tree -> info)
    Delete(tree->right, item);
  else
    DeleteNode(tree);
}

void GetPredecessor(TreeNode* tree, int& data);

void DeleteNode(TreeNode*& tree)
{
  int data;
  TreeNode* temp;

  temp = tree;
  if (tree -> left == NULL)
  {
    tree = tree -> right;
    delete temp;
  }
  else if (tree -> right == NULL)
  {
    tree = tree -> left;
    delete temp;
  }
  else
  {
    GetPredecessor(tree->left, data);
    tree -> info = data;
    Delete(tree->left, data);
  }
}

void GetPredecessor(TreeNode* tree, int& data)
{
  while(tree -> right != NULL)
    tree = tree -> right;
  data = tree -> info;
}

void In_order(TreeNode* tree)
{
  if (tree != NULL)
  {
    In_order(tree->left);
    cout << tree -> info << " ";
    In_order(tree->right);
  }
}

void TreeType::Inorder()
{
  return In_order(root);
}

void pre_order(TreeNode* tree)
{
  if(tree != NULL)
  {
    cout << tree->info << " ";
    pre_order(tree->left);
    pre_order(tree->right);
  }
}

void TreeType::Preorder()
{
  return pre_order(root);
}

void post_order(TreeNode* tree)
{
  if(tree != NULL)
  {
    post_order(tree->left);
    post_order(tree -> right);
    cout << tree->info << " ";
  }
}

void TreeType::Postorder()
{
  return post_order(root);
}

bool find_ancestor(TreeNode* tree, int item);

bool TreeType::FindAncestor(int item)
{
  return find_ancestor(root, item);
}

bool find_ancestor(TreeNode* tree, int item)
{
  if (tree == NULL)
    return false;
  if (tree -> info == item)
    return true;
  if(find_ancestor(tree->left, item) || find_ancestor(tree->right, item))
  {
    cout << tree->info << " ";
    return true;
  }
  return false;
}

TreeNode *common_ancestor(TreeNode*& tree, int item1, int item2)
{
  while(tree != NULL)
  {
    if (tree -> info > item1 && tree -> info > item2)
      tree = tree->left;
    else if (tree -> info < item1 && tree -> info < item2)
      tree = tree -> right;
    else
      break;
  }
  return tree;
}

TreeNode TreeType::CommonAncestor(int item1, int item2)
{
  return *common_ancestor(root, item1, item2);
}



