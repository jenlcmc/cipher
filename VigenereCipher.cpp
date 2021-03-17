#include "VigenereHelper.cpp"
using namespace std;

/**VigenereMenu - user interface
 * return void
*/
void VigenereMenu(){
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
