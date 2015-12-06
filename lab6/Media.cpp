#include "Media.h"
#include <iostream>

using namespace std;

void Media::Initialize ( string newmedia_title, string newmedia_length)
{
	newmedia_title = media_title;
	newmedia_length = media_length;
}

void Media::display() 
{
	std::cout << "Media to be displayed" << endl;
}

string Media::getTitle()
{
	return media_title;
}

string Media::getLength()
{
	return media_length;
}

void Song::display()
{
	cout << "Song: " << getTitle() << " " << getLength() << endl;
}

void Video::display()
{
	cout << "Video: " << getTitle() << " " << getLength() << endl;
}