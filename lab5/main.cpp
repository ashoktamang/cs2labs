#include "StackType.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <fstream>


using namespace std;

bool validSyntax(ifstream &inputfile);

int main() 
{
	StackType stack1;
	StackType stack2;
	StackType stack3;

	srand(time(NULL));

	int index = 0;
	int temp_array[MAX_ITEMS];


	// Solution of 1(a)
	cout << "Solution: 1(a) Twenty UNIQUE integers generated in stack1 are as follows: \n"
		 << "Note: \n"
		 << "Random numbers are generated in the range of 0-1000 for the \n"
		 << "purpose of making it easy to see the results. \n"
		 << "Random numbers without bound is achieved by \n"
		 << "removing '%1000 + 1' in line 31.\n";
	while (index < MAX_ITEMS)
	{
		int temp = rand() % 1000 + 1;
		if (index == 0)
		{
			
			stack1.Push(temp);
			temp_array[index] = temp;
			cout << temp_array[index] << endl;
			index++;
		}
		else
		{
			bool unique_int = true;
			for (int i = 0; i < index; i++)
			{
				if (temp_array[i] == temp)
				{
					unique_int = false;
					break;
				}
			}
			if (unique_int)
			{
				stack1.Push(temp);
				temp_array[index] = temp;
				cout << temp_array[index] << endl;
				index++;
			};		
		};
	};



	// solution of 1(b)
	cout << "Solution: 1(b) Reverse order of stack1 is given below" << endl;

	for (int index = 0; index < MAX_ITEMS; index++)
	{
		cout << stack1.Top() << endl;
		stack2.Push(stack1.Top());
		stack1.Pop();

	};

	for (int index = 0; index < MAX_ITEMS; index++)
	{
		stack1.Push(stack2.Top());
		stack2.Pop();
	};

	//solution of 1(c)
	cout << " Solution 1(c): Sorting the stack1. \n";
	cout << " Solution 1(d): Now, printing the sorted stack1.\n";

	/* stack1 = source
	   stack2 = result
	   stack3 = temp
	*/
	
	while (!stack1.IsEmpty())
	{
		if (stack2.IsEmpty())
		{
			stack2.Push(stack1.Top());
			stack1.Pop();
		}
		while(stack1.Top() > stack2.Top())
		{	
			stack3.Push(stack2.Top());
			stack2.Pop();
			if (stack2.IsEmpty())
				break;	
		}
		stack2.Push(stack1.Top());
		stack1.Pop();
		while(!stack3.IsEmpty())
		{
			stack2.Push(stack3.Top());
			stack3.Pop();
		}
	};

	
	for (int index = 0; index < MAX_ITEMS; index++)
	{
		cout << stack2.Top() << endl;
		stack1.Push(stack2.Top());
		stack2.Pop();
	};

    

    cout << "\n (Solution 2) Test case passing through the function. \n"
         << "}{{[]}}[]() \n";

    ifstream expression;
    expression.open("expression.txt");
    if (validSyntax(expression))
    {
    	cout << "Syntax is correct." << endl;
    }
    else
    	cout << "Syntax is incorrect." << endl;

    expression.close();

	
	return 0;
}

bool validSyntax(ifstream &inputfile)
{
	using namespace std;

	StackType stack1;
	

	int sqr_counter = 0, curly_counter = 0, par_counter = 0;


	char c;

	// while(inputfile.get(c))
	// {
	// 	cout << "c" << c << endl;
	// };

	while(inputfile.get(c))
	{
		stack1.Push(c);		
	}
	// inputfile.close();
	while(!stack1.IsEmpty())
	{
		if (sqr_counter == 0 && stack1.Top() == ']') return false;
		if (curly_counter == 0 && stack1.Top() == '}') return false;
		if (par_counter == 0 && stack1.Top() == ')') return false;
		if (stack1.Top() == '[' || stack1.Top() == ']') sqr_counter++;
		if (stack1.Top() == '{' || stack1.Top() == '}') curly_counter++;
		if (stack1.Top() == '(' || stack1.Top() == ')') par_counter++;

		stack1.Pop();
	}

	if (sqr_counter % 2 != 0) return false;
	if (curly_counter % 2 != 0) return false;
	if (par_counter % 2 != 0) return false;

	return true;
	
}