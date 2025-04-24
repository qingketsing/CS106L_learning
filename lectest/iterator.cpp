/*
Date:2025.4.18 UTC+8 9:59
Author:Qingke
Topic:iterator
*/
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <map>
#include <algorithm>

using std::cout ;using std::endl;
using std::vector;
using std::set; using std::map;
using std::string;
/*
Iterator has four main function:
Create iterator
Dereference iterator
Advance iterator
Compare against another iterator
*/

const int ELEM_TO_FIND = 5;

string GetLine();
map<string,int> GetUserInput();
void printVector(const vector<int>& vec);

int main(){ 
    set<int> container;
    for(int i = 0 ;i < 10 ;++i){
        container.insert(i);
    }
    // first we create an iterator and let it point to the first element
    set<int>::iterator it = container.begin();
    // then we dereference the iterator to get the value and travel all the elements in this set
    while(it != container.end()){
        cout << *it << " ";   // what we need to be careful with is the iterator is a pointer 
        ++it;

    }
    cout << endl;
    //another way to travel all the elements in this set
    set<int>::iterator it2;
    for(it2 = container.begin(); it2 != container.end(); ++it2){ // be careful with the end condition is it2 == container.end()
        cout << *it2 << " ";
    }
    cout << endl;

    map<string,int> freqmap;
    freqmap = GetUserInput();

    cout << "The frequency of the words you entered is: " << endl;
    /*
    for(auto it = freqmap.begin(); it != freqmap.end(); ++it){
        cout << it->first << ": " << it->second << endl;
    }
    */
    for(auto [key,val] : freqmap){
        cout << key << ": " << val << endl;
    }

    vector<int> vec = {3,4,2,5,1,6,8,0,7};
    printVector(vec);
    // sort the vector
    std::sort(vec.begin(), vec.end());
    printVector(vec);

    set<int> s = {3,4,2,5,1,6,8,0,7};
    auto findit =  std::find(s.begin(), s.end(), ELEM_TO_FIND);
    if(findit != s.end()){
        cout << "Found " << ELEM_TO_FIND << " in the set." << endl;
    }else{
        cout << "Did not find " << ELEM_TO_FIND << " in the set." << endl;
    }
    return 0;
}

string GetLine(){
    string line;
    getline(std::cin, line);
    return line;
}

map<string,int> GetUserInput(){
    map<string,int> freqmap;
    string line;
    cout << "Please enter a word: ";
    while (getline(std::cin, line) && !line.empty()) {
        cout << ">";
        ++freqmap[line];
    }
    return freqmap;
}

void printVector(const vector<int>& vec){
    for(auto p : vec){
        cout << p << ' ';
    }
    cout << endl;
    return;
}