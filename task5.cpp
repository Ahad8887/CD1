#include <iostream>
using namespace std;

double calculateAverage(int arr[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / n;
}

int main() {

    int arr[] = {5, 10, 15, 20, 25};


    int n = sizeof(arr) / sizeof(arr[0]);

    double average = calculateAverage(arr, n);

    cout << "The average value of the array elements is: " << average << endl;

    return 0;
}
