// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 5 : Polynomial operations

#include <iostream>
using namespace std;
typedef struct
{
  float coef;
  int expo;
} polynomial;

class sample
{
private:
  int choice;
  polynomial poly[100];
  int total;

public:
  void read()
  {
    cout << endl;
    cout << "Enter Total Terms : " << endl;
    cin >> total;
    for (int i = 0; i < total; i++)
    {
      cout << "Enter the Coefficient : " << endl;
      cin >> poly[i].coef;
      cout << "Enter the Exponent : " << endl;
      cin >> poly[i].expo;
    }
  }
  void display()
  {
    cout << endl;
    cout << "Your polynomial is : " << endl;
    for (int i = 0; i < total; i++)
    {
      if (poly[i].expo == 1)
      {
        cout << poly[i].coef;
      }
      else
      {
        cout << poly[i].coef << "x^" << poly[i].expo;
      }
      if (i != total - 1)
      {
        cout << " + ";
      }
    }
  }
  void add(sample b)
  {
    int a = 0, bi = 0;
    sample c;
    int j = 0;
    while (b.total > bi || total > a)
    {
      if (b.poly[bi].expo == poly[a].expo) // Degree matched to add
      {
        c.poly[j].expo = b.poly[bi].expo;
        c.poly[j].coef = b.poly[bi].coef + poly[a].coef;
        j++;
        a++;
        bi++;
      }
      else if (b.poly[bi].expo > poly[a].expo)
      {
        c.poly[j].expo = poly[a].expo;
        c.poly[j].coef = poly[a].coef;
        j++;
        a++;
      }
      else
      {
        
        c.poly[j].expo = b.poly[bi].expo;
        c.poly[j].coef = b.poly[bi].coef;
        j++;
        bi++;
      }
    }
    while (total > a)
    {
      c.poly[j].expo = poly[a].expo;
      c.poly[j].coef = poly[a].coef;
      j++;
      a++;
    }
    while (b.total > bi)
    {
      c.poly[j].expo = b.poly[bi].expo;
      c.poly[j].coef = b.poly[bi].coef;
      j++;
      bi++;
    }

    c.total = j;
    c.display();
  }
};
int main()
{
  int choice;
  cout << "Enter your choice :\n1.Only read and display the polynomial\n2.Add the two polynomials" << endl;
  cin >> choice;
  sample a, b, c;
  switch (choice)
  {
  case 1:
    a.read();
    a.display();
    break;
  case 2:
    a.read();
    a.display();
    b.read();
    b.display();
    a.add(b);
    break;
  default:
    cout << "Enter the valid choice ! " << endl;
    break;
  }
}