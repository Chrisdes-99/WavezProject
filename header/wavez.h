#ifndef __WAVEZ_H__
#define __WAVEZ_H__

#include <string>
#include <vector>
using namespace std;

#include "review.h"
#include "user.h"
#include "artist.h"

class Wavez {
   
 private:
    string title;
    vector<User> userList;
    User currentUser;
    vector<Artist*> artistList;

 public:
    Wavez();
    Wavez(const string &);

    bool loadUsers(const string &);
    bool login();

    void run();

 private:
    void displayMenu() const;
    bool userExists(const string &, const string &) const;
};

#endif
