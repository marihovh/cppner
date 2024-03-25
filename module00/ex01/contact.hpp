#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
private:
	std::string		first_name;
	std::string		last_name;
	std::string 	nickname;
	std::string		number;
	std::string		secret;
public:
	void set_fn(std::string nm) {first_name = nm;}
	std::string get_fn() {return first_name;}
	void set_ln(std::string nm) {last_name = nm;}
	std::string get_ln() {return last_name;}
	void set_nick(std::string nick) {nickname = nick;}
	std::string get_nick() {return nickname;}
	void set_number(std::string nmb) {number = nmb;}
	std::string get_number() {return number;}
	void set_secret(std::string sct) {secret = sct;}	
	std::string get_secret() {return secret;}
};

#endif 