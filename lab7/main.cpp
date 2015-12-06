#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "media.h"
#include "Queue.cpp"
#include "music.h"
#include "video.h"

using namespace std;


int main(){
	//cout << "happening\n";

	// //media mediaObjec;
	// video videoObject;
	// music musicObject;

	// media *medmusic = &musicObject;
	// media *medvideo = $videoObject;
	Queue mque;


	ifstream musicstream, videostream;
	string mtitle;
	int mlength;
	string ans;
	int num;

	musicstream.open("songs.txt");
	videostream.open("videos.txt");

	srand(time(NULL));

	do{
		num = rand()%2;
		if (num == 0){
			musicstream >> mtitle;
			musicstream >> mlength;
			Length *slength = new Length(mlength);
			music* Music = new music(mtitle, slength);
			mque.Enqueue(Music);

			mque.print();


		}else{

			videostream >> mtitle;
			videostream >> mlength;
			Length *slength = new Length(mlength);
			video* Video = new video(mtitle, slength);

			mque.Enqueue(Video);
			mque.print();


		}

		
		cout << "Do you want to repeat this? (y/n) \n";
		cin >> ans;

	

	}while(ans == "y");
}