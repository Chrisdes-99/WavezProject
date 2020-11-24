#ifndef __USER_H__
#define __USER_H__
#include <string>

using namespace std;
 
class User {
 private:
  string username;
  string password;

 public:
  User();
  User(string, string);
  void userLogin();
  void userAdd();
  void userRemove();
};

#endif //__USER_H__


//Check for duplicate account usernames