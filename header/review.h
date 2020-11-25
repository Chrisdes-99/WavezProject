#ifndef __REVIEW_H__
#define __REVIEW_H__
#include <string>

using namespace std;

class Review {
 private:
	string name;
	int rating;
	string author;
	string body;

 public:

	// default constructor
	Review();
	// Parameterized constructor; 
	Review(const string &athr, const string &body, const string &nme, const int &rat);
	
	/* Displays the Review using the following format:
	 *
	 * Name:
	 * Rating: /5
	 * Posted By: 
	 * Review: 
	 *
	 */
	virtual void display() const;	
#endif
};