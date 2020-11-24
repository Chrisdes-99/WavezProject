#ifndef __SONG_H__
#define __SONG_H__

#include "artist.h"
#include "review.h"

#include <vector>
#include <string>

class Song:public Artist
{
  private:
	Review* std::vector<Review*>songReview;
	string name;
	int rating;
  public:
	Song();
	Song(string nam, int rat);
	void addReview(){};
};




#endif
