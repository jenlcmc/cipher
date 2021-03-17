#include "Vigenere.h"
//#include "caesar.cpp"
#include "Caesar.h"
#include <iostream>
using namespace caesar;

void Menu(){
    char userChoice;
    std::cout << "Welcome to cipher text" << endl;
    std::cout << "To try Caesar Cipher. Enter C/c" << endl;
    std::cout << "To try Vigenere Cipher. Enter V/v" << endl;
    std::cin >> userChoice;

    if(userChoice == 'V' || userChoice == 'v'){
        VigenereMenu();
    }
    if(userChoice == 'c' || userChoice == 'C'){
        std::cout << "caesar cipher here// still have to add" << endl;
    }
}