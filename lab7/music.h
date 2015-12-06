#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include "media.h"
#include "length.cpp"
using namespace std;

class music : public media{
public:
	music(string mtitle, Length* mlength);
	virtual void display();

};

#endif