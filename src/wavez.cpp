#include <iostream>
#include <fstream>
using namespace std;
#include "../header/wavez.h"
string name;

Wavez::Wavez(){
    title = "No Title";
    User def();
}

Wavez::Wavez(const string &ttle){
    title = ttle;
    User def();
}

bool Wavez::loadUsers(const string &inputFile){
    ifstream fin (inputFile);
    if (!fin){
        return false;
    }
    else{
        string currUser;
        string currPass;
 
        while (fin >> currUser){
            fin >> currPass;
            User tempUser(currUser, currPass);
            userList.push_back(tempUser);
        }
        userList.pop_back();
        return true;
    }
}



bool Wavez::login(){
    string currentUser;
    string currentPassword;
    int userAction(0);
    
    cout << "Welcome to Wavez" << endl;
    while (true) {
        cout << "Please choose an option by entering the corresponding number:\n" <<
        "(1) Login" << endl <<
        "(2) Register an Account" << endl <<
        "(3) Deactivate an Account" << endl <<
        "(0) Quit" << endl;
        cin >> userAction;

        if (userAction == 1) {
            cout << "Please enter your username!\n";
            getline(cin, currentUser);
            cout << endl;
            cout << "Now please enter your password!\n";
            getline(cin, currentPassword);
            cout << endl;

            User userLogin(currentUser, currentPassword);
        }
        else if (userAction == 2) {
            cout << "Please create your username!\n";
            getline(cin, currentUser);
            cout << endl;
            cout << "Please enter a password for " << currentUser << endl;
            getline(cin, currentPassword);
            cout << endl;

        }
        else if (userAction == 3) {

        }
        else if (userAction == 0) {

        }
        else {
            cout << "Incorrect Option, Please try again" << endl;
        }

        break;
    }
    
    return true;
}


void Wavez::run(){
    string cont;
    int loop = 0;
    while (loop == 0){
        displayMenu();
        cout << "Choose an action: ";
        cin >> cont;
        cout << endl;
        if ((cont == "D") || (cont == "d")){
            if (reviewList.size() == 0){
                cout << "Nothing to Display." << endl;
                cout << endl;
            }
            else{
                for (unsigned int i = 0; i < reviewList.size(); ++i){
                    cout << "---------------------------------------------------------" << endl;
                    cout << "Review #" << (i + 1) << ": ";
                    reviewList.at(i).display();
                    cout << endl;
                }
                cout << "---------------------------------------------------------" << endl;
                cout << endl;
            }
        }
        else if ((cont == "N") || (cont == "n")){
	    cout << "Artist(1); Album(2); Song(3)" << endl;
	    int choice;
	    cin >>choice;
	//Make it so that each option creates an instance of that object and calls that obj's addReview function.
	//Before creating new obj, make sure to search if it already exists, if so just add the review to a vector within that obj
	    if (choice == 1){
	    	//implement artist
	    	addReview();
	    }
	    else if (choice == 2){
		//implement album
		addReview();
	    }
	    else if (choice == 3){
		//implement song
		addReview();
	    }
	    else{
		cout << "Not a valid input. Try again." << endl;
		//implement loop so it tries again
		addReview();
	    }
        }
	else if ((cont == "S") || (cont == "s")){
		cout << "Implement search() function" << endl;
	}
        else if ((cont == "Q") || (cont == "q")){
            cout << "Bye!" << endl;
            ++loop;
        }
    }
}

void Wavez::displayMenu() const{
    cout << "Menu" << endl;
    cout << "- Display All Reviews (\'D\' or \'d\')" << endl;
    cout << "- Add New Review (\'N\' or \'n\')" << endl;
    cout << "- Search (\'S\' or \'s\')" << endl;
    cout << "- Quit (\'Q\' or \'q\')" << endl;
}
