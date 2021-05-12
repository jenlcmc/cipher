#include "caesar.h"


/* Run creaser program */
void caesar::run_program(){
    int choice = 0, shift = 0;
    std::string message = "", p1 ="", p2 ="";

    // separator for display
    for(auto i = 0; i < 10; ++i){
        std::cout << "*";
    } std::cout << std::endl;
    std::cout << "Enter message followed by:\n(1)Encode or (2)Decode\n"
            << "Shift/key value(1-26)\n"; 

    /* get user input message and key value*/
    std::getline(std::cin, message);
    std::cin >> choice >> shift;
 
    message = remove_space(message); //remove spaces 
    std::cout <<message << std::endl; //print message

    if(choice == 1) {        
        p1 = caesar::encrypt(message, shift); //store into p1
        // p2 = caesar::decrypt(p1, shift); //store into p2; commented out, was being used for testing 
        std::cout << "Encode: " << p1 << std::endl;
        caesar::create_file(p1,shift); std::cout << std::endl; //flushes buffer when creating a file

    } else if(choice == 2) {
        p2 = caesar::decrypt(message, shift);
        std::cout  << "Decode: "<< p2 << std::endl;
        caesar::create_file(p2, shift); std::cout << std::endl;
    }
}

/* fuction takes a string for and int for message and shift values */
std::string caesar::encrypt(std::string& message, int shift){
    std::string vals = ""; 
    for(auto i = 0; i < message.length(); ++i){
        if(isupper(message[i])){
            vals += char(int(message[i] + shift - 65)%26 + 65); //converts integers to char values
        } else {
            vals += char(int(message[i] + shift - 97)%26 + 97);  //and adds them into the string
        }
    }
    return vals;
}
/* this function calls the encrypt function and substracts the amount from the alphabet and the shift/key value */
std::string caesar::decrypt(std::string& message, int shift){
    shift%=26;
    return caesar::encrypt(message, 26 - shift);
}

/* using the algorithm library for the erase and remove function.
    remove iterates throuhg the message with begin and end (where to start, where to end, and what to search for)
    erase when it hits the end
 */
std::string caesar::remove_space(std::string& message){
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
    return message;
}

//write into a file using ostream library
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
