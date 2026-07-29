// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function prototypes
int calculateSum(const int arr[], int size);
double calculateAverage(const int arr[], int size);
int findMaximum(const int arr[], int size);
int findMinimum(const int arr[], int size);

int main() {
    int count;

    cout << "How many numbers? ";
    cin >> count;

    // Validate that count is a positive integer
    if (count <= 0) {
        cout << "Error: Number of elements must be greater than 0." << endl;
        return 1;
    }

    // Declare array based on user input
    int numbers[count];

    // Read input numbers from user
    for (int i = 0; i < count; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << endl;
    cout << "Results:" << endl;
    cout << "Sum:     " << calculateSum(numbers, count) << endl;
    cout << "Average: " << calculateAverage(numbers, count) << endl;
    cout << "Maximum: " << findMaximum(numbers, count) << endl;
    cout << "Minimum: " << findMinimum(numbers, count) << endl;

    return 0;
}

// Function to calculate the sum of array elements
int calculateSum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average of array elements
double calculateAverage(const int arr[], int size) {
    int sum = calculateSum(arr, size);
    // Explicitly cast sum to double for decimal division
    return static_cast<double>(sum) / size;
}

// Function to find the maximum value in the array
int findMaximum(const int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find the minimum value in the array
int findMinimum(const int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}