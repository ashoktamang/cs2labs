#include "QueType.h"
// #include "Media.h"
#include <iostream>

using namespace std;

QueType::QueType(int max)
// Parameterized class constructor.
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new Media[maxQue];
}
QueType::QueType()      // Default class constructor.
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new Media[maxQue];
}
QueType::~QueType()     // Class destructor.
{
  delete [] items;
}
void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(Media newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise, a FullQueue exception is thrown.
{
  if (IsFull())
    cout << "Que is full\n";
  else {
    rear = (rear +1) % maxQue;
    items[rear] = newItem;
  }
}

void QueType::Dequeue(Media& item)
// Post: If (queue is not empty) the front of the queue has been
//       removed and a copy returned in item;
//       otherwise, an EmptyQueue exception is thrown.
{
  if (IsEmpty())
    cout << "Que is Empty\n";
  else {
    front = (front + 1) % maxQue;
    item = items[front];
  }
}

void QueType::print()
{
  int count = (rear + maxQue - front) % maxQue + 1;
      for (int i = 0; i < count; i++){
        int index = (front+i) % maxQue;
        items[index].display();

      }
      cout << " \n \n";
}