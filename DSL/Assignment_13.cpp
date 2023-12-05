// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 13 : Envirnomental Parameters

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_PARAMETERS = 10;  // Maximum number of environmental parameters

struct EnvironmentalData {
    string name;
    double values[MAX_PARAMETERS];
};

void findMinMax(const EnvironmentalData data[], int dataSize, int paramCount) {
    for (int i = 0; i < paramCount; ++i) {
        double minVal = data[0].values[i];
        double maxVal = data[0].values[i];

        for (int j = 1; j < dataSize; ++j) {
            if (data[j].values[i] < minVal) {
                minVal = data[j].values[i];
            }

            if (data[j].values[i] > maxVal) {
                maxVal = data[j].values[i];
            }
        }

        cout << "Parameter " << i + 1 << ": Min = " << minVal << ", Max = " << maxVal << endl;
    }
}

void calculateAverage(const EnvironmentalData data[], int dataSize, int paramCount) {
    for (int i = 0; i < paramCount; ++i) {
        double sum = 0.0;

        for (int j = 0; j < dataSize; ++j) {
            sum += data[j].values[i];
        }

        double average = sum / dataSize;
        cout << "Parameter " << i + 1 << ": Average = " << average << endl;
    }
}

void sortData(EnvironmentalData data[], int dataSize, int paramToSort) {
    for (int i = 0; i < dataSize - 1; ++i) {
        for (int j = 0; j < dataSize - i - 1; ++j) {
            if (data[j].values[paramToSort] > data[j + 1].values[paramToSort]) {
                // Swap
                EnvironmentalData temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int dataSize = 5;  // Number of data entries
    const int paramCount = 3; // Number of environmental parameters

    // Sample environmental data
    EnvironmentalData data[dataSize] = {
        {"Entry1", {25.5, 60.2, 30.0}},
        {"Entry2", {22.0, 55.8, 40.5}},
        {"Entry3", {28.5, 70.0, 35.5}},
        {"Entry4", {24.0, 65.5, 45.0}},
        {"Entry5", {26.8, 58.3, 32.7}}
    };

    // 1. Find the maximum and minimum values of each parameter
    findMinMax(data, dataSize, paramCount);

    // 2. Calculate the average value of each parameter
    calculateAverage(data, dataSize, paramCount);

    // 3. Sort the list in ascending order of any one parameter (Sorting by the first parameter in this case)
    int paramToSort = 0;
    sortData(data, dataSize, paramToSort);

    // Display sorted data
    cout << "\nSorted Data:\n";
    for (int i = 0; i < dataSize; ++i) {
        cout << setw(8) << data[i].name << ": ";
        for (int j = 0; j < paramCount; ++j) {
            cout << setw(8) << data[i].values[j] << " ";
        }
        cout << endl;
    }

    return 0;
}

