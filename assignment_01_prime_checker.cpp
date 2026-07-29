// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function prototype
bool isPrime(int n);

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    // Call the function and output the result
    if (isPrime(num)) {
        std::cout << num << " is a prime number." << std::endl;
    } else {
        std::cout << num << " is not a prime number." << std::endl;
    }

    return 0;
}

// Function implementation
bool isPrime(int n) {
    // Requirement: Numbers less than 2 are NOT prime
    if (n < 2) {
        return false;
    }

    // Check for factors from 2 up to sqrt(n)
    // (i * i <= n is equivalent to i <= sqrt(n), but avoids floating-point operations)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Found a factor, so n is not prime
        }
    }

    return true; // No factors found, n is prime
}