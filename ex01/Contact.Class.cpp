#include "Contact.Class.hpp"

Contact::Contact(int id) {
	std::cout << "Constructor called" << std::endl;
	this->index = id;
}

Contact::~Contact(void) {
	std::cout << "Destructor called" << std::endl;
}

void Contact::show_contacts(void) {
	print_int(this->index);
	print_str(this->first_name);
	print_str(this->last_name);
	print_str(this->nickname);
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void Contact::contact_info(void) {
	std::cout << "Index : " << this->index << std::endl;
	std::cout << "First Name : " << this->first_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Last Name : " << this->last_name << std::endl;
	std::cout << "Phone Number : " << this->phone_number << std::endl;
	std::cout << "Darkest Secret : " << this->darkest_secret << std::endl;
}
