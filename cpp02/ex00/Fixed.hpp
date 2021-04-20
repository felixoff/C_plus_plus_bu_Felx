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