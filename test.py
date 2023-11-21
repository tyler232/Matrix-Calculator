import numpy as np
import numpy.linalg as la

A = np.array([[3, 1, 4],
            [2, 3, 6],
            [0, 5, 10]])

for i in range(1000):
    eigval, eigvec = la.eig(A)
