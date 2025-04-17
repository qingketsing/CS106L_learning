/*
Date:2025.4.16 UTC+8 9:59
Author:Qingke
Topic:adaptive containers
*/

#include <iostream>
#include <string>
#include <map>
#include <sstream>

using std::string ;using std::cin;
using std::cout; using std::endl;

string GetLine(){
    string response;
    std::getline(cin,response);
    return response;
}

int main(){
    std::map<string ,int> frequencymap;
    cout << "Enter a word" <<endl;

    while(true){
    	cout << ">";
		string str = GetLine();
		if(str.empty()) break;
		std::istringstream iss(str);
		string word;
		while(iss >> word){
			// int a = frequencymap[word];
			// int a = frequencymap.get(word);
			// Actually , these two function are doing same thing
			++frequencymap[word];
		}
    }
    cout << "Enter a word to check" << endl;
    while(true){
    	cout << '>';
		string response = GetLine();
		if(response.empty()) break;
		if(frequencymap.count(response)){
			int a =  frequencymap[response];	
			cout << "this word has appeared " << a << " times" << endl;
		}
		if(frequencymap.count(response) == 0){
				cout << "this word has not appeared so far" << endl;
		}
    }
}
