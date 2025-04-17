/*
Date:2025.4.15 UTC+8 21:56
Author:Qingke
Topic:STL
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
/*
three cores in STL:
iterator, algorithm, functors/lambdas

*/

const int kNumInt = 20;

void doBubbleSort(std::vector<int> &vec);
void printVec(const std::vector<std::string> &vec);

/*
int main(){
    std::vector<int> vec(kNumInt);
    for(size_t i = 0;i < kNumInt;i++){
        vec[i] = rand();
    }

    doBubbleSort(vec);

    for(size_t i = 0;i < kNumInt;i++){
        std::cout << vec[i] << std::endl;
    }
}
*/

int main(){
    std::vector<int> vec(kNumInt);
    std::generate(vec.begin(),vec.end(),rand);
    std::sort(vec.begin(),vec.end());
    std::copy(vec.begin(),vec.end(),std::ostream_iterator<int>(std::cout,"\n"));
    std::vector<std::string> names;
    names.push_back("Anna");
    names.push_back("Avery");
    printVec(names);
    std::cout << names.at(0) << std::endl;
    return 0;
}



void doBubbleSort(std::vector<int> &vec){
    for(size_t i = 0;i < vec.size() - 1;i++){
        for(size_t j = 0;j < vec.size() - i - 1;j++){
            if(vec[j] > vec[j+1]){
                int tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
 	}
    }
}

void printVec(const std::vector<std::string> &vec){
    if(vec.size() != 0){
	 for(auto p : vec){
    	    std::cout << p << ' '; 
   	 }
	 std::cout << std::endl;
    }else{
    	std::cout << "This vector has no attribute" << std::endl;
    }
    return ;
}

