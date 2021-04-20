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

std::ostream &operator <<(std::ostream &output, Fixed const &other);