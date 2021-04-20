#include "phonebook.hpp"

Contact::Contact()
{
    firstname = "";
    lastname = "";
    nickName = "";
    login = "";
    postalAddr = "";
    emailAddr = "";
    phone = "";
    birthday = "";
    favorMeal = "";
    underwearColor = "";
    darkSecret = "";
}

Contact::~Contact()
{
}

void  Contact::set_data(int index, std::string data)
{
    switch (index)
    {
        case 0:
            firstname = data;
            break;
        case 1:
            lastname = data;
            break;
        case 2:
            nickName = data;
            break;
        case 3:
            login = data;
            break;
        case 4:
            postalAddr = data;
            break;
        case 5:
            emailAddr = data;
            break;
        case 6:
            phone = data;
            break;
        case 7:
            birthday = data;
            break;
        case 8:
            favorMeal = data;
            break;
        case 9:
            underwearColor = data;
            break;
        case 10:
            darkSecret = data;
            break;
    }
} 

std::string  Contact::get_data(int index)
{
    switch (index)
    {
        case 0:
            return (firstname);
        case 1:
            return (lastname);
        case 2:
            return (nickName);
        case 3:
            return (login);
        case 4:
            return (postalAddr);
        case 5:
            return (emailAddr);
        case 6:
             return (phone);
        case 7:
             return (birthday);
        case 8:
            return (favorMeal);
        case 9:
            return (underwearColor);
        case 10:
            return (darkSecret);
    }
    return(NULL);
} 


