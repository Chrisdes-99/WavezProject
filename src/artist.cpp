#include "../header/artist.h"
#include <iostream>
using namespace std;

Artist::Artist(){ //constructor that sets empty name
	Name = "";
}

Artist::Artist(string nam){
	Name = nam;
}

void Artist::setRating(){
        int sum = 0;
        int size = albumList.size();
        for (unsigned int i = 0; i < albumList.size(); ++i){
		sum = sum + albumList.at(i)->getRating();
        }
	this->rating = (sum/size);
	return;
}


string Artist::getName(){
	return Name;
}

vector<Song*> Artist::getSongVector(){
	return songList;
}

vector<Album*> Artist::getAlbumVector(){
	return albumList;
}

virtual void Artist::addReview(){
	return;
}


void Artist::displaySongs(){
	for (unsigned int i = 0; i < songList.size(); ++i){
		cout << "---------------------------------------------------------" << endl;
		vector<Review*> displayVector = songList.at(i)->getSongReview();
		for(unsigned int j = 0; j < displayVector.size(); ++j){
	                cout << "Review for " << displayVector.at(j)->getName() << " #" << (j + 1) << ": ";
	                displayVector.at(j)->display();
			cout << endl;
	
		}
	        cout << "---------------------------------------------------------" << endl;
		cout << endl;
	}
	cout << "---------------------------------------------------------" << endl;

}


void Artist::displayAlbums(){
	for (unsigned int i = 0; i < albumList.size(); ++i){
        	cout << "---------------------------------------------------------" << endl;
                vector<Review*> displayVector = albumList.at(i)->getAlbumReview();
		for(unsigned int j = 0; j < displayVector.size(); ++j){
                cout << "Review for " << displayVector.at(j)->getName() << " #" << (j + 1) << ": ";
                displayVector.at(j)->display();

		}
                cout << endl;
	        cout << "---------------------------------------------------------" << endl;
        }
        cout << "---------------------------------------------------------" << endl;
	

}

