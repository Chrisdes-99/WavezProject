#include "../header/UsernameManager.h"

UsernameManager::UsernameManager() {
    this->current_user = "";

}

UsernameManager::UsernameManager(const string& user, vector<string>& uList) {
    this->current_user = user;
    this->userList = uList;

}

int UsernameManager::userLogin() {
    for (unsigned i = 0; i < userList.size(); ++i) {
        if (current_user == userList.at(i)) {
            return i;
        }    
    }

    return 0;
}

vector<string> UsernameManager::userAdd(){

    userList.push_back(this->current_user);
    return this->userList;

}

vector<string> UsernameManager::userRemove(){
    
    for (unsigned i = 0; i < userList.size(); ++i) {
        if (current_user == userList.at(i)) {
            userList.erase(userList.begin() + i);
        }
    }
    return this->userList;

}