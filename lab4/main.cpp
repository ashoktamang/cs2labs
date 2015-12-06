#include <iostream>
#include "sorted.h"

using namespace std;

int main()
{
  
  SortedType integers;
  
  // Reads file from integers.txt
  integers.readFile();

  // Printing the linked list to the console with elements being in ascending order
  integers.printList();

  // Deleting any duplicates in the list
  integers.removeDuplicates();

  // Printing the list having unique lists
  integers.printList();
  
  // Reversing the linked list
  integers.reverse();

  // Printing the reversed linked list
  integers.printList();

  return 0;
}