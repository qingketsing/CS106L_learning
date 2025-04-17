/*
Date:2025.4.18 UTC+8 9:59
Author:Qingke
Topic:iterator
*/
#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using std::cout ;using std::endl;
using std::vector;
using std::set;
/*
Iterator has four main function:
Create iterator
Dereference iterator
Advance iterator
Compare against another iterator
*/

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
    return 0;
}