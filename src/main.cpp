#include <iostream>
#include <string>

using namespace std;

#include "../header/wavez.h"

int main(int argc, char *argv[]) {
    string userfile; // = argv[1];
    cout << "User file?" << endl;
    cin >> userfile;
    cout << endl;
   
   Wavez prog("Wavez Program");
   
   // load users from file
   if (!prog.loadUsers(userfile)) {
      cout << "Error loading users from file " << userfile << endl;
      return 1;
   }
   if (!prog.login()) {
      cout << "Login not successful" << endl;
      return 1;
   }
   prog.run();

   return 0;
}
