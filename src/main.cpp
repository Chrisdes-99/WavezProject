#include "../header/wavez.h"

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
   //===================PROGRAM INITIALIZATION===================
   Wavez prog("Wavez Program");

   //===================REVIEWS READ===================
   if (!prog.loadReviews()) {
      cout << "Error loading reviews from " << ", exiting." << endl;
      return 1;
   }

   //===================LOGIN READ===================
   string userfile; // = argv[1];
   cout << "User file?" << endl;
   //cin.ignore();
   cin >> userfile;
   cout << endl;
   string passfile;; // = argv[2];
   cout << "Password file?" << endl;
   //cin.ignore();
   cin >> passfile;
   cout << endl;

   if (!prog.loadLogin(userfile, passfile)) {
      cout << "Error loading users from file " << userfile << endl;
      return 1;
   }

   if (!prog.login()) {
      cout << "Login unsuccessful, now exiting the program" << endl;
      return 1;
   }

   //===================PROGRAM RUN===================
   prog.run();


   //===================SAVE LOGIN INFO TO FILE===================
   //prog.offloadLogin(userfile, passfile);

   return 0;
}
