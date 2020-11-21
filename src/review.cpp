#include <iostream>
using namespace std;
#include "../header/review.h"

// default constructor
Review::Review(){
    author = "";
    name = "";
    body = "Nothing to display!";
    rating = -1;
}

Review::Review(const string &athr, const string &body, const string &nme, const int &rat){
    author = athr;
    name = nme;
    rating = rat;
    this->body = body;
}

void Review::display() const{
    cout << "Name: " << name << endl;
    cout << "Rating: " << rating << "/5" << endl;
    cout << "Posted By " << this->author << ": " << this->body;
}



