#include<iostream>

class Fixed
{
    private:
        int fix;
        static const int frac = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        virtual ~Fixed();
        Fixed &operator =(const Fixed &other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

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

int main( void )
 {
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}