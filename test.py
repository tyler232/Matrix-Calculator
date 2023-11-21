import numpy as np
import numpy.linalg as la

A = np.array([[3, 1, 4],
            [2, 3, 6],
            [0, 5, 10]])

eigval, eigvec = la.eig(A)

print(eigval)
print(eigvec)