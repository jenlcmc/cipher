#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

namespace vigenere{

void VigenereMenu();
string makeKey(string, string);
string Encrypt(string, string);
string Decrypt(string, string);
string Uppercase(string);

};