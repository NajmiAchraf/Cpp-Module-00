#include "Contact.hpp"

std::string Contact::truncate(std::string str, size_t width) const {
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}

void	Contact::print_str(std::string str) const {
	std::cout << "|" ;
	std::cout << std::left << std::setw(10) << truncate(str, 10);
}

void	Contact::print_int(std::int32_t integer) const {
	std::cout << "|" ;
	std::cout << std::left << std::setw(10) << integer;
}

Contact::Contact(int id) {
	std::cout << "Constructor called" << std::endl;
	this->_index = id;
}

Contact::~Contact(void) {
	std::cout << "Destructor called" << std::endl;
}

void	Contact::show_contacts(void) {
	print_int(this->_index);
	print_str(this->_first_name);
	print_str(this->_last_name);
	print_str(this->_nickname);
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void	Contact::contact_info(void) {
	std::cout << "Index			: " << this->_index << std::endl;
	std::cout << "First Name		: " << this->_first_name << std::endl;
	std::cout << "Nickname		: " << this->_nickname << std::endl;
	std::cout << "Last Name		: " << this->_last_name << std::endl;
	std::cout << "Phone Number		: " << this->_phone_number << std::endl;
	std::cout << "Darkest Secret		: " << this->_darkest_secret << std::endl;
}

void	Contact::set_index(std::int32_t index) {
	this->_index = index;
}

void	Contact::set_elements(std::string first_name, std::string nickname, std::string last_name, std::string phone_number, std::string darkest_secret) {
	this->_first_name = first_name;
	this->_nickname = nickname;
	this->_last_name = last_name;
	this->_phone_number = phone_number;
	this->_darkest_secret = darkest_secret;
}