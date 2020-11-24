#ifndef __PASSWORDMANAGER_H__
#define __PASSWORDMANAGER_H__

#include <string>
/* PURPOSE
-Interacts with passwords.txt
-Passwordsverify()
-PasswordsAdd()
-PasswordsRemove()

*/


class Passwordmanager { 
 private:
    string userPassword;

 public:
   PasswordManager();
   PasswordManager(const string& );

   bool PasswordVerify();
   void PasswordAdd();
   void PasswordRemove();


}

#endif //__PASSWORDMANAGER_H__