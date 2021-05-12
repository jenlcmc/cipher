#include <iostream>
#include <vector>
#include "caesar.h"
#include "subcipher.h"
#include "vigenere.h"

static void help();

int main(int argc, char** argv){
    char userChoice;

    //one of the files is using namespace std
    //no errors with endl (not std::endl);
    std::cout << "Welcome to cipher text" << endl; 
    std::cout << "Caesar Cipher. Enter C/c" << endl;
    std::cout << "Vigenere Cipher. Enter V/v" << endl;
    std::cout << "Subtitution cipher. Enter S/s" << endl;
    std::cout << "Reverse Cipher. (R/r)" << endl;

    std::cin >> userChoice; std::cin.get();
    userChoice = tolower(userChoice); // lowers chances for case input error


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
        case 'r':
            caesar::run_reverse();
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
