//
// Created by cfont on 24.02.2022.
//

#include <cstdlib>
#include <ctime>
#include <math.h>
#include "Matrix.h"

Matrix::Matrix(size_t n, const size_t m, unsigned modulo) {
   if (n < 0 || m < 0)
      throw
   matrix = new int*[n];

   for (size_t i = 0; i < n; i++) {
      matrix[i] = new int[m];
   }
   srand((int) time(0));

   for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
         matrix[i][j] = (int)round((1 + rand() / (RAND_MAX + 1.0) * modulo)) %
            (int)modulo;
      }
   }
}
