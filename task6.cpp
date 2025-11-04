#include <iostream>
#include <climits>

using namespace std;

void findMinMax(int arr[], int n, int &minVal, int &maxVal) {

    minVal = INT_MAX;
    maxVal = INT_MIN;


    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
}

int main() {

    int arr[] = {12, 34, 5, 98, 23, 56, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    int minVal, maxVal;

    findMinMax(arr, n, minVal, maxVal);

    // Output the result
    cout << "The minimum value in the array is: " << minVal << endl;
    cout << "The maximum value in the array is: " << maxVal << endl;

    return 0;
}

