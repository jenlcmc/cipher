#include "./h_files/subcipher.h"

//using namespace std;
/**Encrypt- shift each character the user input by key letter
 * string input - user input
 * unsigned int key - key to shift character by key letters
 * return encrypted message
 * Algorithm- loop through string for each char and if it's white space then keep continue
 * use ternary ?: to check 1st letter if it's a or A
 *  En(x) = (x + n) % 26;
 * This cipher is also a improve version of Caesar cipher
 */
std::string sub::Encrypt(std::string& input, unsigned int key){
    for(int i = 0; input[i] != '\0'; i++){
        //if mess[i] is true then, 1st letter is a. 
        //if not, 1st letter is A
        char firstLetter = islower(input[i]) ? 'a' : 'A';
        auto alpha = input[i] - firstLetter;
        auto newAlpha = alpha + key;
        input[i] = firstLetter + newAlpha % 26;
    }
    return input;
}

/**Encrypt- shift each character the user input by key letter
 * string input - user input
 * unsigned int key - key to shift character by key letters
 * return decrypted message
 * Algorithm- loop through string for each char and if it's white space then keep continue
 * use ternary ?: to check 1st letter if it's a or A
 *  En(x) = (x - n) % 26;
 * This cipher is also a improve version of Caesar cipher
 */
std::string sub::Decrypt(std::string& input, unsigned int key){
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] ==' '){
            continue;
        }
        //if mess[i] is true then, 1st letter is a. 
        //if not, 1st letter is A
        char firstLetter = islower(input[i]) ? 'a' : 'A';
        auto alpha = input[i] - firstLetter;
        //result for newalpha can be negative so have to check value
        int newAlpha = alpha - key;
        //if neagtive, have to rotate by adding 26 to negative
        if(newAlpha < 0){
            newAlpha += 26;
        }
        input[i] = firstLetter + (newAlpha % 26);
    }
    return input;
}

std::string sub::remove_space(std::string& message){
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
    return message;
}

void sub::ASCII(){
    std::cout << "   _____ __ __  ____  \n " <<
                "    / ___/|  |  ||    | \n " << 
                "       |_ |  |  ||  o  ) \n" <<
                "    |__  ||  |  ||     | \n" <<
                "    /  | ||  :  ||  O  | \n" <<
                "    |    ||     ||     | \n" <<
                "     |___| |__,_||_____| \n" << std::endl << std::endl;
    std::cout << "E/e- for encrypt" << std::endl;
    std::cout << "D/d- for decrypt" << std::endl;
    std::cout << "Q/q- to quit" << std::endl;
}

/**VigenereMenu - user interface
 * return void
*/
void sub::SubMenu(){
    std::string messages;
    std::string encrypted;
    std::string decrypted;
    char answer;
    unsigned int key;

    //use app to append and not overwrite when start again
    std::ofstream encryptFile("./Text_Files/encryptedSub.txt", std::fstream::app);
    std::ofstream decryptFile("./Text_Files/decryptedSub.txt", std::fstream::app);
    std::ofstream keyFile("./Text_Files/keyFileSub.txt", std::fstream::app);

    //main menu
    ASCII();
    std::cin >> answer;

    switch (toupper(answer))
    {
    //encrypt choice
    case 'E':
    do{
        std::cout << std:: endl << "Enter message to encrypt (no space) following by key numbers." << std::endl;
        std::cin >> messages >> key;

        //rmeove white spcae
        messages = remove_space(messages);
        //enrypt
        encrypted = Encrypt(messages, key);

        //ask if user want to write encrypted messages into txt file or not
        std::cout << "Do you want to print the messages to txt file? (y/Y) or (n/N)\n";
        std::cin >> answer;

        if(answer == 'y' || answer == 'Y'){
            keyFile << "\n key for encrypted: " << key << std::endl;  
            encryptFile << "encrypt message: " << encrypted << std::endl;
		}
        if(answer == 'n' || answer == 'N'){
            std::cout << std::endl <<"key for the encrypt: " << key << std::endl;
            std::cout << "encrypt message: " << encrypted << std::endl;
		}

        //ask user if they want to continue or not
        std::cout << std::endl << "(Q/q) to quit and (C/c) for continue another encrypt" << std::endl;
        std::cin >> answer;
    }while(answer == 'c' || answer == 'C');
        break;
    
    //decrypt choice
    case 'D':
    do{
        std::cout << "Enter message to decrypt (no space) follow by key numbers." << std::endl;
        std::cin >> messages >>key;
        decrypted = Decrypt(messages, key);

        //ask if user want to write encrypted messages into txt file or not
        std::cout << "Do you want to print the messages to txt file? (y/Y) or (n/N)\n";
        std::cin >> answer;
        
        if(answer == 'y' || answer == 'Y'){
            decryptFile << "decrypt message: " << decrypted << std::endl;
		}
        if(answer == 'n' || answer == 'N'){
            std::cout << "\n decrypt message: " << decrypted << std::endl;
		}

        //ask user if they want to continue or not
        std::cout << std::endl << "(Q/q) to quit and (C/c) for continue another decrypt" << std::endl;
        std::cin >> answer;
    }while(answer == 'c' || answer == 'C');
        break;

    //quit choice
    case 'Q':
        std::cout << "Thank you for using Substition Cipher" << std::endl;
        break;

    //error
    default:
        std::cout << "Wrong choice, please start again" << std::endl;
        break;
    }
}
