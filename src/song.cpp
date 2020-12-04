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

void Song::addReview(){}
