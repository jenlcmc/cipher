#include "caesar.h"

void caesar::run_program(){
    int choice = 0, shift = 0;
    std::string message, p1, p2;

    std::cout << "\tEnter message followed by:\n\n\t(1)Encode or (2)Decode\n\n"
            << "\tShift/key value(1-26)\n"; 
    std::getline(std::cin, message);
    std::cin >> choice >> shift;
 
    message = remove_space(message); //remove spaces 
    std::cout <<message << std::endl; //print message

    if(choice == 1) {        
        p1 = caesar::encrypt(message, shift);
        p2 = caesar::decrypt(p1, shift);
        std::cout << "Encode: " << p1 << std::endl;
        caesar::create_file(p1,shift); std::cout << std::endl; //flushes buffer when creating a file

    } else if(choice == 2) {
        p2 = caesar::decrypt(message, shift);
        std::cout  << "Decode: "<< p2 << std::endl;
        caesar::create_file(p2, shift); std::cout << std::endl;
    }
}

std::string caesar::encrypt(std::string& message, int shift){
    std::string vals = ""; 
    for(auto i = 0; i < message.length(); ++i){
        if(isupper(message[i])){
            vals += char(int(message[i] + shift - 65)%26 + 65); //converts integers to char values
        } else {
            vals += char(int(message[i] + shift - 97)%26 + 97);  //and addes them into the string
        }
    }
    return vals;
}

std::string caesar::decrypt(std::string& message, int shift){
    shift%=26;
    return caesar::encrypt(message, 26 - shift);
}

std::string caesar::remove_space(std::string& message){
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
    return message;
}

//write into a file
int caesar::create_file(std::string& message,int shift){
    std::ofstream opf {"./Text_Files/binary.txt"};

    if(!opf)
    {
        std::cerr << "File could not be found\n"; return 1; 
    }
    
    opf << message << '\n';
    opf << shift << '\n';
    return 0;
}

/* reverse program */
void caesar::run_reverse(){
    /* using getline and stringstream for continuous input
    with spaces; ss for easier conversion of string to char */
    std::string line;
    std::stringstream ss(line);
    std::vector<char> vec;
    std::getline(std::cin, line);
    
    /* pushes string into char vector */
    for(auto i = 0; i < line.length(); ++i){
        vec.push_back(line[i]);
    }

    std::vector<char> rev = reverse_message(vec);

    for(auto i : rev){
        std::cout << i;
    }std::cout << std::endl;
    /* TODO
    create another function to print chars/convert to str
    to save to file
     */
}

std::vector<char> caesar::reverse_message(std::vector<char>& ch){
    std::reverse(ch.begin(), ch.end());
    return ch;
}
