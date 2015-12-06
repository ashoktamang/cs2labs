#include <iostream>

struct TreeNode;

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
{
public:
  TreeType();                     // Constructor.
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int LengthIs() const;
  void RetrieveItem(ItemType& item, bool& found) const;
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order);
  void GetNextItem(ItemType& item, OrderType order,
       bool& finished);
  void Print(std::ofstream& outFile) const;
private:
  TreeNode* root;
};

struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

