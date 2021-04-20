#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:

	std::string firstname;
	std::string	lastname;
	std::string	nickName;
	std::string	login;
	std::string postalAddr;
	std::string	emailAddr;
	std::string	phone;
	std::string	birthday;
	std::string	favorMeal;
	std::string	underwearColor;
	std::string	darkSecret;

	public:

	Contact();
	~Contact();
	void	set_data(int index, std::string data);
	std::string		get_data(int index);
};

void		set_data(Contact *str);
void		get_data(Contact book[8], int index);

#endif