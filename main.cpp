#include <iostream>
#include <vector>
#include "caesar.h"
#include "subcipher.h"
#include "vigenere.h"

static void help();

int main(int argc, char** argv){
    //char userChoice {}; //not work on mac
    char userChoice;
    bool done = false;
    userChoice = tolower(userChoice); // lowers chances for case input error
    
    do{
    std::cout << "  ______   __  ._______   __    __   _______ .______ "<< std:: endl;
    std::cout << " /      | |  | |   _   | |  |  |  | |   ____||   _   | " << std:: endl;
    std::cout << " |  ,----'|  | |  |_)  | |  |__|  | |  |__   |  |_)  | " << std:: endl;
    std::cout << " |  |     |  | |   ___/  |   __   | |   __|  |      /  " << std:: endl;   
    std::cout << " |  `----.|  | |  |      |  |  |  | |  |____ |  ||  |----. " << std:: endl;
    std::cout << " |_______||__| | _|      |__|  |__| |_______|| _| `._____| " << std:: endl;
    std::cout << "                                                          " << std::endl;

    help();
    std::cin >> userChoice; 
    std::cin.get();

    switch (tolower(userChoice)){
        case 'v':
            vigenere::VigenereMenu();
            break;
        case 'c':
            caesar::run_program();
            break;
        case 's':
            sub::SubMenu();
            break;

        case 'q':
            done = true;
            return 0;

        default:
            help();
    }
    }while(!done);
    
}

static void help(){
    std::cerr << "Please choose from one of the following:\n"
        << "v - VigenereCipher\n"
        << "c - caesarCipher\n" 
        << "s - Substition Cipher\n"
        << "q - Quit the program\n";
}
