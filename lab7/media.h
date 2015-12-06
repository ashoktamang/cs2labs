#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <string>
#include "length.cpp"

using namespace std;


class media{
    protected:
     	string title;
    	Length* length;

    public:
    	media();
        media(string mtitle, Length* mlength);
        

	    virtual void display();
	    string getTitle();
	    Length* getLength();

};


#endif