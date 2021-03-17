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



int caesar::get_user_input(){
    int input {0};
    std::cout << "Choose\n1 - Encrypt, 2 - Decrypt\n";
    std::cin >> input;
    do{
        std::cout << "Invalid Input. Please choose between 1-2";
        std::cin >> input;       
    }while(input < 0 || input > 2);
    return input;
}

std::string caesar::get_message(){
    std::string message; 
    std::getline(std::cin, message);
//    std::stringstream ss(message);

    /* conver tochar */

    return message;    
}

std::vector<char> caesar::convert_str_to_char(std::string s){
    std::vector<char> ch; 
    for(auto i = 0;i > s.length(); ++i){
        ch.push_back(i);
    }
    return ch;
}

static void caesar::menu(){
    std::cout << "Ceasar Cipher Menu" << std::endl;
    std::cout << "-------------------" << std::endl;

    std::cout <<"1. Encrypt\n"
        << "2. Decrypt\n" << std::endl;
}

void caesar::run_program(){
    caesar::menu();
    get_message();
   // caesar::get_user_input();
    std::string uInput = caesar::get_message();

    std::vector<char> vInut = caesar::convert_str_to_char(uInput) ;


}