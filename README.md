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

```bash
git clone https://github.com/tyler232/Tiele-Linear-Algebra-Library.git
```

Include the library
```c++
#include "Tiele-Linear-Algebra-Library/tiele.h"
```

Specific Usage Please see tutorial below

## Support
If you encountered bugs with the project please make a Issue Post or E-mail me at "lchangbo1227@gmail.com"

## Tutorial

### Create Matrix
```c++
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
```c++
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
```c++
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
```c++
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
```c++
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

### Transpose
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
std::cout << tiele::transpose(A) << std::endl;
```
```{txt}
[[3,    2,      0]
[1,     3,      5]
[4,     6,      10]]
Rows: 3
Cols: 3
```

### Inverse
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
std::cout << tiele::inverse(A) << std::endl;
```
```{txt}
[[0,    0.5,    -0.3]
[-1,    1.5,    -0.5]
[0.5,   -0.75,  0.35]]
Rows: 3
Cols: 3
```

### Determinant
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
std::cout << tiele::det(A) << std::endl;
```
```{txt}
20
```

### Norm
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
std::cout << tiele::norm(A, 1) << std::endl; // L1 norm
std::cout << tiele::norm(A, 2) << std::endl; // L2 norm
std::cout << tiele::norm(A, std::numeric_limits<int>::infinity()) << std::endl; // inf norm
```
```{txt}
20
13.7825
15
```

### Condition
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
std::cout << tiele::cond(A, 1) << std::endl; // condition with L1 norm
std::cout << tiele::cond(A, 2) << std::endl; // condition with L2 norm
std::cout << tiele::cond(A, std::numeric_limits<int>::infinity()) << std::endl; // condition with inf norm
```
```{txt}
55
29.7778
45
```

### Trace
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
std::cout << tiele::trace(A) << std::endl;
```
```{txt}
16
```

### Rank
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
std::cout << tiele::matrix_rank(A) << std::endl;
```
```{txt}
3
```

### RREF
```c++
tiele::Matrix A({{3, 1, 4, 2},
                {2, 3, 6, 5},
                {0, 5, 10, 7}});
std::cout << tiele::reduced_row_echelon(A) << std::endl;
```
```{txt}
[[1,    0,      0,      0.4]
[0,     1,      0,      2]
[0,     0,      1,      -0.3]
]
Rows: 3
Cols: 4
```

### Eigen
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
// complex algorithm, if you are interested please check tiele.h and tiele.cpp with detailed explaination
std::pair<std::vector<double>, tiele::Matrix> eigen_A = tiele::eigen(A);
// eigenvalues
for (double eigenvalue : eigen_A.first) {
    std::cout << eigenvalue << " ";
}
std::cout << std::endl;
// eigenvectors (column)
std::cout << tiele::eigen(A).second << std::endl;
```
```{txt}
0.809706 1.85181 13.3385 
[[-0.426632,    -0.733675,      0.351519]
[-0.794459,     -0.579154,      0.519855]
[0.432227,      0.355388,       0.778579]]
Rows: 3
Cols: 3
```

### QR decomposition
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
std::cout << tiele::qrDecomposition(A).first << std::endl; // Q
std::cout << tiele::qrDecomposition(A).second << std::endl; // R
```
```{txt}
[[0.83205,      -0.20078,       0.517088]
[0.5547,        0.30117,        -0.775632]
[0,     0.932193,       0.361961]]
Rows: 3
Cols: 3

[[3.60555,      2.49615,        6.6564]
[0,     5.3637, 10.3258]
[0,     0,      1.03418]]
Rows: 3
Cols: 3
```

### LU decomposition
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
std::cout << tiele::luDecomposition(A).first << std::endl; // L
std::cout << tiele::luDecomposition(A).second << std::endl; // U
```
```{txt}
[[1,    0,      0]
[0.666667,      1,      0]
[0,     2.14286,        1]]
Rows: 3
Cols: 3

[[3,    1,      4]
[0,     2.33333,        3.33333]
[0,     0,      2.85714]]
Rows: 3
Cols: 3
```

### Singular Value Decomposition
```c++
tiele::Matrix A({{3, 1, 4},
                {2, 3, 6},
                {0, 5, 10}});
std::cout << tiele::svd(A)[0] << std::endl; // U
std::cout << tiele::svd(A)[1] << std::endl; // S
std::cout << tiele::svd(A)[2] << std::endl; // V
```
```{txt}
[[0.503637,     -0.801896,      0.321423]
[-0.808536,     -0.30645,       0.502352]
[0.304334,      0.512885,       0.802702]]
Rows: 3
Cols: 3

[[0.462844,     0,      0]
[0,     3.13523,        0]
[0,     0,      13.7825]]
Rows: 3
Cols: 3

[[-0.229371,    -0.962798,      0.142861]
[-0.864874,     0.268936,       0.423871]
[0.446523,      0.0263328,      0.894385]]
Rows: 3
Cols: 3
```

### Inner & Outer Product
```c++
tiele::Matrix v1({1, 3, 7});
v1 = tiele::transpose(v1);
tiele::Matrix v2({6, 5, 9});
v2 = tiele::transpose(v2);
std::cout << "Inner Product" << std::endl;
std::cout << tiele::inner(v1, v2) << std::endl;
std::cout << "Outer Product" << std::endl;
std::cout << tiele::outer(v1, v2) << std::endl;
```
```{txt}
Inner Product
84
Outer Product
[[6,    5,      9]
[18,    15,     27]
[42,    35,     63]]
Rows: 3
Cols: 3
```

