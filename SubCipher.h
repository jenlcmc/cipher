#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/* Using namespace to avoid name function name collision */
namespace sub{
//encryted functions
std::string Encrypt(std::string, unsigned int);
//decrypted functions
std::string Decrypt(std::string, unsigned int);
//menu function
void SubMenu();
};