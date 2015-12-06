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
};

class Song: public Media
{
public:
	void display();
};


class Video: public Media
{
public:
	void display();
};