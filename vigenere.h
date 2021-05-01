#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
namespace vigenere{
void VigenereMenu();
std::string makeKey(std::string&, std::string&);
std::string Encrypt(std::string&, std::string&);
std::string Decrypt(std::string&, std::string&);
std::string Uppercase(std::string&);
std::string remove_space(std::string&);
};