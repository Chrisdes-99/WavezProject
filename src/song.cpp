#include "../header/song.h"
using namespace std;

Song::Song(){}

void Song::addReview(){

  char songReview[100];

  int rating;

  std::string name;

  cout<<"Enter the Name of the Album You'd Like to Review."<<endl;

  cin >> name;

  cout<<"Enter a Rating for" << name << endl;

  cin >> rating;

  cout<<"Leave A Review For"<< name <<endl;

  std::cin.getline(songReview,100);

  Review* song = new Review (author, name, songReview, rating);

  songList.push_back(song);

  cout<< "Review for" << name << "added!" << endl;

}
