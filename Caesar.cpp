#include "Caesar.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <ostream>

std::vector<char> caesar::encrypt(std::vector<char> en, int k){
    char ch;
    for(auto i = 0; en[i] != '\0'; ++i){
        ch = en[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + k;
            if( ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            en[i] = ch;
        }
    }
    return en;
}

std::vector<char> caesar::decrypt(std::vector<char> dc, int k){
    char ch = 0;
    for(auto i = 0; dc[i] != '\0'; ++i){
        ch = dc[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - k;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            dc[i] = ch;
        }
    }
    return dc;
}
/* create a function to reverse the order of the vector */
std::vector<char> caesar::reverseOrder(std::vector<char> vec){
    std::vector<char> revOrder;
    std::reverse(vec.begin(), vec.end());
    return vec;
    
}
// void set_message(std::string str){
//     std::cout << "Enter message: ";
// //    std::string message; 
//     std::getline(std::cin, message);
//     message = str;
// }
// std::string caesar::get_message(){
//     return message;    
// }

std::vector<char> caesar::convert_str_to_char(std::string str){
    std::vector<char> ch; 
    for(auto i = 0;i < str.length(); ++i){
        ch.push_back(str[i]);
    }
    return ch;
}

static void caesar::menu(){
    std::cout << "Ceasar Cipher Menu" << std::endl;
    std::cout << "-------------------" << std::endl;

    std::cout <<"1. Encrypt\n"
        << "2. Decrypt\n";

}
/* input validation */

int caesar::get_key(int key){
    while(key > 26 || key < 0){
        std::cout << "Enter a value between 1-26 ";
        std::cin >> key;
    }
    return key;
}
int caesar::user_choice(int input){
    while(input > 2 || input < 0){
        std::cout << "Enter a value between 1-2 ";
        std::cin >> input;
    }
    return input;   
}
/* RUN PROGRAM */
void caesar::run_program(){
    caesar::menu();
    int input, key;
    std::cin >> input;
    std::cin.get();
    input = user_choice(input);
    
    std::cout << "Enter a key value between 0-26: ";
    std::cin >> key;
    std::cin.get();
    key = get_key(key);

    std::string message;
    std::cout << "Enter your message:\n";

    std::getline(std::cin, message);
    std::cout << message << std::endl;

    std::vector<char> cMessage = convert_str_to_char(message);
    if(input == 1){
        std::cout << "Encrypt\n";
        std::vector<char> vMessage = encrypt(cMessage, key);
        for(auto i : vMessage){
            std::cout << i;
        } std::cout <<std::endl;
    } else if(input == 2){
        std::cout << "Decrypt\n";
        std::vector<char> vMessage = decrypt(cMessage, key);
        for(auto i : cMessage){
            std::cout << i;
        } std::cout <<std::endl;
    }

}