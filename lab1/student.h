#include <string>
using namespace std;

struct Student
{
	string name;
	int id;
	float GPA;
	void printStudent();
};

//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
void sortStudentArrayGPA(Student arr[], int n);

//This function takes an array of students and the total number //of students and prints them to console
void printStudents(Student students[], int index);
