#include "Contact.Class.hpp"

std::string truncate(std::string str, size_t width)
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}

void	print_str(std::string str) {
	std::cout << "|" ;
	std::cout << std::left << std::setw(10) << truncate(str, 10);
}

void	print_int(std::int32_t integer) {
	std::cout << "|" ;
	std::cout << std::left << std::setw(10) << integer;
}

Contact::Contact(int id) {
	std::cout << "Constructor called" << std::endl;
	this->index = id;
}

Contact::~Contact(void) {
	std::cout << "Destructor called" << std::endl;
}

void	Contact::show_contacts(void) {
	print_int(this->index);
	print_str(this->first_name);
	print_str(this->last_name);
	print_str(this->nickname);
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void	Contact::contact_info(void) {
	std::cout << "Index			: " << this->index << std::endl;
	std::cout << "First Name		: " << this->first_name << std::endl;
	std::cout << "Nickname		: " << this->nickname << std::endl;
	std::cout << "Last Name		: " << this->last_name << std::endl;
	std::cout << "Phone Number		: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret		: " << this->darkest_secret << std::endl;
}

void	Contact::set_index(std::int32_t index) {
	this->index = index;
}

void	Contact::set_elements(std::string first_name, std::string nickname, std::string last_name, std::string phone_number, std::string darkest_secret) {
	this->first_name = first_name;
	this->nickname = nickname;
	this->last_name = last_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}