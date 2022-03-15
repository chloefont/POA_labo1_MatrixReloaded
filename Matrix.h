//
// Created by cfont on 24.02.2022.
//

#ifndef POA_LABO1_MATRIXRELOADED_MATRIX_H
#define POA_LABO1_MATRIXRELOADED_MATRIX_H

#include <iostream>
#include "./operations/Operation.h"
#include "tests/Tests.h"

// TODO opérateur affectation
class Matrix {
public:
   friend Tests;

   friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

   Matrix& operator=(const Matrix& other);

   friend bool operator==(const Matrix& m1, const Matrix& m2);

   friend bool operator!=(const Matrix& m1, const Matrix& m2);

   Matrix(size_t N, size_t M, unsigned modulo);

   Matrix(const Matrix& other);

   ~Matrix();

   Matrix addStatic(const Matrix& other);

   void addSelf(const Matrix& other);

   Matrix* addDynamic(const Matrix& other);

   Matrix subStatic(const Matrix& other);

   void subSelf(const Matrix& other);

   Matrix* subDynamic(const Matrix& other);

   Matrix multStatic(const Matrix& other);

   void multSelf(const Matrix& other);

   Matrix* multDynamic(const Matrix& other);

   size_t getNbRows() const;

   size_t getNbCols() const;

   unsigned getEl(size_t row, size_t col);

private:
   Matrix(size_t n, size_t m, unsigned modulo, unsigned** otherMatrix);

   static unsigned** allocateMatrix(size_t nbRows, size_t nbCols);

   static void operation(Matrix& m1, const Matrix& m2, const Operation&
   op);

   static void deleteMatrix(unsigned** matrixArray, size_t height);


   unsigned** matrix;
   size_t nbRows;
   size_t nbCols;
   unsigned modulo;
};


#endif //POA_LABO1_MATRIXRELOADED_MATRIX_H
