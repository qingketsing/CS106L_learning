/*
Date:2025.4.14 UTC+8 23:22
Auther:Qingke
*/


#include <iostream>  // for cin,cout
#include <sstream>   // for stringstream
#include <iomanip>   // for manipulators
#include <utility>   // for pair/tuple
#include <vector>  
#include <stdexcept> 
using std::ostringstream, std::istringstream, std::istream, std::ostream;
using std::cout, std::cin, std::endl, std::flush, std::string;
using std::left, std::setw, std::setfill;
using std::make_pair, std::make_tuple, std::get;
using std::vector;

int stringToInteger(const string &s);
void stringToIntegerTest();

int main(){
    stringToIntegerTest();
    return 0;
}

int stringToInteger(const string &s){
    istringstream iss(s);
    int result;
    iss >> result;
    return result;
}

void stringToIntegerTest(){
    while(true){
        cout << "Enter an integer :" ;
        string s;
        if(!getline(cin,s)) throw std::domain_error("getline error");
        cout << "Your type is :" << s << '\n';
        int result = stringToInteger(s);
        cout << "The integer is :" << result << '\n';
        
    }
    return ;
}