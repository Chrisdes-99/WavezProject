#include "../header/song.h"
//#include "../header/artist.h"
#include <iostream>
using namespace std;

Song::Song(){}

Song::Song(string nam, int rat){
	name = nam;
	rating = rat;
}

vector<Review*> Song::getSongReview(){
	return songReview;
}

void Song::addReview(){

     string song_review;
    
     cout<< "Leave A Review" <<endl;

     //cin.clear();
     getline(cin, song_review);

     //Review* song = new Review(author,this->name,song_review,this->rating);
     Review* song = new Review(this->name, song_review, this->rating);

     songReview.push_back(song);

     cout<<"Review for " << this->name <<" added!"<<endl;
}

string Song::getName() {
    return this->name;
}
