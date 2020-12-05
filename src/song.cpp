#include "../header/song.h"
using namespace std;

Song::Song(){
	name = "";
	rating = 0;
}

Song::Song(string nam, int rat){
	name = nam;
	rating = rat;
}

void Song::addReview(){

  char songReview[100];

  cout<<"Leave A Review For" << this->name <<end;

  std::cin.getline(songReview,100);

  Review song(author, name, songReview, rating);

  songList.push_back(name);

  addReview.push_back(song);

  cout<< "Review for" << this-> name << "added by" << this->author <<endl;

}
