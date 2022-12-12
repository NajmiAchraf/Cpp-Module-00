#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "Constructor called" << std::endl;
	for (int i = 0; i < 8; ++i)
		this->_Contacts[i].set_index(i + 1);
	this->_full = 0;
	this->reset_id();
}

PhoneBook::~PhoneBook() {
	std::cout << "Destructor called" << std::endl;
}

void	PhoneBook::set_full_id() {
	this->_full = 7;
}

void	PhoneBook::reset_id() {
	this->_index = -1;
}

void	PhoneBook::increment() {
	if (this->_full >= 7)
		this->set_full_id();
	this->_full++;
	if (this->_index == 7)
		this->reset_id();
	this->_index++;
}

void	PhoneBook::add() {
	this->increment();

	std::cout << "Enter The First Name : ";
	std::cin >> this->_first_name;
	this->crtl_d();
	std::cout << "Enter The Nickname : ";
	std::cin >> this->_nickname;
	this->crtl_d();
	std::cout << "Enter The Last Name : ";
	std::cin >> this->_last_name;
	this->crtl_d();
	std::cout << "Enter The Phone Number : ";
	std::cin >> this->_phone_number;
	this->crtl_d();
	std::cout << "Enter The Darkest Secret : ";
	std::cin >> this->_darkest_secret;
	this->crtl_d();

	this->_Contacts[this->_index].set_elements(this->_first_name, \
		this->_nickname, this->_last_name, this->_phone_number, \
		this->_darkest_secret);
}

void	PhoneBook::show() {
	std::string input;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << "index     " << "|" << "first name";
	std::cout << "|" << "last name " << "|" << "nickname  " << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->_full; ++i) {
		this->_Contacts[i].show_contacts();
	}

	while (true) {
		std::cout << "Enter the index of the contact that you want to show all his infos (0 to break): ";
		std::cin >> input;
		this->crtl_d();
		if (1 <= (int)atoi(input.c_str()) && (int)atoi(input.c_str()) <= toascii(this->_full))
		{
			this->_Contacts[atoi(input.c_str()) - 1].contact_info();
			break;
		}
		if (input == "0")
			break;
	}
}

void	PhoneBook::crtl_d() {
	if (std::cin.eof())
		exit(0);
}