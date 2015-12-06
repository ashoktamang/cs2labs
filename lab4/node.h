
enum RelationType {LESS, EQUAL, GREATER}; //struct of comparison boolean

struct Node
{
// Initiating Node Struct
  int data;
  Node* next;
  RelationType ComparedTo(Node* other_node); //Compares one node with another
};