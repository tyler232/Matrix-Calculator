# Tiele Linear Algebra Library

Tiele Linear Algebra Library is a C++ library that designed to perform various amount of linear algebra operations. It is designed to be fast and easy to use, make it easy to implemented into a wide range of projects.

## Feature

Basic Linear Algebra Operations(Addition, Subtraction, Multiplication between Matrix, Vector and Scalar)

Inner & Outer Product calculation between vectors

Transpose, Inverse, Determinant, Norm, Trace, Condition, Rank

REF and RREF

Eigenvectors and Eigenvalues

QR decomposition

LU decomposition

Singular Value Decomposition

## Getting Started

### Prerequisites
C++ compiler with C++14 support

### Installation
clone this repository

```{bash}
git clone https://github.com/tyler232/Tiele-Linear-Algebra-Library.git
```

Include the library
```{C++}
#include "Tiele-Linear-Algebra-Library/tiele.h"
```

Specific Usage Please see tutorial below

## Support
If you encountered bugs with the project please make a Issue Post or E-mail me at "lchangbo1227@gmail.com"

## Tutorial

### Create Matrix
```{C++}
tiele::Matrix matrix_A({{3, 1, 4},
                        {2, 3, 6},
                        {0, 5, 10}});
std::cout << matrix_A << std::endl;
```
```{txt}
[[3,    1,      4]
[2,     3,      6]
[0,     5,      10]]
Rows: 3
Cols: 3
```

### Create Zero Matrix
```{C++}
// First parameter is amount of rows, second parameter is amount of columns
tiele::Matrix matrix_B(3, 3);
std::cout << matrix_B << std::endl;
```
```{txt}
[[0,    0,      0]
[0,     0,      0]
[0,     0,      0]]
Rows: 3
Cols: 3
```

### Create Identity Matrix
```{C++}
// Parameter is the size of identity
tiele::Matrix I = tiele::identity(3);
std::cout << I << std::endl;
```
```{txt}
[[1,    0,      0]
[0,     1,      0]
[0,     0,      1]]
Rows: 3
Cols: 3
```

### Get and Set Value in the Matrix
```{C++}
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
// get value at row 2 col 1
double val = A.getValue(2, 1);
std::cout << val << std::endl;
// set value at row 2 col 1 to -20
A.setValue(2, 1, -20);
val = A.getValue(2, 1);
std::cout << val << std::endl;
```
```{txt}
5
-20
```

### Basic Matrix Operation
```{C++}
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
tiele::Matrix B({{2, 4, -1},
                {3, -2, 7.5},
                {9, 5, 1}});
std::cout << "Addition" << std::endl;
std::cout << A + B << std::endl;
std::cout << "Subtraction" << std::endl;
std::cout << A - B << std::endl;
std::cout << "Multiplication" << std::endl;
std::cout << A * B << std::endl;
```
```{txt}
Addition
[[5,    5,      3]
[5,     1,      13.5]
[9,     10,     11]]
Rows: 3
Cols: 3

Subtraction
[[1,    -3,     5]
[-1,    5,      -1.5]
[-9,    0,      9]]
Rows: 3
Cols: 3

Multiplication
[[45,   30,     8.5]
[67,    32,     26.5]
[105,   40,     47.5]]
Rows: 3
Cols: 3
```
