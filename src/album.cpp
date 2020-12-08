#include "../header/album.h"
#include <iostream>
using namespace std;

Album::Album(){
	name = "";
	rating = 0;
}

Album::Album(string nam, int rat){
	name = nam;
	rating = rat;
}

void Album::addReview(){
     
  char album_review[100];

  cout << "Leave a Review" <<endl;
  
  std::cin.getline(album_review,100);
 
  //Review* album = new Review(author,this->name,album_review,this->rating);

  Review* album = new Review(this->name, album_review, this->rating);

  //albumList.push_back(album);
  albumReview.push_back(album);

  cout<< "Review for" << this->name << "added!"<< endl;

}

string Album::getName() {
    return this->name;
}

int Album::getRating(){
	return this->rating;
}

vector<Review*> Album::getAlbumReview(){
	return albumReview;
}

