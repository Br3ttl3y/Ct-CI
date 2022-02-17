#include <iostream>
using namespace std;

const int MAX_ASCII_EX_CHARS = 256;

class UniqueCharacterFinder {
    private:
        string userInput;
        bitset<MAX_ASCII_EX_CHARS> characterBits;

        bool isOverCharacterLimit(){
            return userInput.length() > MAX_ASCII_EX_CHARS;
        }

    public:
        UniqueCharacterFinder(string input){
            userInput = input;
        }

        bool HasDuplicateCharacter(){
            if(isOverCharacterLimit()){
                return true;
            }

            for(int c = 0; c < userInput.length(); c++){
                int character = userInput[c];
                bool isCharacterDuplicate = characterBits[character];
                if(isCharacterDuplicate){
                    return true;
                }
                
                characterBits.set(character, true);
            }
            
            return false;    
        }
};

int main()
{
    string userInput;
    cout << "Type a word (ASCII characters only): " << endl;
    cin >> userInput;
    
    UniqueCharacterFinder question(userInput);

    string result = question.HasDuplicateCharacter() ? "has" : "doesn't have";

    cout << "Input: \"" << userInput << "\" " << result << " duplicate characters." << endl;
}
