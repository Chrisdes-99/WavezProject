#ifndef __ALBUM_H__
#define __ALBUM_H__

#include <string>
#include <vector>

#include "artist.h"
#include "review.h"

class Album:public Artist
{
  private:
	Review* std::vector<Review*>albumReview;
	Review* std::vector<Review*>addReview;
	string name;
	int rating;


  public:
	Album();
	Album(string nam, int rate);
	int getRating();
	void addReview();

};






#endif
