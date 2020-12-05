#include <iostream>
#include <fstream>
using namespace std;
#include "../header/wavez.h"
#include "artist.cpp"
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
            if (artistList.size() == 0){
                cout << "Nothing to Display." << endl;
                cout << endl;
            }
            else{
		string artistName;
		cout << "Which artist would you like to see reviews for?" << endl;
		cin.ignore();
		getline(cin,artistName);
		cout << endl;
		Artist* selectedArtist = nullptr;
		bool foundArtist = false;
                for (unsigned int i = 0; i < artistList.size(); ++i){
              		if(artistList.at(i)->getName() == artistName){
				foundArtist = true;
				selectedArtist = artistList.at(i);
			}
	    	}
		
		if (!foundArtist){
			cout << "Artist does not exist in Wavez." << endl;
		}
		else{
			string displayChoice;	
			cout << "Do you want to see Song (S) or Album (A) reviews for this artist?" << endl;
			cin >> displayChoice;
			if (displayChoice == "S"){
				selectedArtist->displaySongs();
			}
			else if (displayChoice == "A"){
				selectedArtist->displayAlbums();
			}
			else{
				cout << "Invalid entry" << endl;
			}
		}
	    }
        }



        else if ((cont == "N") || (cont == "n")){
	    cout << "Artist(1); Album(2); Song(3)" << endl;
	    int choice;
	    cin >>choice;
	
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

