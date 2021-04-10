#include<iostream>
#include<fstream>

int main()
{
    int startIndex;
    std::ifstream fin;
    std::ofstream fout;
    std::string fileName;
    std::string s1;
    std::string s2;
    std::string buffer;
    int lenght;

    //if (argc == 4)
//    {
        fileName = "ex0107Test.txt";
        s1 = "hello";
        s2 = "bye";
        lenght = s1.length();
        fin.open(fileName);
        fout.open(fileName + ".replace");
        if (fin.is_open() && fout.is_open())
        {
            while(std::getline(fin,buffer))
            {
                startIndex = 0;
                while ((startIndex = buffer.find(s1,startIndex)) != std::string::npos)
                    buffer.replace(startIndex,lenght,s2);
                fout << buffer;
                fout << "\n";
            }
        }
        fin.close();
        fout.close();
 //   }
    return(0);
}