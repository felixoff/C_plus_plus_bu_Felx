#include "serialize.hpp"

void * serialize(void)
{
    char masChar[] = "ABCDE";
//    int masInt = 8;
    char *streamBytes = new char[20] ;
    for (int i = 0; i < 8; i++)
        streamBytes[i] = masChar[rand() % (sizeof(masChar) - 1)];
    *reinterpret_cast<int *>(&streamBytes[8]) = rand() % 10;
 //   &streamBytes[8] = reinterpret_cast<char *>(&masInt);
    for (int i = 12; i < 20; i++)
        streamBytes[i] = masChar[rand() % (sizeof(masChar) - 1)];
//    ss << masStr[rand() % (7 - 1)] << masInt[rand() % sizeof(masInt - 1)]  << masStr[rand() % (7 - 1)];
//    std::string s = ss.str();
 //   std::string *s8 = &s;
 //   std::cout << (void *)s8 << std::endl;
    return((void*)streamBytes);
}
Data * deserialize(void * streamBytes)
{
    Data *data = new Data();
    data->s1.assign(static_cast<char *>(streamBytes),8);
    data->digit = *reinterpret_cast<int *>(static_cast<char *>(streamBytes) + 8);
 //   data->s2.assign(static_cast<char *>(streamBytes) + 12,8);
 //   std::cout << static_cast<char *>(streamBytes)[12]<< std::endl;
    data->s2.assign(&static_cast<char *>(streamBytes)[12],8);
    return(data);
}