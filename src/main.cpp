#include "../header/wavez.h"

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
   //===================PROGRAM INITIALIZATION===================
   Wavez prog("Wavez Program");

   //===================REVIEWS READ===================
   prog.loadReviews();

   //===================LOGIN READ===================
   string userfile; // = argv[1];
   string passfile;
   cout << "Load default(1) or custom credential database?(2)" << endl;
   int userAction(0);
   cin >> userAction;
   if (userAction == 1) {
      userfile = "usernames.txt";
      passfile = "passwords.txt";
   }
   else if (userAction == 2) {
      cout << "Please enter the username's filename: " << endl;
      cin >> userfile;
      cout << endl;

      cout << "Please enter the password's filename: " << endl;
      cin >> passfile;
      cout << endl;
   }
   else {
      cout << "Incorrect Option, ending program" << endl;
      return 1;
   }

   if (!prog.loadLogin(userfile, passfile)) {
      cout << "Error loading users from file " << userfile << endl;
      return 1;
   }

   if (!prog.login()) {
      cout << "Login unsuccessful, now exiting the program" << endl;
      prog.offloadLogin(userfile, passfile);
      return 1;
   }
   

   //===================PROGRAM RUN===================
   prog.run();


   //===================SAVE LOGIN INFO TO FILE===================
   prog.offloadLogin(userfile, passfile);

   return 0;
}
