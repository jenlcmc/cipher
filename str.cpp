#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    std::string message {"Hello World"};

//    std::size_t fnd = str.find(" ");
//    std::cout << fnd << std::endl;
//    str.erase(str.begin() +fnd);
//    std::cout << str << std::endl;
    std::transform(message.begin(), message.end(), message.begin(),
        [](unsigned char c) {return toupper(c); });
    cout << message << endl; 
    return 0;
}