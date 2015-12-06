#include "node.h"
#include <iostream>

using namespace std;

RelationType Node::ComparedTo(Node* other_node)
{
  if(data < other_node->data)
    return GREATER;
  else if(data == other_node->data)
    return EQUAL;
  return LESS;
}