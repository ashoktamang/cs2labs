#include <iostream>

struct TreeNode;

class TreeType
{
public:
  TreeType();
  bool isEmpty() const;
  bool isFull() const;
  int LengthIs() const;
  void InsertItem(int item);
  void DeleteItem(int item);
  void Inorder();
  void Preorder();
  void Postorder();
  bool FindAncestor(int item);
  TreeNode CommonAncestor(int n1, int n2);

private:
  TreeNode* root;
};

struct TreeNode
{
  int info;
  TreeNode* left;
  TreeNode* right;
};