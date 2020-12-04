#ifndef __ARTIST_H__
#define __ARTIST_H__

#include "review.h"

#include <string>
#include <vector>

class Artist
{
 protected:
    std::string Name;
    vector<Review*>songList;
    vector<Review*>albumList;
    int rating;

 public:
    Artist();
    Artist(string nam);    

    void setRating(); //Calculates rating average based on the artist's albums ratings

    virtual void addReview()= 0;
};


#endif


