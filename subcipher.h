#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/* Using namespace to avoid name function name collision */
namespace sub{
std::string Encrypt(std::string&, unsigned int);
std::string Decrypt(std::string&, unsigned int);
std::string remove_space(std::string& message);
void SubMenu();
void displaySub();
};