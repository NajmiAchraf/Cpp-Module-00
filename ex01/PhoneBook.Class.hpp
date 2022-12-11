#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.Class.hpp"

class PhoneBook {

private:
	std::int32_t	index;
	std::int32_t	full;
	std::string		first_name;
	std::string		nickname;
	std::string		last_name;
	std::string		phone_number;
	std::string		darkest_secret;
	Contact			Contacts[8];

public:

	PhoneBook();
	~PhoneBook();
	void	set_full_id();
	void	reset_id();
	void	increment();
	void	add();
	void	show ();
};

#endif