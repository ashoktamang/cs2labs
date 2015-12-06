#include "student.h"
#include <string>

using namespace std;

class gradStudent: public Student
{
public:
	void Initialize(string name, int id, float GPA, string research_area);
	string GetResearchArea();
private:
	string research_area;
};

struct department 
{
	Student undergradStudents[15];
	gradStudent GradStudents[15];
	
	void sortUndergradsArrayGPA(int length);
	void sortGradsArrayGPA(int length);
	void printUndergradsArray(int length);
	void printGradsArray(int length);
};