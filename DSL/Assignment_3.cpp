// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 3 : String Operations

#include <iostream>
#include <string>
using namespace std;
int main()
{
   int count = 0;
   int choice;
   string string1,string2,string3,string4,string5;
   string stringrev,foundpos,temp;
   bool found = false;
   char replace;
   char replaceby;
   char removed;
   char checkchar;
   string remainingString = "";

   cout << "-------------------------String Operations------------------------" << endl;
   cout << "Enter the number of condition you want to do : " << endl;
   cout << "1. To determine the frequency of occurence of a particular character in the string" << endl;
   cout << "2. Extract a new string from original string by accepting starting position and length" << endl;
   cout << "3. To accept any character and return the string with by removing all occurences of a character accepted " << endl;
   cout << "4. To check whether given string, is palindrome or not " << endl;
   cout << "5. To make a replacement of word in string by another word" << endl;
   cin >> choice;

   switch (choice)
   {
   case 1:
      cout << "Enter the String on which you want to operate : " << endl;
      cin >> string1;

      cout << "Enter the character from the given string that you want to check : " << endl;
      cin >> checkchar;

      for (int i = 0; i < string1.size(); i++)
      {
         if (string1[i] == checkchar)
         {
            ++count;
         }
      }
      cout << checkchar << " character repeats " << count << " times" << endl;
      break;

   case 2:
      int starting_position, end_position;

      cout << "Enter the string : " << endl;
      cin >> string2;

      cout << "Enter the index of starting position of the string : " << endl;
      cin >> starting_position;

      cout << "Enter the index of ending position of the string : " << endl;
      cin >> end_position;

      for (int i = starting_position; i < end_position; i++)
      {
         cout << string2[i];
      }
      break;

   case 3:
      cout << "Enter the string : " << endl;
      cin >> string3;

      cout << "Enter the character you want to remove : " << endl;
      cin >> removed;

      cout << "Removing character " << removed << " from string " << string3 << endl;
      for (int i = 0; i < string3.size(); i++)
      {
         if (string3[i] != removed)
         {
            cout << removed << " ";
         }
      }
      cout << endl;

      for (int i = 0; i < string3.size(); i++)
      {
         if (string3[i] != removed)
         {
            remainingString += string3[i];
         }
      }
      cout << "Remaining string: " << remainingString << endl;
      break;

   case 4:
      // Palindrome checking :
      cout << "Enter the string : " << endl;
      cin >> string4;
      for (int i = string4.size() - 1; i >= 0; i--)
      {
         stringrev += string4[i];
      }
      if (stringrev == string4)
      {
         cout << "This string is a palindrome!" << endl;
      }
      else
      {
         cout << "This string is not a palindrome!" << endl;
      }
      break;

   case 5:
      cout << "You selected the replacement of an element : " << endl;
      cout << "Enter the string: " << endl;
      cin >> string5;
      // getline(cin, string5);

      cout << "Enter the element you want to check is in the string or not: " << endl;
      cin >> replace;

      for (int i = 0; i < string5.length(); i++)
      {
         if (replace == string5[i])
         {
            cout << "Element found !" << endl;
            found = true;
            break;
         }
      }
      if (!found)
      {
         cout << "Your element is not found in the string." << endl;
      }
      else
      {
         cout << "Enter the element that you want to replace: " << endl;
         cin >> replace;
         cout << "Enter the element by which you want to replace: " << endl;
         cin >> replaceby;

         for (int i = 0; i < string5.length(); i++)
         {
            if (string5[i] == replace)
            {
               string5[i] = replaceby;
            }
         }

         cout << "The new string is: " << endl;
         cout << string5 << endl;
      }
      break;
   default:
      cout << "Thank you !!" << endl;
      break;
   }

   return 0;
}