#include "ItemType.h"
// File ItemType.h must be provided by the user of this class.
//  ItemType.h must contain the following definitions:
//  MAX_ITEMS:     the maximum number of items on the list
//  ItemType:      the definition of the objects on the list
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item), which returns
//       LESS, if self "comes before" item
//       GREATER, if self "comes after" item
//       EQUAL, if self and item are the same
class UnsortedType
{
public:
  UnsortedType();
  bool IsFull() const;
  int LengthIs() const;
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetList();
  void GetNextItem(ItemType& item);
private:
  int length;
  ItemType info[MAX_ITEMS];
  int currentPos;
};

