#include "student.h"
#include <iostream>
using namespace std;

void Student::printStudent()
{
	cout << "Name: " <<	name << endl;
	cout << "ID: "  << id << endl;
	cout <<  "GPA: " << GPA << endl << endl;
}
//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
void sortStudentArrayGPA(Student arr[], int n) {
      int minIndex = 0; 
	  int startIndex = 0;
	  for (startIndex; startIndex < n; startIndex++)
	  {
		   minIndex = startIndex;
		  for (int studentIndex = 0; studentIndex < n; studentIndex++)
		  {
			  if (arr[studentIndex].GPA < arr[minIndex].GPA)
			  {
				  Student temp = arr[minIndex];
				  arr[minIndex] = arr[studentIndex];
				  arr[studentIndex] = temp;
			  }
		  }
	  };
}

//This function takes an array of students and the total number //of students and prints them to console
void printStudents(Student students[], int index){
	for (int i = 0; i < index; i++)
	{
		students[i].printStudent();
	}
}