#include <iostream>
#include <string>
#include <cctype>
#include <locale> //std::tolower
#include "UnsortedType.h"
#include "single.h"

using namespace std;

int main()
{
	// Setting the maximum size of number of songs in the UnsortedPlaylist array
	int maxnumber_of_songs;
	cout << "Enter the maximum number of songs: ";
	cin >> maxnumber_of_songs;

	// Declaring UnsortedPlaylist
	Single* UnsortedPlaylist = new Single[maxnumber_of_songs];

	// Reading and writing to "FavSongs.txt"
	ifstream read_songs;
	ofstream write_songs;
	ifstream readlines;
	ofstream writelogs;
	
	int number_of_songs; // number of songs in the text file

	read_songs.open("favSongs.txt");
	readlines.open("favSongs.txt");
	//write_songs.open("favSongs.txt");
	writelogs.open("logs.txt");


	if (read_songs.fail())
	{
		writelogs << "There is something wrong." << endl;
	}
	else
	{
		string name; 
		int index = 0;
		while(getline(read_songs, name))
		{
			UnsortedPlaylist[index].name = name;
			cout << name << endl;
			index++;
		}
	}

	read_songs.close();



	//Prompting user to update the array and favSongs.txt
	string response; locale loc;

	do
	{
		cout << "You can add a song, delete song and update the rating of a song." << endl
		 << "Type 'add' to add a song, 'delete' to delete and 'rate' to update the rating of a song'" << endl
		 << "Type 'exit' to end the program." << endl
		 << "What do you want?: ";
		cin >> response;

		if (response == "add")
		{
			string song;
			cout << "Enter the name of a song: ";
			cin >> song;

			//Update UnsortedPlaylist
			number_of_songs++; //to check if it exceeds the number of maxnumber_of_songs in the UnsortedPlaylist


		}
	} while (response != "exit");
	

	return 0;
}