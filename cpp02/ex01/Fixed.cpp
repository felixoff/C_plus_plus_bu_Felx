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

Fixed::Fixed(int integer)
{
    std::cout << "Integer constructor called" << std::endl;
    this->fix = integer << this->frac;
}

Fixed::Fixed(float flo)
{
    std::cout << "Float constructor called" << std::endl;
    this->fix = roundf(flo * (float)(1 << this->frac));
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

std::ostream &operator <<(std::ostream &output, Fixed const &other)
{
    output << other.toFloat();
    return output;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "SetRawBits member function called" << std::endl;
    this->fix = raw;
}

int Fixed::getRawBits(void) const
{
    return this->fix;
}

float Fixed::toFloat(void) const
{
    return (float)this->fix/(float)(1<< this->frac);
}

int Fixed::toInt(void) const
{
    return this->fix >> this->frac;
}