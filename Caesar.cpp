#include "Caesar.h"

#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <ostream>


void caesar::run_program(){
    int choice {}, shift {};
    std::string message;
    std::cout << "Encode or Decode followed by message choice, and shift "; 
    std::getline(std::cin, message);
    std::cin >> choice;
    std::cin >> shift; 
    std::string p1, p2;
    message = remove_space(message);
    std::cout <<message << std::endl;

    if(choice == 1) {        
        p1 = caesar::encrypt(message, shift);
        p2 = caesar::decrypt(p1, shift);
    } else {
        p2 = caesar::decrypt(p1, shift);
    }
    p1 = caesar::encrypt(message, shift);

    std::cout << "Encode: " << p1 << std::endl;
    p2 = caesar::decrypt(p1, shift);
    std::cout  << "Decode: "<< p2 << std::endl;

}
std::string caesar::encrypt(std::string& message, int shift){
    std::string vals{""}; 
    for(auto i = 0; i < message.length(); ++i){
        if(isupper(message[i])){
            vals += char(int(message[i] + shift - 65)%26 + 65);
        } else {
            vals += char(int(message[i] + shift - 97)%26 + 97);
        }
    }
    return vals;
}

std::string caesar::decrypt(std::string& message, int shift){
    shift%=26;
//    stdstring dec = encrypt(message, 26 - shift);
    return caesar::encrypt(message, 26 - shift);
}
std::string caesar::remove_space(std::string& message){
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
    return message;
}