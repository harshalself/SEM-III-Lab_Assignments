// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 12 : Searching

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

// Function for linear search
bool linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return true;  // Found
        }
    }
    return false;  // Not found
}

// Function for binary search
bool binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return true;  // Found
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;  // Not found
}

// Function for jump search
bool jumpSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return false;  // Not found
        }
    }
    for (int i = prev; i < min(step, n); ++i) {
        if (arr[i] == target) {
            return true;  // Found
        }
    }
    return false;  // Not found
}

// Function to compare the complexities of searching methods
void compareSearchMethods(const vector<int>& arr, int target) {
    clock_t startTime, endTime;

    // Linear Search
    startTime = clock();
    bool linearResult = linearSearch(arr, target);
    endTime = clock();
    cout << "Linear Search: " << (linearResult ? "Found" : "Not Found")
         << ". Time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds\n";

    // Binary Search
    startTime = clock();
    bool binaryResult = binarySearch(arr, target);
    endTime = clock();
    cout << "Binary Search: " << (binaryResult ? "Found" : "Not Found")
         << ". Time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds\n";

    // Jump Search
    startTime = clock();
    bool jumpResult = jumpSearch(arr, target);
    endTime = clock();
    cout << "Jump Search: " << (jumpResult ? "Found" : "Not Found")
         << ". Time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds\n";
}

int main() {
    srand(time(0));

    int choice, n, target;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> rollNumbers(n);

    cout << "Choose how to input data:\n";
    cout << "1. Input from user\n";
    cout << "2. Generate random data\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter the roll numbers:\n";
            for (int i = 0; i < n; ++i) {
                cout << "Enter roll number for student " << i + 1 << ": ";
                cin >> rollNumbers[i];
            }
            break;
        case 2:
            for (int i = 0; i < n; ++i) {
                rollNumbers[i] = rand() % 1000 + 1;  // Random roll numbers between 1 and 1000
            }
            sort(rollNumbers.begin(), rollNumbers.end());
            break;
        default:
            cout << "Invalid choice!\n";
            return 1;
    }

    cout << "Enter the roll number to search: ";
    cin >> target;

    // Compare and display search results
    compareSearchMethods(rollNumbers, target);

    return 0;
}

