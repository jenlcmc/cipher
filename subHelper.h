#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//encryted functions
string Encrypt(string, unsigned int);

//decrypted functions
string Decrypt(string, unsigned int);

//menu function
void SubMenu();