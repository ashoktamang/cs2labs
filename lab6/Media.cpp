#include "Media.h"
#include <iostream>

void Media::Initialize ( string newmedia_title, string newmedia_length)
{
	newmedia_title = media_title;
	newmedia_length = media_length;
}

void Media::display() 
{
	std::cout << "Media to be displayed" << endl;
}

void Song::display()
{
	std::cout << "Song: " << media_title << " " << media_length << endl;
}

void Video::display()
{
	std::cout << "Video: " << media_title << " " << media_length << endl;
}