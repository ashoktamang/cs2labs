#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include "media.h"
#include "length.cpp"
using namespace std;

class video : public media{
public:
	video(string mtitle, Length* mlength);
	void check();

	
	virtual void display();

};

#endif