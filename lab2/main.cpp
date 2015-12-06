#include "grad_student.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Declare an instance of the struct department
	department Engineering;

	//Declare an instance of the class Student and GradStudent
	Student undergradStudent;
	gradStudent gradStudent;

	//Declare necessary variables to store the information of undergrads and grads
	string firstname, lastname, research_area;
	int id, numberofUndergradStudents = 0, numberofGradStudents = 0;
	float GPA;

	
	//Reading from student.txt
	ifstream undergradStudent_info;
	ifstream gradStudent_info;
	ifstream readlines;
	ofstream writelogs;
	

	undergradStudent_info.open("student.txt");
	readlines.open("student.txt");
	writelogs.open("logs.txt");


	string unused;
	while (getline(readlines, unused) )
		++numberofUndergradStudents;

	readlines.close();

	for (int index = 0; index < numberofUndergradStudents; index++)
	{
		if (undergradStudent_info.fail())
		{
			writelogs << "There is something wrong." << endl;
		}
		else
		{
			undergradStudent_info >> firstname;
			undergradStudent_info >> lastname;
			undergradStudent_info >> id;
			undergradStudent_info >> GPA;

			string fullname = firstname + " " + lastname;
			
			Engineering.undergradStudents[index].Initialize(fullname, id, GPA);
		}
		
	}

	undergradStudent_info.close();

	
	//Reading from graduate.txt
	gradStudent_info.open("graduate.txt");
	readlines.open("graduate.txt");

	string temp;
	while (getline(readlines, temp) )
		++numberofGradStudents;

	readlines.close();

	for (int index = 0; index < numberofGradStudents; index++)
	{
		if(gradStudent_info.fail())
		{
			writelogs << "There is something more wrong." << endl;
		}
		else
		{
			gradStudent_info >> firstname;
			gradStudent_info >> lastname;
			gradStudent_info >> id;
			gradStudent_info >> GPA;
			gradStudent_info >> research_area;

			string fullname = firstname + " " + lastname;
			
			Engineering.GradStudents[index].Initialize(fullname, id, GPA, research_area);
		}
	}

	gradStudent_info.close();

	writelogs.close();

	// Sort undergradStudents and GradStudents arrays
	Engineering.sortUndergradsArrayGPA(numberofUndergradStudents);
	Engineering.sortGradsArrayGPA(numberofGradStudents);

	// Print undergradStudents and GradStudents arrays
	cout << "The Undergraduate Class" << "_____________________" << endl;
	Engineering.printUndergradsArray(numberofUndergradStudents);
	
	cout << "The Graduate Class" << "__________________________" << endl;
	Engineering.printGradsArray(numberofGradStudents);


    return 0;
}