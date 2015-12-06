const int MAX_ITEMS = 20;

class StackType
{
public:
  StackType();
  bool IsEmpty() const;
  bool IsFull() const;
  void Push(int item);
  void Pop();
  int Top() const;
private:
  int top;
  int items[MAX_ITEMS];
};