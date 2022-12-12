#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.Class.hpp"

class PhoneBook {


private:

	std::int32_t	_index;
	std::int32_t	_full;
	std::string		_first_name;
	std::string		_nickname;
	std::string		_last_name;
	std::string		_phone_number;
	std::string		_darkest_secret;
	Contact			_Contacts[8];


public:

	PhoneBook();
	~PhoneBook();

	void	set_full_id();
	void	reset_id();
	void	increment();
	void	add();
	void	show();

};

#endif