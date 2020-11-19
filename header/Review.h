#ifndef __REVIEW_H__
#define __REVIEW_H__
#include <string>

using namespace std;

class Review {
 private:
	string author;
	string subject;
	string body;

 public:

	// default constructor
	Review();
	// Parameterized constructor; 
	Review(const string &athr, 
	     const string &sbjct, 
	     const string &body);
	
	/* Displays the Review using the following format:
	 *
	 * subject
	 * from author: body
	 */
	void display() const;	
#endif
};
