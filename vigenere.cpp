#include "vigenere.h"
using namespace std;

/**makeKey - generate a new key
 * equal to length of orginial input
 * string UnserInput - input from the user
 * string key - generate key
 * return string key
 * Algorithm - generate key until the key length not equal to orginal input
**/

string vigenere::makeKey(string UserInput, string key){
    int UserSize = UserInput.length();

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
string vigenere::Encrypt(string input, string key){
    string EncryptedMess; 
    
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
string vigenere::Decrypt(string input, string key){
    string Decrypted;
    
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
string vigenere::Uppercase(string input){
	string value;
    for(unsigned int i = 0; i < input.length(); i++){
        value += toupper(input[i]);
    }
    return value;
}

/**VigenereMenu - user interface
 * return void
*/
void vigenere::VigenereMenu(){
    char answer;
    char choice;
    string messages;
    string key;
    string newKey;
    string encryptMessages;
    string encryptMess;
    string UserKey;
    string decryptMess;
    //use app to append and not overwrite when start again
    ofstream newfile("encryptFile.txt", fstream::app);
    ofstream DecryptFile("decryptFile.txt", fstream::app);
    ofstream keyFile("keyFile.txt", fstream::app);

    //main menu
    cout << "Hello, Welcome to Vigenere Cipher \n";
    cout << "For Encryption: choose E/e \n";
    cout << "For Decryption: choose D/e \n";
    cout << "To quit the program: choose Q/q \n";
    cin >> answer;

    switch(toupper(answer))
    {
    //encrypt choice
    case 'E':
    do{
        cout << "Please enter messages you want to encrypt. Please no whitespace/space \n";
        cin >> messages;
        cout << "Please also enter the key you want to generate. Please no whitespace/space\n";
        cin >> key;

        newKey = makeKey(Uppercase(messages), Uppercase(key));
        encryptMessages = Encrypt(Uppercase(messages), Uppercase(newKey));
        
        //ask if user want to write encrypted messages into txt file or not
        cout << "Do you want to print the messages to txt file? (y/Y) or (n/N)\n";
        cin >> answer;
        if(answer == 'y' || answer == 'Y'){
            keyFile << "key for the file: " << newKey << '\n';
            newfile << encryptMessages << endl;
		}
        if(answer == 'n' || answer == 'N'){
            cout <<"key for the decrypt: " << newKey << endl;
            cout << "Encrypted messages " << encryptMessages << endl;
		}

        //ask user if they want to continue or not
        cout << "(Q/q) to quit and (C/c) for continue another encrypt" << endl;
        cin >> answer;
    }while(answer == 'c' || answer == 'C');
    break;

    //decrypt choice
    case 'D':
    do{
        cout << "Please enter messages you want to decrypt. Please no whitespace/space '\n";
        cin >> encryptMess;
        cout << "Please also enter the key. Please no whitespace/space\n";
        cin >> UserKey;

        decryptMess = Decrypt(Uppercase(encryptMess), Uppercase(UserKey));
        
        //ask if user want to write encrypted messages into txt file or not
        cout << "Do you want to print the messages to txt file? (y/Y) or (n/N)\n";
        cin >> answer;
        if(answer == 'y' || answer == 'Y'){
                DecryptFile << decryptMess << '\n';
		}
        if(answer == 'n' || answer == 'N'){
            DecryptFile << "Decrypt message: " << decryptMess << '\n';
		}

        //ask user if they want to continue or not
        cout << "(Q/q) to quit and (C/c) for continue another decrypt" << endl;
        cin >> answer;
    }while(answer == 'c' || answer == 'C');
    break;

    //if user choice q, then quit the program
    case 'Q':
        cout << "Quite the program. Thank you for using Vigenere Cipher \n" << endl;
        break;

    default:
        cout << "Wrong choice. Please enter the choice again '\n";
        cin >> answer;
        break;
    }
}
