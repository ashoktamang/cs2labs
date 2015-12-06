#include "TreeNode.h"

bool TreeType::IsFull() const
// Returns true if the free store has no room for another node
//  and false otherwise.
{
  TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

bool TreeType::IsEmpty() const
// Returns true if the tree is empty and false otherwise.
{
  return root == NULL;
}

int CountNodes(TreeNode* tree);

int TreeType::LengthIs() const
// Calls the recursive function CountNodes to count the
//  nodes in the tree.
{
	return CountNodes(root);
}

int CountNodes(TreeNode* tree)
// Post: Returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void Retrieve(TreeNode* tree, ItemType& item, bool& found);

void TreeType::RetrieveItem(ItemType& item, bool& found) const
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
}

void Retrieve(TreeNode* tree, ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem;
//       otherwise, found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found);// Search right subtree.
}
else {
  item = tree->info;
  found = true;
}

void Insert(TreeNode*& tree, ItemType item);
void TreeType::InsertItem(ItemType item)
// Calls the recursive function Insert to insert item into tree.
{
  Insert(root, item);
}

void Insert(TreeNode*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
	if (tree == NULL)
	{// Insertion place found.
		tree = new TreeNode;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
	}
	else if (item < tree->info)
		  Insert(tree->left, item);
	else
	  Insert(tree->right, item);
}

void DeleteNode(TreeNode*& tree);
void Delete(TreeNode*& tree, ItemType item);
void TreeType::DeleteItem(ItemType item)
// Calls the recursive function Delete to delete item from tree.
{
  Delete(root, item);
}
void Delete(TreeNode*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    Delete(tree->left, item);
  else if (item > tree->info)
// Look in left subtree.
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);           // Node found; call DeleteNode.
}

void GetPredecessor(TreeNode* tree, ItemType& data);
void DeleteNode(TreeNode*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no
//       longer in the tree.  If tree is a leaf node or has only one
//       non-NULL child pointer, the node pointed to by tree is
//       deleted; otherwise, the user's data is replaced by its
//       logical predecessor and the predecessor's node is deleted.
{
  ItemType data;
  TreeNode* tempPtr;
  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
else {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);  // Delete predecessor node.
}

void GetPredecessor(TreeNode* tree, ItemType& data)
// Sets data to the info member of the rightmost node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
    data = tree->info;
}

void PrintTree(TreeNode* tree, std::ofstream& outFile)
// Prints info member of items in tree in sorted order on outFile.
{
  if (tree != NULL)
  {
    PrintTree(tree->left, outFile);   // Print left subtree.
    outFile << tree->info;
    PrintTree(tree->right, outFile);  // Print right subtree.
}

void TreeType::Print(std::ofstream& outFile) const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root, outFile);
}

TreeType::TreeType()
{
	root = NULL; 
}

