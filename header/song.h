#ifndef __SONG_H__
#define __SONG_H__

#include "artist.h"
//class Artist;
#include "review.h"

#include <vector>
#include <string>


class Song : public Artist{
  private:
	std::vector<Review*>songReview;
	string name;
	int rating;
  public:
	Song();
	Song(string nam, int rat);
	virtual void addReview();
	vector<Review*> getSongReview();
};




#endif
