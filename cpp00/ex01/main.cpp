#include "phonebook.hpp"

void set_info(Contact *str)
{
    std::string data;
    std::string mas[] = {"first name", "last name", "nick name", "login", "postal address",
    "email adress", "phone number", "birthday date", "favorite meal", "underwear color", "darkest secret"};
    int     i;

    i = -1;
    std::cout << "| Добавить новый контакт" << std::endl;
    while (++i <= 10)
    {
            std::cout << i << ") " << mas[i] << ": ";
            std::getline(std::cin, data);
            (*str).set_data(i, data);
    }
    std::cout << "| Контакт добавлен" << std::endl;
}

void get_info(Contact book[8], int index)
{
    int     i;
    int     j;
    std::string str;
    std::string	arr[] = {"first name", "last name", "nick name", "login",
     "postal address", "email adress", "phone number", "birthday date",
      "favorite meal", "underwear color", "darkest secret"};
    if (index != 0)
    {
        i = -1;
        std::cout << "|" << std::setfill('-') << std::setw(52) << "|" << std::endl;
        std::cout << "| ";
        std::cout << std::setfill(' ') << std::setw(16) << "Индекс" << " | ";
		std::cout << std::setfill(' ') << std::setw(17) << "Фамилия" << " | ";
		std::cout << std::setfill(' ') << std::setw(13) << "Имя" << " | ";
		std::cout << std::setfill(' ') << std::setw(13) << "Ник" << " |" << std::endl;
        while (++i < index)
        {
            j = -1;
           	std::cout << "| " << std::setfill(' ') << std::setw(10) << i << " | ";
            while (++j < 3)
            {
                str = book[i].get_data(j);
                if (str.size() > 10)
                {
                    str.resize(9);
                    str += ".";
                }
				std::cout << std::setw(10) << str << " | ";
            }
            std::cout << std::endl;
        }
        std::cout << "|" << std::setfill('-') << std::setw(52) << "|" << std::endl;
		std::cout << "| Введите индекс: ";
        if ((std::cin >> i).good() && i >= 0 && i<= index - 1)
        {
            j = -1;
            while (++j <= 10)
                std::cout << "| - " << arr[j] << ": " << book[i].get_data(j) << std::endl;
        }
        else
        {
            std::cin.clear();
            std::cout << "| Неверный индекс" << std::cout;
        }
        std::cin.ignore(10000, '\n');
    }
    else std::cout << "Нет пользователей" << std::endl;
}

int     main()
{
    Contact     book[8];
    std::string  str;
    int         i;

    i = 0;
    while (1)
    {
        std::getline(std::cin, str);
            if (str == "ADD")
                if (i < 8)
                    set_info(&book[i++]);
                else
                    std::cout << "Книга переполнена" << std::endl;
            else if (str == "SEARCH")
                get_info(book, i);
            else if (str == "EXIT")
                break ;
            else
                std::cout << "Неизвестная комманда" << std::endl;
    }
    return(0);
}