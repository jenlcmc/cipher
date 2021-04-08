#include <iostream>
#include <vector>
#include "caesar.h"
#include "subcipher.h"
//#include "subcipher.cpp"
//#include "vigenere.cpp"
#include "vigenere.h"

static void help();

int main(int argc, char** argv){
    char userChoice {};
    userChoice = tolower(userChoice); // lowers chances for case input error

    std::cout << "Welcome to cipher text" << endl;
    std::cout << "Caesar Cipher. Enter C/c" << endl;
    std::cout << "Vigenere Cipher. Enter V/v" << endl;
    std::cout << "Subtitution cipher. Enter S/s" << endl;
    std::cin >> userChoice;
    std::cin.get();

    switch (userChoice){
        case 'v':
            vigenere::VigenereMenu();
            break;
        case 'c':
            caesar::run_program();
            break;
        case 's':
            sub::SubMenu();
            break;
        default:
            help();
    }

    return 0;
}

static void help(){
    std::cerr << "Please enter:\n"
        << "v - VigenereCipher\n"
        << "c - caesarCipher\n" 
        << "s - Substition Cipher\n";
}
