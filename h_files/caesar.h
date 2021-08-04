#pragma once

#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>


namespace caesar{
//    std::vector<char> encrypt(std::vector<char>, int);
    std::string encrypt(std::string&, int);
    std::string decrypt(std::string&, int);
    std::string remove_space (std::string&);
    int create_file(std::string&,int);
    void run_program();

    /* reverse */
    void run_reverse();
    std::vector<char> reverse_message(std::vector<char>&);

};
