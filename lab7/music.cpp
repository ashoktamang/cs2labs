#include <iostream>
#include "media.h"
#include "music.h"
#include "length.cpp"
using namespace std;

music::music(string mtitle, Length* mlength):media(mtitle, mlength){

}


void music::display(){
	cout << "Song: " << getTitle() << " ";
	getLength()->print();
}