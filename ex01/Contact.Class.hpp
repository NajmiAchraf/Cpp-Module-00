#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {


private:

	std::int32_t	_index;
	std::string		_first_name;
	std::string		_nickname;
	std::string		_last_name;
	std::string		_phone_number;
	std::string		_darkest_secret;

	std::string truncate(std::string str, size_t width) const;

	void	print_str(std::string str) const;
	void	print_int(std::int32_t integer) const;


public:

	Contact(int id = -1);
	~Contact(void);

	void	show_contacts(void);
	void	contact_info(void);

	void	set_index(std::int32_t index);
	void	set_elements(std::string first_name, std::string nickname, std::string last_name, std::string phone_number, std::string darkest_secret);

};

#endif