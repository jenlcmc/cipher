#include <iostream>
#include <vector>
#include <algorithm>

namespace caesar{

    std::vector<char> createAlpha(int shift){
        std::vector<char> cAlpha;
        for(auto i = 65 + shift; i < 91; ++i){
            cAlpha.push_back(i);
        }
        return cAlpha;
    }

    /* create a function that returns a vector of the values that were
    were not included because of the shift */
    std::vector<char> shiftValues(int shift){
        std::vector<char> shifted_values;
        for(auto i =65; i < 65+shift; ++i){
            shifted_values.push_back(i);
        }
        return shifted_values;
    }

    /* create a function to reverse the order of the vector */
    std::vector<char> reverseOrder(std::vector<char> vec){
//        std::vector<char> revOrder;
        std::reverse(vec.begin(), vec.end());
        return vec;
        
    }
}