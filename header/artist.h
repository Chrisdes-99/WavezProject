#ifndef __ARTIST_H__
#define __ARTIST_H__

#include "review.h"
#include <string>
#include <vector>

class Song;
class Album;

class Artist{
 protected:
    std::string Name;
    vector<Song*>songList;
    vector<Album*>albumList;
    int rating;

 public:
    Artist();
    Artist(string nam);    
    std::string getName();
    void setRating(); //Calculates rating average based on the artist's albums ratings
    void displaySongs();
    void displayAlbums();
    virtual void addReview();
    vector<Song*> getSongVector();
    vector<Album*> getAlbumVector();
};


#endif

