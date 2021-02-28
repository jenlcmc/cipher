#include <iostream>
#include <vector>
#include "caesar.cpp"
#include "helper.cpp"

void printVec(std::vector<char>);


int main(int argc, char** argv){

    /* CODE TESTING */
    std::vector<char> tester = caesar::createAlpha(3);
    std::vector<char> sValues = caesar::shiftValues(3);

    printVec(tester);
    printVec(sValues);
    caesar::reverseOrder(tester);
    printVec(tester);
    return 0;
}

void printVec(std::vector<char> c){
    for(auto i : c){
        std::cout << i << ' ';
    }std::cout << std::endl;
}

void usage(int argc, char** argv){


}