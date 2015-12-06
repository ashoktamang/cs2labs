#include <iostream>
#include <string>
#include "media.h"
#include "music.h"
#include "length.cpp"
using namespace std;

media::media(string mtitle, Length* mlength){
	title = mtitle;
	length = mlength;
}

void media::display(){
	cout << "SONGVIDEO BOTH: " << getTitle();
	getLength()->print();
}

string media::getTitle(){
	return title;
}

media::media(){

}


Length* media::getLength(){
	return length;
}



