#include "PhoneBook.Class.hpp"

PhoneBook::PhoneBook() {
	std::cout << "Constructor called" << std::endl;
	for (int i = 0; i < 8; ++i)
		Contacts[i].index = i + 1;
	this->full = 0;
	this->reset_id();
}

PhoneBook::~PhoneBook() {
	std::cout << "Destructor called" << std::endl;
}

void	PhoneBook::set_full_id() {
	this->full = 7;
}

void	PhoneBook::reset_id() {
	this->index = -1;
}

void	PhoneBook::increment() {
	if (this->full >= 7)
		this->set_full_id();
	this->full++;
	if (this->index == 7)
		this->reset_id();
	this->index++;
}

void	PhoneBook::add() {
	this->increment();

	std::cout << "Enter The First Name : ";
	std::cin >> this->first_name;
	std::cout << "Enter The Nickname : ";
	std::cin >> this->nickname;
	std::cout << "Enter The Last Name : ";
	std::cin >> this->last_name;
	std::cout << "Enter The Phone Number : ";
	std::cin >> this->phone_number;
	std::cout << "Enter The Darkest Secret : ";
	std::cin >> this->darkest_secret;

	Contacts[this->index].first_name = this->first_name;
	Contacts[this->index].nickname = this->nickname;
	Contacts[this->index].last_name = this->last_name;
	Contacts[this->index].phone_number = this->phone_number;
	Contacts[this->index].darkest_secret = this->darkest_secret;
}

void	PhoneBook::show() {
	std::string input;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << "index     " << "|" << "first name";
	std::cout << "|" << "last name " << "|" << "nickname  " << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->full; ++i) {
		Contacts[i].show_contacts();
	}

	while (true) {
		std::cout << "Enter the index of the contact that you want to show all his infos (0 to break): ";
		std::cin >> input;
		if (std::cin.eof())
			exit(0);
		if (1 <= (int)atoi(input.c_str()) && (int)atoi(input.c_str()) <= toascii(this->full))
		{
			Contacts[atoi(input.c_str()) - 1].contact_info();
			break;
		}
		if (input == "0")
			break;
	}
}
