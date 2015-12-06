#include <string>
using namespace std;

class Student
{
public:
	void Initialize(string name, int id, float GPA);
	string GetName();
	int GetID() const;
	float GetGPA();
private:
	string name;
	int id;
	float GPA;
};
