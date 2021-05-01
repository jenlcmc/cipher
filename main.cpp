#include <iostream>
#include <vector>
#include "caesar.h"
#include "subcipher.h"
#include "vigenere.h"

static void help();

int main(int argc, char** argv){
    char userChoice {}; //not work on mac
    //char userChoice;
    userChoice = tolower(userChoice); // lowers chances for case input error

    std::cout << "Welcome to cipher text" << std::endl;
    std::cout << "Caesar Cipher. Enter C/c" << std::endl;
    std::cout << "Vigenere Cipher. Enter V/v" << std::endl;
    std::cout << "Subtitution cipher. Enter S/s" << std::endl;

    std::cin >> userChoice; std::cin.get();

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
    std::cerr << "Please choose from one of the following:\n"
        << "v - VigenereCipher\n"
        << "c - caesarCipher\n" 
        << "s - Substition Cipher\n";
}
