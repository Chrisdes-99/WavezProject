#include "../header/wavez.h"

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
   //===================PROGRAM INITIALIZATION===================
   Wavez prog("Wavez Program");

   //===================REVIEWS READ===================
   string reviewFile;
   cout << "Please enter the name of the review file" << endl;
   cin >> reviewFile;
   if (!prog.loadReviews(reviewFile)) {
      cout << "Error loading reviews from " << reviewFile << ", exiting." << endl;
      return 1;
   }

   //===================LOGIN READ===================
   string userfile; // = argv[1];
   cout << "User file?" << endl;
   cin >> userfile;
   cout << endl;
   string passfile; // = argv[2];
   cout << "Password file?" << endl;
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
   prog.offloadLogin(userfile, passfile);

   return 0;
}
