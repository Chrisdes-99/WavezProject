#include "../header/wavez.h"
#include "../header/artist.h"
#include "../header/review.h"
#include "../header/song.h"
#include "../header/album.h"

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string name;

Wavez::Wavez(){
    title = "No Title";
    User def();
}

Wavez::Wavez(const string &ttle){
    title = ttle;
    User def();
}

bool Wavez::loadReviews() {
 //FORMAT:
 //
 //
 //
 //   ifstream infs(reviewFile);
 //   if (!infs) {
 //       return false;
 //   }
 //   else {
 //   }
 return true;

}


bool Wavez::loadLogin(const string &userfile, const string &passfile){
    ifstream fin (userfile);
    ifstream fin_2 (passfile);


    if (!fin){
        return false;
    }
    else if (!fin_2) {
        return false;
    }
    else{

        string currUser;
        string currPass;
        while (fin >> currUser) {
            vUsers.push_back(currUser);
            cout << "TESTUSERS: " << currUser << endl;
        }
        while (fin_2 >> currPass) {
            vPass.push_back(currPass);
            cout << "TESTPASS: " << currPass << endl;
        }

        if (vUsers.size() < vPass.size()) {
            cout << "There are less usernames than there are passwords, please fix" << endl;
            return false;
        }

        else if (vUsers.size() > vPass.size()) {
            cout << "There are less passwords than there are usernames, please fix" << endl;
            return false;
        }
/*
        for (unsigned i = 0; i < vUsers.size(); ++i) {
            User tempUser(vUsers.at(i), vPass.at(i));
            userList.push_back(tempUser);
        }
        //Purpose of this ?
        userList.pop_back();
        return true;
*/
    return true;
    }
}



bool Wavez::login(){
    string currentUser;
    string currentPassword;
    int userAction(0);
    
    cout << "Welcome to Wavez" << endl;
    login_menu_start:
    while (true) {
        cout << "Please choose an option by entering the corresponding number:\n" <<
        "(1) Login" << endl <<
        "(2) Register an Account" << endl <<
        "(3) Deactivate an Account" << endl <<
        "(0) Quit" << endl;
        cin >> userAction;

        if (userAction == 1) {
            cout << "Please enter your username!\n";
            cin.ignore();
            getline(cin, currentUser);
            cout << endl;
            cout << "Now please enter your password!\n";
            cin.ignore();
            getline(cin, currentPassword);
            cout << endl;

            User temp_user(currentUser, currentPassword, vUsers, vPass);

            //User temp_user(currentUser, currentPassword, userList);

            if (!temp_user.userLogin()) {
                return false;
            }
            return true;

        }
        else if (userAction == 2) {
            cout << "Please create your username!\n";
            cin.ignore();
            getline(cin, currentUser);
            cout << endl;
            cout << "Please enter a password for " << currentUser << endl;
            cin.ignore();
            getline(cin, currentPassword);
            cout << endl;

            User temp_user(currentUser, currentPassword, vUsers, vPass);
            vUsers = temp_user.userAdd().at(0);
            vPass = temp_user.userAdd().at(1);
            cout << currentUser << "'s Account has been successfully created!" << endl;
            goto login_menu_start;

        }
        else if (userAction == 3) {
            cout << "Please enter the username of the account you wish to delete" << endl;
            cin.ignore();
            getline(cin, currentUser);
            cout << "Please enter the password for " << currentUser << endl;
            cin.ignore();
            getline(cin, currentPassword);
            cout << endl;
            cout << "Are you sure you want to delete this account? (Y/N)" << endl; //please enter the username one more time
            char userChoice;
            cin.ignore();
            cin >> userChoice;
            if (tolower(userChoice) == 'y') {
                User temp_user(currentUser, currentPassword, vUsers, vPass);
                if (!temp_user.userLogin()) {
                    cout << "Invalid credentials, Returning to main menu" << endl;
                    goto login_menu_start;
                }
                else
                {
                    vUsers = temp_user.userRemove().at(0);
                    vPass = temp_user.userAdd().at(1);
                    cout << currentUser << "'s Account has been successfully deleted!" << endl;
                    goto login_menu_start;
                }
                

            }
            else if (tolower(userChoice) == 'n') {
                cout << "Understood, will not delete this account" << endl;
                goto login_menu_start;
            }
            else {
                cout << "Invalid answer, returning to main menu" << endl;
                goto login_menu_start;
            }
        }
        else if (userAction == 0) {
            return false;
        }
        else {
            cout << "Incorrect Option, Please try again" << endl;
        }

        //break;
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
	    	//addReview();
	    }
	    else if (choice == 2){
		//implement album
		    //addReview();
	    }
	    else if (choice == 3){
		//implement song
		    //addReview();
	    }
	    else{
		cout << "Not a valid input. Try again." << endl;
		//implement loop so it tries again
		    //addReview();
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

void Wavez::offloadLogin(const string & userFile, const string & passFile) {
    ofstream ofs(userFile);
    ofs.open(userFile, ofstream::out | ofstream::trunc);

    ofstream ofs_2(passFile);
    ofs.open(passFile, ofstream::out | ofstream::trunc);
    
    for (unsigned i = 0; i < vUsers.size(); ++i) { 
        ofs << vUsers.at(i) << endl;
    }

    for (unsigned i = 0; i < vPass.size(); ++i) {
        ofs_2 << vPass.at(i) << endl;
    }


    ofs.close();
    ofs_2.close();
}
