#include "grad_student.h"
#include <string>
#include <iostream>

using namespace std;

void gradStudent::Initialize(string new_name, int new_id, float new_GPA, string new_research_area)
{
	Student::Initialize(new_name, new_id, new_GPA);
	research_area = new_research_area;
}

string gradStudent::GetResearchArea()
{
	return research_area;
}

//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
void department::sortUndergradsArrayGPA(int numberofStudents)
{
	  int minIndex = 0; 
	  for (int startIndex = 0; startIndex < numberofStudents; startIndex++)
	  {
		   minIndex = startIndex;
		  for (int studentIndex = 0; studentIndex < numberofStudents; studentIndex++)
		  {
			  if (undergradStudents[studentIndex].GetGPA() < undergradStudents[minIndex].GetGPA())
			  {
				  Student temp = undergradStudents[minIndex];
				  undergradStudents[minIndex] = undergradStudents[studentIndex];
				  undergradStudents[studentIndex] = temp;
			  }
		  }
	  }
};

//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
void department::sortGradsArrayGPA(int numberofStudents) 
{
      int minIndex = 0; 
	  for (int startIndex = 0; startIndex < numberofStudents; startIndex++)
	  {
		  minIndex = startIndex;
		  for (int studentIndex = 0; studentIndex < numberofStudents; studentIndex++)
		  {
			  if (GradStudents[studentIndex].GetGPA() < GradStudents[minIndex].GetGPA())
			  {
				  gradStudent temp = GradStudents[minIndex];
				  GradStudents[minIndex] = GradStudents[studentIndex];
				  GradStudents[studentIndex] = temp;
			  }
		  }
	  }
};


//This function takes an array of students and the total number //of students and prints them to console
void department::printUndergradsArray(int numberofStudents){
	for (int i = 0; i < numberofStudents; i++)
	{
		cout << "Name: " <<	undergradStudents[i].GetName() << endl;
		cout << "ID: "  << undergradStudents[i].GetID() << endl;
		cout <<  "GPA: " << undergradStudents[i].GetGPA() << endl << endl;
	};
}

void department::printGradsArray(int numberofStudents){
	for (int i = 0; i < numberofStudents; i++)
	{
		cout << "Name: " <<	GradStudents[i].GetName() << endl;
		cout << "ID: "  << GradStudents[i].GetID() << endl;
		cout <<  "GPA: " << GradStudents[i].GetGPA() << endl;
		cout << "Research area: " << GradStudents[i].GetResearchArea() << endl << endl;
	}
}

