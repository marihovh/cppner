#include "phonebook.hpp"
#include "contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

int PhoneBook::parse1(std:: string name)
{
	int i = -1;
	while (name[++i])
		if (!std::isalpha(name[i]) && name[i] != '\n')
			return (1);
	return (0);
}

int PhoneBook::parse2(std:: string nick)
{
	int i = -1;
	while (nick[++i])
		if (!std::isalpha(nick[i]) && !std::isdigit(nick[i]) && nick[i] != '\n')
			return (1);
	return (0);
}

int PhoneBook::parse3(std:: string number)
{
	int i = -1;
	while (number[++i])
		if (!std::isdigit(number[i]) && number[i] != '+')
			return (1);
	return (0);

}

int esim(std::string tox, std::string *input)
{
	std:: cout << "ERROR: "<< tox << std:: endl;
	std:: cout << tox << std:: endl;
	std:: getline(std::cin, *input);
	if (std::cin.eof())
		return 1;
	return 0;
}

int PhoneBook::add(Contact *user)
{
	std::string input;
	std:: cout << "First Name" << std:: endl;
	std:: getline(std::cin, input);
	if (std::cin.eof())
		return (1);
	while (!input[0] || parse1(input))
		if (esim("First Name", &input))
			return 1;
	user->set_fn(input);
	std:: cout << "Last Name" << std:: endl;
	std:: getline(std::cin, input);
	if (std::cin.eof())
			return (1);
	while (!input[0] || parse1(input))
		if(esim("Last Name", &input))
			return 1;
	user->set_ln(input);
	std:: cout << "Nickname" << std:: endl;
	std:: getline(std::cin, input);
	if (std::cin.eof())
			return (1);
	while (!input[0] || parse2(input))
		if(esim("Nickname", &input))
			return 1;
	user->set_nick(input);
	std:: cout << "Number" << std:: endl;
	std:: getline(std::cin, input);
	if (std::cin.eof())
			return (1);
	while (!input[0] || parse3(input))
		if (esim("Number", &input))
			return 1;
	user->set_number(input);
	std:: cout << "!!!SECRET!!!" << std:: endl;
	std:: getline(std::cin, input);
	user->set_secret(input);
	if (std::cin.eof())
			return (1);
	std:: cout << "I saved the contact" << std:: endl;
	return (0);
}

void only_ten(std::string str)
{
	if (str.length() >= 10)
		std::cout << std::right << std::setw(9) << str.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << str << "|";
}

int PhoneBook::search(Contact users[8])
{
	std::string command;
	int index = -1;
	int i = -1;
	while (++i < TAB_LEN)
		std::cout << "_";
	i = -1;
	std::cout << std::endl << "|" << std::right << std::setw(10) << "Id" << "|";
	std::cout << std::right << std::setw(10) << "first name" << "|";
	std::cout << std::right << std::setw(10) << "last name" << "|";
	std::cout << std::right << std::setw(10) << "nickname" << "|" << std::endl;
	while (users[++i].get_fn()[0] != '\0')
	{
		std::cout << "|" << std::right << std::setw(10) << i << "|";
		only_ten(users[i].get_fn());
		only_ten(users[i].get_ln());
		only_ten(users[i].get_nick());
		std::cout << std::endl;
	}
	std:: getline(std::cin, command);
	if (std::cin.eof())
			return (1);
	const char *nb = &command[0];
	if (!std::isdigit(command[0]) || command.length() > 1)
		std::cout << "Invalid index" << std::endl;
	else
		index = std::atoi(nb);
	if (index >= 0 && index <= i - 1)
	{
		std::cout << users[index].get_fn() << std::endl;
		std::cout << users[index].get_ln() << std::endl;
		std::cout << users[index].get_nick() << std::endl;
		std::cout << users[index].get_number() << std::endl;
		std::cout << users[index].get_secret() << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
	return (0);
}

int main()
{
	PhoneBook book;
	int i = -1;

	std::string command;
	std::getline(std::cin, command);
	if (std::cin.eof())
			return (1);
	while (command.compare("EXIT"))
	{
		if (!command.compare("ADD"))
		{
			if (++i != 0 && i % 8 == 0)
				i = 0;
			if (book.add(&book.users[i]))
				return (1);
		}
		else if (!command.compare("SEARCH"))
		{
			if (book.search(book.users))
				return (1);
		}
		else if (!command.compare("EXIT"))
			std::cout << "exit" << std::endl;
		else
			std::cout << "Invalid command" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (1);
	}
	return (0);
}
