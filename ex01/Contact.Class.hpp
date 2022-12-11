#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>
# include <iomanip>

std::string truncate(std::string str, size_t width);
void	print_str(std::string str);
void	print_int(std::int32_t integer);

class Contact {

public:
	std::int32_t index;
	std::string first_name;
	std::string nickname;
	std::string last_name;
	std::string phone_number;
	std::string darkest_secret;

	Contact(int id = -1);
	~Contact(void);
	void	show_contacts(void);
	void	contact_info(void);
};

#endif