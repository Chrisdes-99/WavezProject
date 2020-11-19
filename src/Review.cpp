#include <iostream>
using namespace std;
#include "../header/Review.h"

// default constructor
Review::Review(){
    author = "";
    subject = "";
    body = "Nothing to display!";
}

Review::Review(const string &athr, const string &sbjct, const string &body){
    author = athr;
    subject = sbjct;
    this->body = body;
}

void Review::display() const{
    cout << this->subject << endl;
    cout << "from " << this->author << ": " << this->body;
}

