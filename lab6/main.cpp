
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
	string title;
	string length;

	Media media_object;
	Video video_object;
	Song song_object;

	QueType mediaque;

	ifstream song_info, video_info;

	song_info.open("songs.txt");
	video_info.open("vieos.txt");

	while (! song_info.eof())
	{
		// getline(song_info >> title);
		// cout << song_info;
		// while ((song_info >> title) && (song_info >> length))
		// {
		// 	media_object.Initialize(title, length);
		// 	cout << title << endl;
		// 	cout << length << endl;

		// }
	}

	while (! video_info.eof())
	{
		// while ((video_info >> title) && (video_info >> length))
		// {
		// 	media_object.Initialize(title, length);
		// }
	}

	return 0;


}