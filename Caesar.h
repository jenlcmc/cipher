#pragma once

#include <vector>
#include <string>

namespace caesar{
    std::vector<char> encrypt(std::vector<char>, int);
    std::vector<char> decrypt(std::vector<char>, int);
    std::vector<char> reverseOrder(std::vector<char> vec);
//    int get_user_input();
    std::string  get_message();
    void set_message(std::string);
    std::vector<char> convert_str_to_char(std::string);
    static void menu();
    int get_key(int);
    int user_choice(int);
    void run_program();

};