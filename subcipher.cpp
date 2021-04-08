#include "subcipher.h"

using namespace std;
/**Encrypt- shift each character the user input by key letter
 * string input - user input
 * unsigned int key - key to shift character by key letters
 * return encrypted message
 * Algorithm- loop through string for each char and if it's white space then keep continue
 * use ternary ?: to check 1st letter if it's a or A
 *  En(x) = (x + n) % 26;
 * This cipher is also a improve version of Caesar cipher
 */
string sub::Encrypt(string input, unsigned int key){
    string mess = input;
    char stringChar;
    for(int i = 0; mess[i] != '\0'; i++){
        //if mess[i] is true then, 1st letter is a. 
        //if not, 1st letter is A
        char firstLetter = islower(mess[i]) ? 'a' : 'A';
        unsigned int alpha = mess[i] - firstLetter;
        unsigned int newAlpha = alpha + key;
        mess[i] = firstLetter + newAlpha % 26;
    }
    return mess;
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
string sub::Decrypt(string input, unsigned int key){
    string mess = input;
    char stringChar;
    for(int i = 0; mess[i] != '\0'; i++){
        if(mess[i] ==' '){
            continue;
        }
        //if mess[i] is true then, 1st letter is a. 
        //if not, 1st letter is A
        char firstLetter = islower(mess[i]) ? 'a' : 'A';
        unsigned int alpha = mess[i] - firstLetter;
        //result for newalpha can be negative so have to check value
        int newAlpha = alpha - key;
        //if neagtive, have to rotate by adding 26 to negative
        if(newAlpha < 0){
            newAlpha += 26;
        }
        mess[i] = firstLetter + (newAlpha % 26);
    }
    return mess;
}

/**VigenereMenu - user interface
 * return void
*/
void sub::SubMenu(){
    string messages;
    string encrypted;
    string decrypted;
    char answer;
    unsigned int key;
    //use app to append and not overwrite when start again
    ofstream encryptFile("encryptedSub.txt", fstream::app);
    ofstream decryptFile("decryptedSub.txt", fstream::app);
    ofstream keyFile("keyFileSub.txt", fstream::app);

    //main menu
    cout << endl << "Welcome to Substitution Cipher menu" << endl;
    cout << "Enter (E/e) for encrypt" << endl;
    cout << "Enter (D/d) for decrypt" << endl;
    cout << "Enter (Q/q) to quit" << endl;

    cin >> answer;
    switch (toupper(answer))
    {
    //encrypt choice
    case 'E':
    do{
        cout << "Please enter the message you want to encrypt. No space please" << endl;
        cin >> messages;
        cout << "Please enter the key" << endl;
        cin >> key;
        
        encrypted = Encrypt(messages, key);

        //ask if user want to write encrypted messages into txt file or not
        cout << "Do you want to print the messages to txt file? (y/Y) or (n/N)\n";
        cin >> answer;
        if(answer == 'y' || answer == 'Y'){
            keyFile << "key for encrypted: " << key << endl;  
            encryptFile << "encrypt message: " << encrypted << endl;
		}
        if(answer == 'n' || answer == 'N'){
            cout <<"key for the encrypt: " << key << endl;
            cout << "encrypt message: " << encrypted << endl;
		}

        //ask user if they want to continue or not
        cout << "(Q/q) to quit and (C/c) for continue another encrypt" << endl;
        cin >> answer;
    }while(answer == 'c' || answer == 'C');
        break;
    
    //decrypt choice
    case 'D':
    do{
        cout << "Please enter the message you want to decrypt. No space please" << endl;
        cin >> messages;
        cout << "Please enter the key" << endl;
        cin >> key;
        
        decrypted = Decrypt(messages, key);

        //ask if user want to write encrypted messages into txt file or not
        cout << "Do you want to print the messages to txt file? (y/Y) or (n/N)\n";
        cin >> answer;
        if(answer == 'y' || answer == 'Y'){
            decryptFile << "decrypt message: " << decrypted << endl;
		}
        if(answer == 'n' || answer == 'N'){
            cout << "decrypt message: " << decrypted << endl;
		}

        //ask user if they want to continue or not
        cout << "(Q/q) to quit and (C/c) for continue another decrypt" << endl;
        cin >> answer;
    }while(answer == 'c' || answer == 'C');
        break;

    //quit choice
    case 'Q':
        cout << "Thank you for using Substition Cipher" << endl;
        break;

    //error
    default:
        cout << "Wrong choice, please start again" << endl;
        break;
    }
}
