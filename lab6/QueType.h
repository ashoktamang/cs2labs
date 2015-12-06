#include "Media.h"
#include <string>

using namespace std;

class QueType
{
public:
  QueType(int max);
  QueType();
  ~QueType();
  void MakeEmpty();

bool IsEmpty() const;
  bool IsFull() const;
  void Enqueue(Media newItem);
  void Dequeue(Media& item);
private:
  int front;
  int rear;
  Media* items;
  int maxQue;
};