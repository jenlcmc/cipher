#pragma once

#include <vector>
#include <string>

namespace caesar{
//    std::vector<char> encrypt(std::vector<char>, int);
    std::string encrypt(std::string&, int);
    std::string decrypt(std::string&, int);
    std::string remove_space (std::string&);
    void run_program();

};