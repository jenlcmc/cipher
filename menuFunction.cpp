#include "Vigenere.h"
#include "caesar.cpp"
using namespace caesar;
void Menu(){
    char userChoice;
    cout << "Welcome to cipher text" << endl;
    cout << "To try Caesar Cipher. Enter C/c" << endl;
    cout << "To try Vigenere Cipher. Enter V/v" << endl;
    cin >> userChoice;

    if(userChoice == 'V' || userChoice == 'v'){
        VigenereMenu();
    }
    if(userChoice == 'c' || userChoice == 'C'){
        cout << "caesar cipher here// still have to add" << endl;
    }
}