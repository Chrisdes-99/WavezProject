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

  std::string name;

  int rating;

  cout<<"Enter the Name of the Album You'd Like to Review." <<endl;

  cin >> name;

  cout<<"Enter A Rating For"<< name << endl;

  cin >>rating;

  cout << "Leave a Review for" << name <<endl;
  
  std::cin.getline(albumReview,100);
 
  Review* album = new Review(author,name,albumReview,rating);

  albumList.push_back(album);

  cout<< "Review for" << name << "added!"<<endl;

}

int Album::getRating(){
	return rating;
}

