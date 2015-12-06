#include "node.h"

using namespace std;

class SortedType
// functions enclosed in a class which manipulates and creates linked list
{
public:	
  SortedType();
  ~SortedType();
  void readFile();
  void addNode(Node*);
  void printList();
  void removeDuplicates();
  void reverse();

private:
  Node* head;
  int length;
};
