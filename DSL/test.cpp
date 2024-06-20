#include<iostream>
#include<string>
using namespace std;

class StringOperations
{
public:
    string inputString;
    char checkCharacter;

    //1. To determine the frequency of occurrence of a particular character in the string.
    void countOccurrences()
    {
        int count = 0;
        cout << "Enter a String: " << endl;
        getline(cin, inputString);
        cout << "String: " << inputString << endl;
        cout << "Enter any character from the given string: " << endl;
        cin >> checkCharacter;
        for (int i = 0; i < inputString.size(); i++)
        {
            if (inputString[i] == checkCharacter)
            {
                ++count;
            }
        }
        cout << "Occurrence of " << checkCharacter << " is " << count << " times" << endl;
    }

    //2. Extract a new string from the original string by accepting starting position and length.
    void extractSubstring()
    {
        int startPos, endPos;
        cout << "Enter starting position to extract: ";
        cin >> startPos;
        cout << "Enter end position to extract: ";
        cin >> endPos;
        cout << "Extracted string is: ";
        for (int j = startPos; j <= endPos; j++)
        {
            cout << inputString[j];
        }
        cout << endl;
    }

    //3. To accept any character and return the string by removing all occurrences of the accepted character.
    void removeCharacter()
    {
        cout << "Removing character " << checkCharacter << " from string " << inputString << endl;
        for (int i = 0; i < inputString.size(); i++)
        {
            if (inputString[i] != checkCharacter)
            {
                cout << inputString[i] << endl;
            }
        }
    }

    //4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of the same length as x.
    void replaceSubstring()
    {
        string replaceStr, replaceWith;
        bool found = false;
        int i;

        cout << "Enter substring to replace: " << endl;
        cin >> replaceStr;
        cout << "Enter string to replace with: " << endl;
        cin >> replaceWith;

        for (i = 0; i < inputString.length(); i++)
        {
            if (inputString[i] == replaceStr[0])
            {
                int a = 0;
                for (int j = i; a < replaceStr.length(); j++)
                {
                    if (inputString[j] == replaceStr[a])
                    {
                        a++;
                        found = true;
                    }
                    else
                    {
                        found = false;
                        break;
                    }
                }
            }
            if (found)
            {
                break;
            }
        }

        string newString = "";
        for (int x = 0; x < inputString.length(); x++)
        {
            if (x != i)
            {
                newString = newString + inputString[x];
            }
            else
            {
                newString = newString + replaceWith + " ";
                x = replaceStr.length() + x;
            }
        }
        cout << newString;
    }

    //5. To check whether the given string is a palindrome or not.
    void checkPalindrome()
    {
        string reversed;
        for (int c = inputString.size() - 1; c >= 0; c--)
        {
            reversed = reversed + inputString[c];
        }
        cout << endl;
        if (reversed == inputString)
        {
            cout << "The given string is a palindrome!" << endl;
        }
        else
        {
            cout << "The given string is not a palindrome!" << endl;
        }
    }
};

int main()
{
    StringOperations stringOps;
    stringOps.countOccurrences();
    stringOps.extractSubstring();
    stringOps.removeCharacter();
    stringOps.replaceSubstring();
    stringOps.checkPalindrome();
    return 0;
}
