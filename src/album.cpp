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

void Album::addReview(){}

int Album::getRating(){
	return rating;
}

vector<Review*> Album::getAlbumReview(){
	return albumReview;
}

