#include "./h_files/vigenere.h"

/**makeKey - generate a new key
 * equal to length of orginial input
 * string UnserInput - input from the user
 * string key - generate key
 * return string key
 * Algorithm - generate key until the key length not equal to orginal input
**/

std::string vigenere::makeKey(std::string& UserInput, std::string& key){
    int UserSize = UserInput.length();
    //make them upper
    UserInput = Uppercase(UserInput);
    key = Uppercase(key);

    for(int i = 0; ; i++){
        if(key.length() == UserSize){
            break;
        }
        if(UserSize == i){
            i = 0;
        }
        key.push_back(key[i]);
    
    }
    return key;
}
/**Encrypt - encrypt the user message and return encrypted text
 * string input- original input from the user
 * string key - key from makeKey()
 * return Encrypt string message
 * Alforithm- Ci = Ti + Ki (mod m)
 * Ci - ith character of ciphertext
 * Ti - ith character of open text
 * Ki - ith character of key (if key phrase shorter than open text, than key is repeated to math the 
 * length of open text)
 * m- length of alphabet
**/
std::string vigenere::Encrypt(std::string& input, std::string& key){
    std::string EncryptedMess; 
    //make it upper
    input = Uppercase(input);
    key = Uppercase(key);

    for(int i = 0; i < input.length(); i++){
        //convert in range of alphabet
        char InputToChar = (input[i] + key[i]) % 26;
        //convert into ASCII
        InputToChar += 'A';
        EncryptedMess.push_back(InputToChar);
    
    }
    return EncryptedMess;
}

/**Decrypt - decrypt the user message and return decrypted text
 * string input- encrypted input from the user
 * string key - key from makeKey()
 * return Decrypt string message
 * Alforithm- Ti = Ci - Ki (mod m)
 * Ci - ith character of ciphertext
 * Ti - ith character of open text
 * Ki - ith character of key (if key phrase shorter than open text, than key is repeated to math the 
 * length of open text)
 * m- length of alphabet
**/
std::string vigenere::Decrypt(std::string& input, std::string& key){
    std::string Decrypted;
    
    input = Uppercase(input);
    key = Uppercase(key);

    for(int i = 0; i < input.length(); i++){
        //convert in alphabet-range
        char temp = (input[i] - key[i] + 26) % 26;
        //convert into ASCII
        temp += 'A';
        Decrypted.push_back(temp);
    }
    
    return Decrypted;
}

/*Uppercase - format string to uppercase
	string s- user input string
	return upper string value

	Algorithm- using for loop to loop through the string and then user another var to hold uppercase of the string
	After that, return the uppercase value
*/
std::string vigenere::Uppercase(std::string& input){
	std::string value;
    for(unsigned int i = 0; i < input.length(); i++){
        value += toupper(input[i]);
    }
    return value;
}

std::string vigenere::remove_space(std::string& message){
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
    return message;
}

void vigenere::displayVigenere(){
    //main menu
    std::cout << std::endl;
    std::cout << " ____    ____  __    _______  _______ .__   __.  _______ .______       _______ \n"
              << " |   |  /   / |  |  /  _____||   ____||  | |  | |   ____||   _  |     |   ____| \n"
              << "  |   ||   /  |  | |  |  __  |  |__   |   ||  | |  |__   |  |_)  |    |  |__   \n"
              << "   |      /   |  | |  | |_ | |   __|  |  . `  | |   __|  |      /     |   __|  \n"
              << "    |    /    |  | |  |__| | |  |____ |  ||   | |  |____ |  ||  |----.|  |____ \n"
              << "     |__/     |__|  |______| |_______||__| |__| |_______|| _| `._____||_______| \n" << std::endl;
    std::cout << std::endl;
    std::cout << "E/e - Encryption \n";
    std::cout << "D/e - Decryption \n";
    std::cout << "Q/q - Quit\n";
}

/**VigenereMenu - user interface
 * return void
*/
void vigenere::VigenereMenu(){
    char answer;
    char choice;
    std::string messages, encryptMessages, encryptMess, decryptMess;
    std::string key, newKey, UserKey;

    //use app to append and not overwrite when start again
    std::ofstream newfile("./Text_Files/encryptFile.txt", std::fstream::app);
    std::ofstream DecryptFile("./Text_Files/decryptFile.txt", std::fstream::app);
    std::ofstream keyFile("./Text_Files/keyFile.txt", std::fstream::app);

    displayVigenere();
    std::cin >> answer;

    switch(toupper(answer))
    {
    //encrypt choice
    case 'E':
    do{
        std::cout << std::endl;
        std::cout << "Please enter messages you want to encrypt.No space\n";
        std::cin >> messages;
        std::cout << "Please also enter the key you want to generate.No space\n";
        std::cin >> key;
        //remove whitespace
        messages = remove_space(messages);
        key = remove_space(key);

        newKey = makeKey(messages, key);
        encryptMessages = Encrypt(messages, newKey);
        
        //ask if user want to write encrypted messages into txt file or not
        std::cout << std::endl;
        std::cout << "Do you want to print the messages to txt file? (y/Y) or (n/N)\n";
        std::cin >> answer;
        if(answer == 'y' || answer == 'Y'){
            keyFile << "key for the file: " << newKey << '\n';
            newfile << encryptMessages << std::endl;
		}
        if(answer == 'n' || answer == 'N'){
            std::cout <<"key for the decrypt: " << newKey << std::endl;
            std::cout << "Encrypted messages " << encryptMessages << std::endl;
		}

        //ask user if they want to continue or not
        std::cout << std::endl;
        std::cout << "(Q/q) to quit and (C/c) for continue another encrypt" << std::endl;
        std::cin >> answer;

        if(answer == 'Q' || answer == 'q'){
            return;
        }
    }while(answer == 'c' || answer == 'C');
    break;

    //decrypt choice
    case 'D':
    do{
        std::cout << std::endl;
        std::cout << "Please enter messages you want to decrypt.  No space\n";
        std::cin >> encryptMess;
        std::cout << "Please also enter the key. No space \n";
        std::cin >> UserKey;

        encryptMess = remove_space(encryptMess);
        UserKey = remove_space(UserKey);

        decryptMess = Decrypt(encryptMess, UserKey);
        
        //ask if user want to write encrypted messages into txt file or not
        std::cout << std::endl;
        std::cout << "Do you want to print the messages to txt file? (y/Y) or (n/N)\n";
        std::cin >> answer;
        if(answer == 'y' || answer == 'Y'){
            DecryptFile << decryptMess << '\n';
		}
        if(answer == 'n' || answer == 'N'){
            std::cout << "Decrypt message: " << decryptMess << '\n';
		}

        //ask user if they want to continue or not
        std::cout << std::endl;
        std::cout << "(Q/q) to quit and (C/c) for continue another decrypt" << std::endl;
        std::cin >> answer;

        if(answer == 'Q' || answer == 'q'){
            return;
        }
    }while(answer == 'c' || answer == 'C');
    break;

    //if user choice q, then quit the program
    case 'Q':
        std::cout << std::endl;
        std::cout << "Thank you for using Vigenere Cipher \n";
        return;

    default:
        std::cout << "Wrong choice. Start again\n";
        break;
    }
}
