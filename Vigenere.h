#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void VigenereMenu();
string makeKey(string, string);
string Encrypt(string, string);
string Decrypt(string, string);
string Uppercase(string);