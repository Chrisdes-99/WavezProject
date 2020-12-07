#ifndef __ALBUM_H__
#define __ALBUM_H__

#include <string>
#include <vector>

#include "artist.h"
#include "review.h"

class Album:public Artist
{
  private:
	std::vector<Review*>albumReview;
	std::vector<Review*>addReview;
	string name;
	int rating;


  public:
	Album();
	Album(string nam, int rate);
	virtual void addReview();
	vector<Review*> getAlbumReview();
	int getRating();

};






#endif
