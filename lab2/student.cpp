#include "student.h"
#include <iostream>
using namespace std;

void Student::Initialize(string new_name, int new_id, float new_GPA)
{
	name = new_name;
	id = new_id;
	GPA = new_GPA;
}

string Student::GetName()
{
	return name;
}

int Student::GetID() const
{
	return id;
}

float Student::GetGPA()
{
	return GPA;
}