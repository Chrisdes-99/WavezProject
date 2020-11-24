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
}

virtual void Artist::addReview(){
	return;
}
