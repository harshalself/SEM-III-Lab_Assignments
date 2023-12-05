// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 11 : Sorting

#include<iostream>
using namespace std;

class ArrayOperation 
{
    int arr[5];

public:
    void accept() 
	{
        cout << "Enter array elements:" << endl;
        for (int i = 0; i < 5; i++) 
		{
            cin >> arr[i];
        }
    }

    void display() 
	{
        cout << "Array elements are: ";
        for (int i = 0; i < 5; i++) 
		{
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    void bubbleSort() 
	{
        for (int i = 0; i < 5 - 1; i++) 
		{
            for (int j = 0; j < 5 - i - 1; j++) 
			{
                if (arr[j] > arr[j + 1]) 
				{
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
        cout << "Array sorted using Bubble Sort." << endl;
        display();
    }

    void selectionSort() 
	{
        for (int i = 0; i < 5 - 1; i++) 
		{
            int minIndex = i;
            for (int j = i + 1; j < 5; j++) 
			{
                if (arr[j] < arr[minIndex]) 
				{
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
        cout << "Array sorted using Selection Sort." << endl;
        display();
    }

    void insertionSort() 
	{
        for (int i = 1; i < 5; i++) 
		{
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) 
			{
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        cout << "Array sorted using Insertion Sort." << endl;
        display();
    }

    void shellSort() 
	{
        for (int gap = 5 / 2; gap > 0; gap /= 2) 
		{
            for (int i = gap; i < 5; i += 1) 
			{
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
				{
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
        cout << "Array sorted using Shell Sort." << endl;
        display();
    }
};

int main() 
{
    ArrayOperation ao;

    ao.accept();
    ao.display();
    ao.bubbleSort();
    ao.selectionSort();
    ao.insertionSort();
    ao.shellSort();

    return 0;
}

