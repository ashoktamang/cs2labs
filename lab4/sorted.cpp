#include <iostream>
#include <string>
#include <fstream>
#include "sorted.h"

using namespace std;

SortedType::SortedType()
{
  head = new Node;
  length = 0;
}

SortedType::~SortedType()
{
  Node* tempPtr;
  while (head != NULL)
  {
    tempPtr = head;
    head = head->next;
    delete tempPtr;
  }
  delete head;
}

void SortedType::readFile()
{

  ifstream in_file;
  in_file.open("integers.txt");
  int num;

  while(in_file >> num)
  {
    Node* new_node = new Node;
    new_node->data = num;
    addNode(new_node);
    new_node = NULL;
    delete new_node;
  }
}

void SortedType::addNode(Node* new_node)
{
  bool moreToSearch = true;
  Node* current = head;
  Node* previous = head;
  while ( moreToSearch )
  {
    if(length == 0)
    {
      head->next = new_node;
      break;
    }
    if(current == NULL)
    {
      previous->next = new_node;
      break;
    }
    switch ( new_node->ComparedTo( current ) )
    {
      case LESS :
        moreToSearch = true;
        previous = current;
        current = current->next;
        break;
      default:
        previous->next = new_node;
        new_node->next = current;
        moreToSearch = false;
        break;
    }
  }
  previous = NULL;
  delete previous;
  current = NULL;
  delete current;
  length++;
}

void SortedType::printList()
{
// print nexted list.
  Node* current = head->next;
  while(current != NULL)
  {
    cout << current->data << ' ';
    current = current->next;
  }
  cout << endl;
  current = NULL;
  delete current;
}

void SortedType::removeDuplicates()
{
  Node* current = head->next;
  Node* previous = head;

  while(current != NULL)
  {
    if(previous->data == current->data)
    {
      previous->next = current->next;
      delete current;
      Node* current = previous->next;
    }
    previous = current;
    current = current->next;
  }
  previous = NULL;
  delete previous;
}

void SortedType::reverse()
{
  Node* next_node = new Node;
  Node* previous = NULL;
  Node* current = head->next;

  while(next_node != NULL)
  {
    next_node = current->next;
    current->next = previous;
    previous = current;
    current = next_node;
  }
  head->next = previous;
  previous = NULL;
  current = NULL;
  delete previous;
}