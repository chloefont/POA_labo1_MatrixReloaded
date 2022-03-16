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


   /* Creating a copy of the matrix other and assigning it to the current matrix. */
   Matrix& operator=(const Matrix& other);

   //TODO pas très clair
   /**
    * If the two matrices are equal, then they have the same number of rows, columns, and modulo
    * 
    * @param m1 the first matrix
    * @param m2 the matrix to compare with m1
    * @return A boolean value.
    */
   friend bool operator==(const Matrix& m1, const Matrix& m2);

   /**
    * Returns true if the two matrices are not equal
    * 
    * @param m1 the first matrix
    * @param m2 the matrix to compare to m1
    * @return The result of the comparison of the two matrices.
    */
   friend bool operator!=(const Matrix& m1, const Matrix& m2);

   /**
    * Constructor that creates a matrix with the given number of rows and columns.
    * 
    * @param nbRows the number of rows
    * @param nbCols the number of columns
    * @param modulo the modulo
    */
   Matrix(size_t N, size_t M, unsigned modulo);

   /**
    * @brief Copy the other Matrix into a new Matrix.
    * 
    * @param other 
    */
   Matrix(const Matrix& other);

   /**
    * @brief Destroy the Matrix object
    * 
    */
   ~Matrix();

   /**
    * Add the values of the other matrix to the values of a copy of this matrix.
    * 
    * @param other The matrix to add to this one.
    * @return A new Matrix object.
    */
   Matrix addStatic(const Matrix& other);

   /**
    * Add the elements of the
    * matrix other to the elements of this matrix.
    * 
    * @param other the matrix to add to this one
    */
   void addSelf(const Matrix& other);

   /**
    * Add the values of the other matrix to the values of a copy of this matrix.
    * 
    * @param other The matrix to add to this one.
    * @return A new Matrix object that is the result of the addition of the two matrices.
    */
   Matrix* addDynamic(const Matrix& other);

   /**
    * This function subtracts the values of the other matrix from the values of a copy of this matrix.
    * 
    * @param other The matrix to subtract from this matrix.
    * @return A new Matrix object.
    */
   Matrix subStatic(const Matrix& other);

   /**
    * This function subtracts the values of the other matrix from the values of this matrix.
    * 
    * @param other the matrix to subtract from this matrix.
    */
   void subSelf(const Matrix& other);

   /**
    * This function subtracts the values of the other matrix from the values of a copy of this matrix.
    * 
    * @param other The matrix to subtract from this matrix.
    * @return A new Matrix object.
    */
   Matrix* subDynamic(const Matrix& other);

   /**
    * This function takes two matrices and multiplies them together into a new Matrix.
    * 
    * @param other the other matrix to be multiplied with this matrix
    * @return The result of the multiplication in a new Matrix.
    */
   Matrix multStatic(const Matrix& other);

   /**
    * Multiply this matrix by the other matrix.
    * 
    * @param other the matrix to multiply with.
    */
   void multSelf(const Matrix& other);

   /**
    * This function takes two matrices and multiplies them together into a new Matrix.
    * 
    * @param other the matrix to multiply with.
    * @return A new Matrix object that is the result of the multiplication.
    */
   Matrix* multDynamic(const Matrix& other);

   /**
    * Return the number of rows in the matrix
    * 
    * @return The number of rows in the matrix.
    */
   size_t getNbRows() const;

   /**
    * Return the number of columns in the matrix
    * 
    * @return The number of columns in the matrix.
    */
   size_t getNbCols() const;

   unsigned getEl(size_t row, size_t col);

private:
   Matrix(size_t n, size_t m, unsigned modulo, unsigned** otherMatrix);

   /**
    * Allocate a matrix of unsigned integers
    * 
    * @param nbRows the number of rows in the matrix
    * @param nbCols the number of columns in the matrix
    * @return A pointer to a pointer to an array of unsigneds.
    */
   static unsigned** allocateMatrix(size_t nbRows, size_t nbCols);

   /**
    * It makes an opration between m1 and m2 and stores the result in m1
    * 
    * @param m1 The first matrix.
    * @param m2 The second matrix.
    * @param op the operation to perform.
    */
   static void operation(Matrix& m1, const Matrix& m2, const Operation&
   op);

   /**
    * This function deletes a matrix
    * 
    * @param matrixArray the array of pointers to the rows of the matrix
    * @param height The number of rows in the matrix.
    */
   static void deleteMatrix(unsigned** matrixArray, size_t height);


   unsigned** matrix;
   size_t nbRows;
   size_t nbCols;
   unsigned modulo;
};


#endif //POA_LABO1_MATRIXRELOADED_MATRIX_H
