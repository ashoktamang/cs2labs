#include "node.h"
#include <iostream>

using namespace std;

void removeDuplicates(Node* head);
void findKthElements(Node* head, int k);
void printLinkedList(Node* head);
void printArray(int list[], int length);
void removeNode(Node* head, Node* currentNode);
void partition(int list[], int length, int value, Node* head);

int main()
{
	// Initializing an illustration of an array for the required operations
	const int MAX_ITEMS = 13;
	int list[MAX_ITEMS] = {4, 6, 4, 96, 23, 12, 20, 52, 20, 50, 1, 5, 13};

	// Initializing the head of the linked list derived from the array
	Node* head = new Node;
	head -> next = NULL;

	Node* current = head;

	cout << "Inital list" << endl;
	printArray(list, MAX_ITEMS);

	cout << "After partitioned into a linked list \n";
	partition(list, MAX_ITEMS, 23, head);
	printLinkedList(head);
	
	cout << "After removing Duplicates" << endl;
	removeDuplicates(head);
	printLinkedList(head);
	

	cout << "From kth = 6th element to the last elemnt of the linked list.\n";
	findKthElements(head, 6);
	

	return 0;

}

// Solution: 1.a:
void removeDuplicates(Node* head)
{
	/* Removes any duplicate elements in the linked list.

		The functions requires O(n**2) time because of the implementation
		of nested while loops.

		Arguments:
			Node* head: head node of the given linked list.
	*/
	Node* iteration = head;

	while (iteration -> next != NULL) {
		Node* duplicateFinder = iteration -> next;
		Node* previous = iteration;
		while (duplicateFinder -> next != NULL)
		{
			if (iteration -> data == duplicateFinder -> data)
			{
				previous -> next = duplicateFinder -> next;

			} else
			{
				previous = duplicateFinder;
			}
			// previous = previous -> next;
			duplicateFinder = duplicateFinder -> next;
		}
		iteration = iteration -> next;
	}
	
	
}

// Solution: 1.b:
void findKthElements(Node* head, int k)
{
	/* Finds the elements from kth index to the last index of the linked
		list and prints those values.

		The function require O(n) time.

		Arguments:
			Node* head: head node of the given linked list.
			int k: index of the list starting from which elements are
					printed till the last index of the list.
	*/

	Node* current = head;
	for (int i = 0; i < k; i++)
	{
		current = current -> next;
	}

	while (current -> next != NULL)
	{
		cout << current -> data << " ";
		current = current -> next;
	}
	cout << current -> data << endl;
}

// Solution 1.c:
void removeNode(Node* head, Node* nodeToRemove)
{
	/* Finds the node in the linked list and removes it

		The function require O(n) time.

		Arguments:
			Node* head: head node of the given linked list.
			Node* nodeToRemove: node's memory address for 
								removing the node remaining in that
								address
	*/
	Node* current = head;

	while (current -> next != nodeToRemove)
	{
		current = current -> next;
	}

	delete(current);
}

// Solution: 1.d:
void partition(int list[], int length, int value, Node* head) 
{
	/* Returns a linkedlist where the elements lesser than the given value
		is on the left side of the value and those greater than the value
		is on the right side of it.

		The function require O(n) time.

		Arguments:
			int list[]: An array from which elements are derived
			int length: length of the array
			int value: the value for the partition
			Node* head: head node of the given linked list.
			
	*/
	Node* current = head;
	Node* lesserthanValue = head;

	Node* greaterthanValue = new Node;
	Node* greater = greaterthanValue;
	Node* lastNode = new Node;
	

	for (int index = 0; index < length; index++) 
	{
		if (list[index] < value)
		{
			lesserthanValue -> data = list[index];
			Node* temp = new Node;
			lesserthanValue -> next = temp;
			lesserthanValue = lesserthanValue -> next;
			current = lesserthanValue;
		}
		else if (list[index] > value)
		{
			greater -> data = list[index];
			lastNode = greater;
			Node* temp = new Node;
			greater -> next = temp;
			greater = greater -> next;
		}
	}
	current -> data = value;
	current -> next = greaterthanValue;
	lastNode -> next = NULL;
}

void printLinkedList(Node* head)
{
	/* Prints a Linked List.
		The function require O(n) time.

		Arguments:
			Node* head: head node of the given linked list.
	*/
	Node* current = head;
	while (current -> next != NULL)
	{
		cout << current -> data << " ";
		current = current -> next;
	}
	cout << current -> data << endl;
}

void printArray(int list[], int length)
{
	/* Prints an array.
		The function require O(n) time.

		Arguments:
			int list[]: An user-defined array.
			int length: length of the array
	*/
	for (int index = 0; index < length; index++)
	{
		cout << list[index] << " ";
	}
	cout << endl;
}


