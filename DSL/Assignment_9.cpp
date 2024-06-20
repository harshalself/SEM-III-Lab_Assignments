// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 9 : String Operations using Stack

#include <iostream>
#include <stack>
#include <string>
#include <cctype> // for std::isalnum

using namespace std;

// Function to print the original string followed by the reversed string
void printOriginalAndReversedString(string input) {
    stack<char> charStack;

    // Push alphanumeric characters onto the stack
    for (char c : input) {
        if (isalnum(c)) {
            charStack.push(tolower(c)); // Convert to lowercase for case insensitivity
        }
    }

    cout << "Original String: " << input << endl;
    cout << "Reversed String: ";
    
    // Pop and print characters from the stack to reverse the string
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }

    cout << endl;
}

// Function to check if a string is a palindrome
bool isPalindrome(string input) {
    stack<char> charStack;
    string in;
    // Push alphanumeric characters onto the stack
    for (char c : input) {
        if (isalnum(c)) {
           in+=tolower(c);
            charStack.push(tolower(c)); // Convert to lowercase for case insensitivity
        }
    }

    string reversedString;

    // Pop characters from the stack to create the reversed string
    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    // Compare the original and reversed strings
    return in == reversedString;
}
int main() 
{
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    printOriginalAndReversedString(input);

    if (isPalindrome(input)) {
        cout << "The given string is a palindrome." << endl;
    } else {
        cout << "The given string is not a palindrome." << endl;
    }

    return 0;
}