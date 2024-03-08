#include <iostream>
#include<string>
#include <unordered_map>
#include <sstream>




//convert charachters to morsecode by switch case
std::string morse(char m){
switch ((toupper(m))) {
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
        case 'Z':
            return "--..";
        case ' ':
            return " ";//spaces
        default:
            return "";//if user types special charachters not in morse
  }
}



// Function to decipher Morse code
std::string decipher_Morse(const std::string& morseCode) {
    std::unordered_map<std::string, char> morseToChar = {
            {".-",   'A'},
            {"-...", 'B'},
            {"-.-.", 'C'},
            {"-..",  'D'},
            {".",    'E'},
            {"..-.", 'F'},
            {"--.",  'G'},
            {"....", 'H'},
            {"..",   'I'},
            {".---", 'J'},
            {"-.-",  'K'},
            {".-..", 'L'},
            {"--",   'M'},
            {"-.",   'N'},
            {"---",  'O'},
            {".--.", 'P'},
            {"--.-", 'Q'},
            {".-.",  'R'},
            {"...",  'S'},
            {"-",    'T'},
            {"..-",  'U'},
            {"...-", 'V'},
            {".--",  'W'},
            {"-..-", 'X'},
            {"-.--", 'Y'},
            {"--..", 'Z'},
            {" ",    ' '} // space
    };
    std::istringstream iss(morseCode);
    std::string word;
    std::string result;

    while (iss >> word) {
        auto it = morseToChar.find(word);
        if (it != morseToChar.end()) {
            result += it->second;
        }
        else {
            result += '?'; // Unknown Morse code sequence
        }
    }
    return result;}



void displaymenu(){
    std::cout<<"welcome to morse code application\n1-cipher \n2-dicipher\n3-exit";
}
int main() {
    using namespace std;



    displaymenu();
    string text;
    int choice;
    string morseCode;
    cin >> choice;

    cin.ignore();
    switch (choice) {
        case 1: {
            cout<<"enter text you want to cipher";
            getline(cin, text);
            for (char m: text) {
                if (isalpha(m) || (isdigit(m))) {
                    cout << morse(m);
                }
                if (m == ' ') {
                    cout << ' ';
                } else {
                    continue;
                }
            }
        }
        case 2: {
            cout << "enter the morsecode you want to dicipher";
            getline(cin, morseCode);

            string decodedText = decipher_Morse(morseCode);
            cout << "Deciphered text: " << decodedText;

        }
        default: {
            break;
        }
    }

}













