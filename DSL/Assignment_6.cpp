// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 6 : Linked List Operations

#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Node
{
public:
   string name;
   int date;
   int month;
   Node *link;
};

class LinkedList
{
private:
   Node *head = NULL;
   Node *tail = NULL;

public:
   Node *getnode()
   {
      int noofStudent;
      Node *newnode = new Node;

      cout << "Enter Name : " << endl;
      cin >> newnode->name;

      cout << "Enter Date : " << endl;
      cin >> newnode->date;

      cout << "Enter Month : " << endl;
      cin >> newnode->month;

      newnode->link = NULL;
      return newnode;
   }
   void append(Node *newnode)
   {
      if (head == NULL)
      {
         head = newnode;
         tail = newnode;
      }
      else
      {
         tail->link = newnode;
         tail = newnode;
      }
   }
   void display()
   {
      Node *temp = head;
      while (temp != NULL)
      {
         cout << temp->name << " - " << temp->date << "/" << temp->month << endl;
         temp = temp->link;
      }
      cout << endl;
   }
   void deletion()
   {
      string name;
      cout << "Enter the name to delete : " << endl;
      cin >> name;

      Node *temp = head;
      Node *prev = NULL;
      while (temp != NULL && temp->name != name)
      {
         prev = temp;
         temp = temp->link;
      }

      if (temp == NULL)
      {
         cout << "Name not found." << endl;
      }
      else if (temp == head)
      {
         head = head->link;
         delete temp;
      }
      else
      {
         prev->link = temp->link;
         delete temp;
      }
   }
   void birthday()
   {
      time_t t = time(0);
      tm *now = localtime(&t);
      int c_day = now->tm_mday;
      int c_month = now->tm_mon + 1;

      Node *temp = head;
      while (temp != NULL)
      {
         if (temp->date == c_day && temp->month == c_month)
         {
            cout << "Happy birthday " << temp->name << "!" << endl;
         }
         temp = temp->link;
      }
      cout << endl;
   }
};
int main()
{
   LinkedList l;
   Node *temp;
   int noofStudent;
   int choice;
   bool repeat = true;
   while (repeat)
   {
      cout << "1. Insert name and birthday of new student\n2. Delete a student entry\n3. Display a happy birthday message for whom today (based on system date) is birthday\n4. Display the list of students with their birthdays\n5. Exit" << endl;
      cout << "\nEnter the choice : ";
      cin >> choice;

      switch (choice)
      {
      case 1:
         cout << "Enter the number of students : " << endl;
         cin >> noofStudent;
         for (int i = 0; i < noofStudent; i++)
         {
            temp = l.getnode();
            l.append(temp);
         }
         break;
      case 2:
         l.deletion();
         break;
      case 3:
         l.birthday();
         break;
      case 4:
         l.display();
         break;
      case 5:
         repeat = false;
         break;
      default:
         cout << "Invalid choice" << endl;
         break;
      }
   }
   return 0;
}