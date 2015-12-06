
#include "QueType.h"
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
	srand(time(NULL));
	
	string title, length;


	QueType mediaque;


	ifstream song_info, video_info;

	song_info.open("songs.txt");
	video_info.open("vieos.txt");

	char response;
	int random;

	do{
		random = rand()%2;
		if (random == 0){
			song_info >> title;
			song_info >> length;
			Song song;
			Media * mediaItem = &song;
			mediaItem -> Initialize(title, length);
			mediaque.Enqueue(*mediaItem);
			mediaque.print();


		}else{

			video_info >> title;
			video_info >> length;
			Video video;

			Media * mediaItem = &video;
			mediaItem -> Initialize(title, length);

			mediaque.Enqueue(*mediaItem);
			mediaque.print();


		}

		cout << "\n\n";
		cout << "Do you want to repeat this? (y/n) \n";
		cin >> response;

	

	}while(response == 'y');
	

	return 0;


}