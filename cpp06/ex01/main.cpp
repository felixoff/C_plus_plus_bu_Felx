#include "serialize.hpp"

int main()
{
    Data *data;
    void *stream;
    stream  = serialize();
    data = deserialize(stream);
    std::cout << data->s1<< std::endl << data->digit<< std::endl <<  data->s2 << std::endl;
}