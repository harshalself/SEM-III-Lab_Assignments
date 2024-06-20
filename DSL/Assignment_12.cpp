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

    void linearSearch() 
	{
        int key, flag = 0;
        cout << "Enter a key:" << endl;
        cin >> key;
        for (int i = 0; i < 5; i++) 
		{
            if (arr[i] == key) 
			{
                cout << "Key found" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0) 
		{
            cout << "Key not found" << endl;
        }
    }

    void binarySearch() 
	{
        int key, flag = 0, low = 0, high = 5 - 1, mid;
        cout << "Enter a key: " << endl;
        cin >> key;
        while (low <= high) 
		{
            mid = (high + low) / 2;
            if (arr[mid] == key) 
			{
                cout << "Key found at: " << mid << endl;
                flag = 1;
                break;
            }
			else if (key < arr[mid]) 
			{
                high = mid - 1;
            }
			else if (key > arr[mid]) 
			{
                low = mid + 1;
            }
        }
        if (flag == 0) 
		{
            cout << "Key not found" << endl;
        }
    }
};
int main() 
{
    ArrayOperation ao;

    ao.accept();
    ao.display();
    ao.linearSearch();
    ao.display();
    ao.binarySearch();
	ao.display();
    return 0;
}