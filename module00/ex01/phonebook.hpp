#ifndef PHONEBOOK_HPP 
#define PHONEBOOK_HPP
#include "contact.hpp"
#include <cctype>
#define TAB_LEN 45

class PhoneBook
{
public:
	Contact users[8];
	int parse1(std:: string name);
	int parse2(std:: string nick);
	int parse3(std:: string number);
	int add(Contact *user);
	int search(Contact users[8]);
};

#endif