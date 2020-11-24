#ifndef __ARTIST_H__
#define __ARTIST_H__

#include "review.h"

#include <string>
#include <vector>

class Artist
{
 protected:
    std::string Name;
    Song* vector<Review*>songList;
    Album* vector<Review*>albumList;

 public:
    void addRating(); //Calculates rating average based on the artist's albums ratings

    virtual void addReview()= 0;
};


#endif
