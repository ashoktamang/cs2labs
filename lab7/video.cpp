#include <iostream>
#include <string>
#include "media.h"
#include "video.h"
#include "length.cpp"
using namespace std;

video::video(string mtitle, Length* mlength) : media(mtitle, mlength){

}

void video::check(){
	cout << "checking if function inside video works\n";
}

void video::display(){
	cout << "Video: " << getTitle() << " " ;
	getLength()->print();
}
