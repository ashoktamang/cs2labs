#include "student.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Declare an instance of the struct Student
	Student a_student;

	//Declare an array for student struct
	Student studentsArray[10];

	//Reading from student.txt
	ifstream student_info;
	ifstream readlines;
	student_info.open("student.txt");
	readlines.open("student.txt");

	int numberofStudents = 0;

	string unused;
	while ( std::getline(readlines, unused) )
		++numberofStudents;

	readlines.close();

	cout << numberofStudents;

	for (int index = 0; index < numberofStudents; index++)
	{
		string lastname;
		student_info >> studentsArray[index].name;
		student_info >> lastname;
		studentsArray[index].name += " " + lastname;
		student_info >> studentsArray[index].id;
		student_info >> studentsArray[index].GPA;

	}

	student_info.close();

	sortStudentArrayGPA(studentsArray, numberofStudents);

	printStudents(studentsArray, numberofStudents);

	//Set data members of struct Student
	a_student.name = "John";
	a_student.id = 01234567;
	a_student.GPA = 0.0;

	//Call member function to print the struct
	a_student.printStudent();
	
	system("pause"); // Only necessary if using Visual Studio
	return 0;

	system("pause"); // Only necessary if using Visual Studio
	return 0;
}