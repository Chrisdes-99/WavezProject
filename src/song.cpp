#include "../header/song.h"
using namespace std;

Song::Song(){}

Song::Song(string nam, int rat){
	name = nam;
	rating = rat;
}

void Song::addReview(){

  char songReview[100];
 
  cout<<"Leave A Review"<<endl;

  std::cin.getline(songReview,100);

  Review* song = new Review(author,this->name,songReview,this->rating);

  songList.push_back(song);

  cout<< "Review for " << this->name << "added!"<< endl;

}
