#ifndef __USERNAMEMANAGER_H__
#define __USERNAMEMANAGER_H__

#include <string>
/* PURPOSE
-Interacts with usernames.txt
-Usernameverify()
-UsernameAdd()
-UsernameRemove()
-Syncs with index in usernames.txt with index in passwords.txt

*/

class UsernameManager { 
 private:
    string userName;

 public:
   UsernameManager();
   //pass by ref here to save mem, no new copy
   UsernameManager(const string& );
   


}

#endif //__USERNAMEMANAGER_H__