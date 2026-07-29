// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Maximum size allowed for fixed 2D arrays
const int MAX = 10;

// Function prototypes
void readMatrix(int matrix[MAX][MAX], int rows, int cols, string name = "matrix");
void printMatrix(const int matrix[MAX][MAX], int rows, int cols);
void transposeMatrix(const int src[MAX][MAX], int dest[MAX][MAX], int rows, int cols);
void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int C[MAX][MAX], int rows, int cols);
void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int C[MAX][MAX], int m, int n, int p);

int main() {
    int m, n, p;

   
    cout << "=== PART A: Transpose Matrix ===" << endl;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    int matA[MAX][MAX];
    int transA[MAX][MAX];

    readMatrix(matA, m, n, "Matrix A");

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matA, m, n);

    transposeMatrix(matA, transA, m, n);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transA, n, m); // Note: swapped dimensions (n x m)

    
    cout << "\n=== PART B: Matrix Addition ===" << endl;
    cout << "Enter dimensions for Addition (M x N)" << endl;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    int matB1[MAX][MAX];
    int matB2[MAX][MAX];
    int sumMat[MAX][MAX];

    cout << "\nEnter values for First Matrix:" << endl;
    readMatrix(matB1, m, n, "First Matrix");

    cout << "\nEnter values for Second Matrix:" << endl;
    readMatrix(matB2, m, n, "Second Matrix");

    addMatrices(matB1, matB2, sumMat, m, n);

    cout << "\nMatrix Sum:" << endl;
    printMatrix(sumMat, m, n);

    cout << "\n=== PART C: Matrix Multiplication ===" << endl;
    cout << "Enter Matrix A rows (M): ";
    cin >> m;
    cout << "Enter Matrix A cols / Matrix B rows (N): ";
    cin >> n;
    cout << "Enter Matrix B cols (P): ";
    cin >> p;

    int matC1[MAX][MAX];
    int matC2[MAX][MAX];
    int prodMat[MAX][MAX];

    cout << "\nEnter values for Matrix A (" << m << "x" << n << "):" << endl;
    readMatrix(matC1, m, n, "Matrix A");

    cout << "\nEnter values for Matrix B (" << n << "x" << p << "):" << endl;
    readMatrix(matC2, n, p, "Matrix B");

    multiplyMatrices(matC1, matC2, prodMat, m, n, p);

    cout << "\nProduct Matrix (A x B):" << endl;
    printMatrix(prodMat, m, p);

    return 0;
}

// Function to read matrix values from user input
void readMatrix(int matrix[MAX][MAX], int rows, int cols, string name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to print a matrix as an aligned grid
void printMatrix(const int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A: Transpose function
void transposeMatrix(const int src[MAX][MAX], int dest[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

// Part B: Addition function
void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Part C: Multiplication function (A: m x n, B: n x p, C: m x p)
void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int C[MAX][MAX], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0; // Initialize product sum
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}