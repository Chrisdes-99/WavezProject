#include "../header/album.h"
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
     
  char albumReview[100];

  cout << "Leave a Review for" << this->name <<endl;
  
  std::cin.getline(albumReview,100);
 
  Review album(author,name,review,rating);

  addReview.push_back(album);

  cout<< "Review for" << this-> name << "added!"<<endl;

}

int Album::getRating(){
	return rating;
}

