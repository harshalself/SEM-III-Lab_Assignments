// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 4 : Sparse matrix operations

#include <iostream>
#include <string>
using namespace std;

class Sparse
{
  int row, col;
  int sparse[100][3];
  int matrix[100][100];

public:
  void represent()
  {
    cout << "Enter rows of the matrix : " << endl;
    cin >> row;
    cout << "Enter columns of the matrix : " << endl;
    cin >> col;
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        cin >> matrix[i][j];
      }
    }
    int count = 0;
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        if (matrix[i][j] != 0)
        {
          count++;
        }
      }
    }

    sparse[0][0] = row;
    sparse[0][1] = col;
    sparse[0][2] = count;
    int s = 1;
    for (int i = 0; i < count; i++)
    {
      for (int j = 0; j < col; j++)
      {
        if (matrix[i][j] != 0)
        {
          sparse[s][0] = i;
          sparse[s][1] = j;
          sparse[s][2] = matrix[i][j];
          s++;
        }
      }
    }
  }

  void display()
  {
    for (int i = 0; i <= sparse[0][2]; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        cout << sparse[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  void addition(Sparse obj)
  {

    Sparse outs;

    int a = 1, b = 1, c = 1;
    while (a <= sparse[0][2] && b <= obj.sparse[0][2])
    {

      if (sparse[a][0] == obj.sparse[b][0])
      {
        if (sparse[a][1] == obj.sparse[b][1])
        {
          outs.sparse[c][0] = sparse[a][0];
          outs.sparse[c][1] = sparse[a][1];
          outs.sparse[c][2] = sparse[a][2] + obj.sparse[b][2];
          c++;
          a++;
          b++;
        }
        else if (sparse[a][1] <= obj.sparse[b][1])
        {
          outs.sparse[c][0] = sparse[a][0];
          outs.sparse[c][1] = sparse[a][1];
          outs.sparse[c][2] = sparse[a][2];
          c++;
          a++;
        }
        else
        {
          outs.sparse[c][0] = obj.sparse[b][0];
          outs.sparse[c][1] = obj.sparse[b][1];
          outs.sparse[c][2] = obj.sparse[b][2];
          c++;
          b++;
        }
      }
      else if (sparse[a][0] <= obj.sparse[b][0])
      {
        outs.sparse[c][0] = sparse[a][0];
        outs.sparse[c][1] = sparse[a][1];
        outs.sparse[c][2] = sparse[a][2];
        c++;
        a++;
      }
      else
      {
        outs.sparse[c][0] = obj.sparse[b][0];
        outs.sparse[c][1] = obj.sparse[b][1];
        outs.sparse[c][2] = obj.sparse[b][2];
        c++;
        b++;
      }
    }
    outs.sparse[0][0] = sparse[0][0];
    outs.sparse[0][1] = sparse[0][1];
    outs.sparse[0][2] = c - 1;
    while (a <= sparse[0][2])
    {
      outs.sparse[c][0] = sparse[a][0];
      outs.sparse[c][1] = sparse[a][1];
      outs.sparse[c][2] = sparse[a][2];
      c++;
      a++;
    }
    while (b <= obj.sparse[0][2])
    {
      outs.sparse[c][0] = obj.sparse[b][0];
      outs.sparse[c][1] = obj.sparse[b][1];
      outs.sparse[c][2] = obj.sparse[b][2];
      c++;
      b++;
    }
    outs.display();
  }

  void simpleTranspose()
  {
    Sparse out;
    int k = 1;
    out.sparse[0][0] = sparse[0][1];
    out.sparse[0][1] = sparse[0][0];
    out.sparse[0][2] = sparse[0][2];
    for (int i = 0; i < sparse[0][1]; i++)
    {
      for (int j = 1; j <= sparse[0][2]; j++)
      {
        if (i == sparse[j][1])
        {
          out.sparse[k][0] = sparse[j][1];
          out.sparse[k][1] = sparse[j][0];
          out.sparse[k][2] = sparse[j][2];
          k++;
        }
      }
    }
    out.display();
  }

  void fastTranspose()
  {
    Sparse result;
    int index[sparse[0][1] + 1];
    int total[sparse[0][1]];
    for (int i = 0; i < sparse[0][1]; i++)
    {
      total[i] = 0;
    }
    int col;
    for (int i = 1; i <= sparse[0][2]; i++)
    {
      col = sparse[i][1];
      total[col]++;
    }
    index[0] = 1;
    for (int i = 1; i <= sparse[0][1]; i++)
    {
      index[i] = index[i - 1] + total[i - 1];
    }
    int loc;
    result.sparse[0][0] = sparse[0][1];
    result.sparse[0][1] = sparse[0][0];
    result.sparse[0][2] = sparse[0][2];
    for (int i = 1; i <= sparse[0][2]; i++)
    {
      col = sparse[i][1];
      int loc = index[col];
      result.sparse[loc][0] = sparse[i][1];
      result.sparse[loc][1] = sparse[i][0];
      result.sparse[loc][2] = sparse[i][2];
      index[col]++;
    }
    result.display();
  }
};

int main()
{
  Sparse sc, obj;
  sc.represent();
  sc.display();
  sc.fastTranspose();
  obj.represent();
  obj.display();
  sc.addition(obj);
}