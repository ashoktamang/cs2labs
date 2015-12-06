#include "StackType.h"
#include <iostream>
#include <fstream>


using namespace std;

StackType::StackType()
{
	top = -1; 
}

bool StackType::IsEmpty() const
{
  return (top == -1);
}

bool StackType::IsFull() const
{
  return (top == MAX_ITEMS - 1);
}

void StackType::Push(int newItem)
{
	if (IsFull())
		cout << "Stack is Full" << endl;
	top++;
	items[top] = newItem;
}

void StackType::Pop()
{
	if (IsEmpty())
		cout << "Stack is Empty" << endl;
	top--;
}

int StackType::Top() const
{
  if (IsEmpty())
  	cout << "Stack is Empty" << endl;
	return items[top];
}