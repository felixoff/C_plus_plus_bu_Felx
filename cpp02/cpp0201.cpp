#include<iostream>
# include <cmath>

class Fixed
{
    private:
        int fix;
        static const int frac = 8;
    public:
        Fixed();
        Fixed(int integer);
        Fixed(float flo);

        Fixed(const Fixed &other);
        virtual ~Fixed();
        Fixed &operator =(const Fixed &other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const; 
        int toInt( void ) const;
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

int main( void )
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}