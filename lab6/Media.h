#include <string>

using namespace std;

class Media
{
private:
	string media_title;
	string media_length;
public:
	void Initialize ( string newmedia_title, string newmedia_length);
	virtual void display ();
	string getTitle();
	string getLength();
};

class Song: public Media
{
public:
	virtual void display();
};


class Video: public Media
{
public:
	virtual void display();
};