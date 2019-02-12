#include <iostream>
#include <string>
#include <cstdlib>

int toint(std::string s) //The conversion function
{
    return atoi(s.c_str());
}

int main()
{
    std::string str = "12345";
    int intx = toint(str); //Convert str to an integer
    str[0] = 9;
    int intx_1 = toint(str); //Convert str to an integer
    std::cout << "The string is now an int: " << intx_1 << std::endl; //output it to the screen
    return 0;
}
