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
	std::string input;
	this->increment();

	while (true) {
		std::cout << "Enter First Name: ";
		std::getline(std::cin, input);
		this->control_D();
		if (input.empty())
			std::cout << "First Name cannot be empty." << std::endl;
		if (input.length() > 0)
		{
			this->_first_name = input;
			input = "";
			break;
		}
	}
	while (true) {
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, input);
		this->control_D();
		if (input.empty())
			std::cout << "Nickname cannot be empty." << std::endl;
		if (input.length() > 0)
		{
			this->_nickname = input;
			input = "";
			break;
		}
	}
	while (true) {
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, input);
		this->control_D();
		if (input.empty())
			std::cout << "Last Name cannot be empty." << std::endl;
		if (input.length() > 0)
		{
			this->_last_name = input;
			input = "";
			break;
		}
	}
	while (true) {
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, input);
		this->control_D();
		if (input.empty())
			std::cout << "Phone Number cannot be empty." << std::endl;
		if (input.length() > 0)
		{
			this->_phone_number = input;
			input = "";
			break;
		}
	}
	while (true) {
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, input);
		this->control_D();
		if (input.empty())
			std::cout << "Darkest Secret cannot be empty." << std::endl;
		if (input.length() > 0)
		{
			this->_darkest_secret = input;
			input = "";
			break;
		}
	}

	this->_Contacts[this->_index].set_elements(this->_first_name, \
		this->_nickname, this->_last_name, this->_phone_number, \
		this->_darkest_secret);
}

void	PhoneBook::show() {
	std::string input;

	if (this->_full == 0) {
		std::cout << "No contacts to show" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << "index     " << "|" << "first name";
	std::cout << "|" << "last name " << "|" << "nickname  " << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->_full; ++i) {
		this->_Contacts[i].show_contacts();
	}

	while (true) {
		std::cout << "Enter the index of the contact that you want to show all his infos (0 to break): ";
		std::getline(std::cin, input);
		this->control_D();
		if (input.length() < 2 && std::isdigit(input[0]))
		{
			if (std::stoi(input) == 0)
				break;
			if (1 <= std::stoi(input) && std::stoi(input) <= this->_full)
			{
				this->_Contacts[atoi(input.c_str()) - 1].contact_info();
				break;
			}
		}
		if (input.empty())
			std::cout << "Index cannot be empty." << std::endl;
		else
			std::cout << "Invalid index." << std::endl;
	}
}

void	PhoneBook::control_D() {
	if (std::cin.eof())
		exit(0);
}
