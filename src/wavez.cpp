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
    cout << "Welcome to Wavez" << endl;
    bool cont = true;
    while (cont){
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> currentUser;
        cout << endl;
        if (currentUser == "Q" || currentUser == "q"){
            cout << "Bye!" << endl;
            return false;
        }
        cout << "Enter your password: ";
        cin >> currentPassword;
        cout << endl;
        User inputUser(currentUser, currentPassword);
        //Iterate through vector
        int foundUser = 0;
        for (unsigned int i = 0; i < userList.size(); ++i){
            if (userList.at(i).check(currentUser, currentPassword)){
                ++foundUser;
            }
        }
        
        if (foundUser > 0){
            cout << "Welcome back " << inputUser.getUsername() << "!" << endl;
            name = inputUser.getUsername();
            cout << endl;
            cont = false;
        }
        else{
            cout << "Invalid Username or Password!" << endl;
            cout << endl;
        }
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
		bool foundArtist = false;
                for (unsigned int i = 0; i < artistList.size(); ++i){
              		if(artistList.at(i)->Name == artistName){ //make name getter  function
				foundArtist = true;
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
				//call display on artist pointer on song vector of found artist (loop)
			}
			else if (displayChoid == "A"){
				//call display on artist pointer on album vector of found artist (loop)
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


//Make addReview a virtual function in review.cpp, and make artist, album, and song have their own instances of it. Each of those objs should have a vector of that same obj to handle multiple
//reviews for one obj.
void Wavez::addReview(){
    string reviewName;
    string body;
    int rating;
    string author = name;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, reviewName);
    cout << endl;
    cout << "Enter rating: ";
    cin >> rating;
    cout << endl;
    cout << "Enter Review: ";
    cin.ignore();
    getline(cin, body);
    cout << endl;
    Review newRev(author, body, reviewName, rating);
    reviewList.push_back(newRev);
    cout << "Review Recorded!" << endl;
    cout << endl;
}
