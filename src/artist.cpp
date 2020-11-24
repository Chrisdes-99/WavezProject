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
	return;
}

virtual void Artist::addReview(){
	return;
}
