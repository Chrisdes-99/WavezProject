#include <iostream>
#include <fstream>
using namespace std;
#include "Wavez.h"
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
        display();
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
            addReview();
        }
        else if ((cont == "Q") || (cont == "q")){
            cout << "Bye!" << endl;
            ++loop;
        }
    }
}

void Wavez::display() const{
    cout << "Menu" << endl;
    cout << "- Display Reviews (\'D\' or \'d\')" << endl;
    cout << "- Add New Review (\'N\' or \'n\')" << endl;
    cout << "- Quit (\'Q\' or \'q\')" << endl;
}

void Wavez::addReview(){
    string subject;
    string body;
    string author = name;
    cout << "Enter Subject: ";
    cin.ignore();
    getline(cin, subject);
    cout << endl;
    cout << "Enter Body: ";
    getline(cin, body);
    cout << endl;
    Review newRev(author, subject, body);
    reviewList.push_back(newRev);
    cout << "Review Recorded!" << endl;
    cout << endl;
}
