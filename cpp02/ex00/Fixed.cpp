#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fix = 0;
        std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    this->fix = other.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &other)
{
    this->fix = other.getRawBits();
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "SetRawBits member function called" << std::endl;
    this->fix = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "GetRawBits member function called" << std::endl;
    return this->fix;
}