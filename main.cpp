
#include <iostream>

#include "cppp.h"

int oink(int num)
{
    std::cout << "This is #" + std::to_string(num) +  " pig." << std::endl;
    for (auto i=0;i<1000000000;i++){ num += (int)(rand());  }
    return num;
}

int main(){
    std::cout << "main()" << std::endl;
    std::vector<int> numbers = {1,2,3,4,5,6,7,8};

    // std::vector<std::future<int>> results;
    // for(auto i:numbers){
    //     results.push_back(std::async(std::launch::async, oink,i));
    // }
    // for(auto& res:results){
    //     auto tmp = res.get();
    // }
    auto pool = Pool();
    auto results = pool.map(oink, numbers);
}