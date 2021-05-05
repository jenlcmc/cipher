#include "caesar.h"

#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>


void caesar::run_program(){
    int choice = 0, shift = 0;
    std::string message, p1, p2;

    std::cout << "\tEnter message followed by:\n\n\t(1)Encode or (2)Decode\n\n"
            << "\tShift/key value(1-26)\n"; 
    std::getline(std::cin, message);
    std::cin >> choice >> shift;
 
    message = remove_space(message); //remove spaces 
    std::cout <<message << std::endl; //print message

    if(choice == 1) {        
        p1 = caesar::encrypt(message, shift);
        p2 = caesar::decrypt(p1, shift);
        std::cout << "Encode: " << p1 << std::endl;
        caesar::create_file(p1,shift); std::cout << std::endl; //flushes buffer when creating a file

    } else if(choice == 2) {
        p2 = caesar::decrypt(message, shift);
        std::cout  << "Decode: "<< p2 << std::endl;
        caesar::create_file(p2, shift); std::cout << std::endl;
    }
}

std::string caesar::encrypt(std::string& message, int shift){
    std::string vals = ""; 
    for(auto i = 0; i < message.length(); ++i){
        if(isupper(message[i])){
            vals += char(int(message[i] + shift - 65)%26 + 65); //converts integers to char values
        } else {
            vals += char(int(message[i] + shift - 97)%26 + 97);  //and addes them into the string
        }
    }
    return vals;
}

std::string caesar::decrypt(std::string& message, int shift){
    shift%=26;
    return caesar::encrypt(message, 26 - shift);
}

std::string caesar::remove_space(std::string& message){
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
    return message;
}

//write into a file
int caesar::create_file(std::string& message,int shift){
    std::ofstream opf {"./Text_Files/dearjane.txt"};

    if(!opf)
    {
        std::cerr << "File could not be found\n"; return 1; 
    }
    
    opf << message << '\n';
    opf << shift << '\n';
    return 0;
}

