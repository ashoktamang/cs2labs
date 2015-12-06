#ifndef LENGTH_CPP
#define LENGTH_CPP

#include <iostream>
using namespace std;

struct Length{



	int hours;
	int minutes;
	int seconds;
	int sec; //to preserve seconds on the next print

	Length(int sec){
		seconds = sec;
	}

	Length(){

	}

	void print(){
		minutes = seconds /60;
		hours = minutes / 60;

		minutes = minutes % 60;
		sec = seconds % 60;


		
		cout << hours <<":"<<minutes<<":"<< sec <<endl;

	}

     
};

#endif