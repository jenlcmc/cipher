#include "Vigenere.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;
/**makeKey - generate a new key
 * equal to length of orginial input
 * string UnserInput - input from the user
 * string key - generate key
 * return string key
 * Algorithm - generate key until the key length not equal to orginal input
**/

string makeKey(string UserInput, string key){
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
string Encrypt(string input, string key){
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
string Decrypt(string input, string key){
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
string Uppercase(string input){
	string value;
    for(unsigned int i = 0; i < input.length(); i++){
        value += toupper(input[i]);
    }
    return value;
}