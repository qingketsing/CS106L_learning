/*
Date:2025.4.14 UTC+8 23:22
Auther:Qingke
Content: CS106L lec2 & lec3 first part
*/


#include <iostream>  // for cin,cout
#include <sstream>   // for stringstream
#include <iomanip>   // for manipulators
#include <utility>   // for pair/tuple
#include <vector>  
#include <stdexcept> 
#include <fstream>
using std::ostringstream, std::istringstream, std::istream, std::ostream;
using std::cout, std::cin, std::endl, std::flush, std::string;
using std::left, std::setw, std::setfill;
using std::make_pair, std::make_tuple, std::get;
using std::vector;

int stringToInteger(const string &s);
int getInteger();
void stringToIntegerTest();
void bufferExperiements(ostream& oss);
void badWelcomeProgram();
string promptUserForFile(std::ifstream &stream,string prompt = "",string repromt = "");

int main(){
    getInteger();
    return 0;
}

int stringToInteger(const string &s){
    istringstream iss(s);
    int result;char remain;
    if(!(iss >> result) || (iss >> remain)){
        throw std::domain_error("error");
    }
    return result;
}

int getInteger(){
    while(true){
        string line;
        if(!getline(cin,line)){
            throw std::domain_error("can't get line");
        }
        int result;char trash;
        istringstream iss(line);
        if(iss >> result && !(iss >> trash)) return result;
    }
}

void stringToIntegerTest(){
    while(true){
        cout << "Enter an integer :" ;
        string s;
        if(!getline(cin,s)) throw std::domain_error("getline error");  // getline不跳过换行和空白字符，而是读取他们
        cout << "Your type is :" << s << '\n';
        int result = stringToInteger(s);
        cout << "The integer is :" << result << '\n';
        
    }
    return ;
}

void bufferExperiements(ostream& oss){
    oss << "CS";
    oss << "106";
    oss << "L";
    return ;
}

void badWelcomeProgram(){
    string name; int age;
    string result;
    cin >> name;
    cin >> age;  //缓冲区将会读到空白字符并跳空过所有的空白字符
    cout << name << age; // 但当eof开启时，后面的操作全部都会冻结
    cin >> result;
}

string promptUserForFile(std::ifstream& stream,
                        string prompt = "",
                        string repromt = ""){
    string fname;
    while(true){
        if(!prompt.empty()){
            cout << prompt;
        }
        getline(cin,fname);
        stream.open(fname);
        if(stream){
            return fname;
        }else{
            stream.clear();
            if(!repromt.empty()){
                std::cerr <<repromt;
            }
        }
    }
}