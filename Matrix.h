#ifndef POA_LABO1_MATRIXRELOADED_MATRIX_H
#define POA_LABO1_MATRIXRELOADED_MATRIX_H

#include <iostream>
#include "./operations/Operation.h"
#include "tests/Tests.h"

class Matrix {
public:

   /**
    * @brief Returns a ostream containing a formatted matrix.
    * 
    * @param os 
    * @param matrix 
    * @return std::ostream& 
    */
   friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

   /**
    * Copies the other matrix into the current matrix.
    * 
    * @param other 
    * @return Matrix& 
    */
   Matrix &operator=(const Matrix &other);


   /**
    * Matrix are equal if they have the same size, the same values and the same modulo.
    * 
    * @param m1 the first matrix
    * @param m2 the matrix to compare with m1
    * @return A boolean value.
    */
   friend bool operator==(const Matrix &m1, const Matrix &m2);

   /**
    * Returns true if the two matrices are not equal
    * 
    * @param m1 the first matrix
    * @param m2 the matrix to compare to m1
    * @return The result of the comparison of the two matrices.
    */
   friend bool operator!=(const Matrix &m1, const Matrix &m2);

   /**
    * Constructor that creates a matrix with the given number of rows and columns.
    * The modulo is applied to every value of the matrix.
    *
    * @param nbRows the number of rows
    * @param nbCols the number of columns
    * @param modulo the modulo
    */
   Matrix(size_t N, size_t M, unsigned modulo);

   /**
    * Copy the other Matrix into a new Matrix.
    * 
    * @param other the other Matrix
    */
   Matrix(const Matrix &other);

   /**
    * Destroy the Matrix object.
    * 
    */
   ~Matrix();

   /**
    * Create a new matrix with the values of the other matrix added to the values of this matrix.
    * It resize the returned matrix if other is bigger than this matrix.
    * 
    * @param other The matrix to add to this one.
    * @return A new Matrix object.
    */
   Matrix addStatic(const Matrix &other);

   /**
    * Add the elements of the other matrix to the elements of this matrix.
    * 
    * @param other the matrix to add to this one
    */
   void addSelf(const Matrix &other);

   /**
    * Create a new matrix with the values of the other matrix added to the values of this matrix.
    * It resize the returned matrix if the other is bigger than this matrix.
    * 
    * @param other The matrix to add to this one.
    * @return A new Matrix object that is the result of the addition of the two matrices.
    */
   Matrix *addDynamic(const Matrix &other);

   /**
    * Creates a new matrix with the values of this matrix substracted with the values of the other matrix.
    * It resize the returned matrix if the other is bigger than this matrix.
    * 
    * @param other The matrix to subtract from this matrix.
    * @return A new Matrix object.
    */
   Matrix subStatic(const Matrix &other);

   /**
    * This function subtracts the values of the other matrix from the values of this matrix.
    * 
    * @param other the matrix to subtract from this matrix.
    */
   void subSelf(const Matrix &other);

   /**
    * Creates a new matrix with the values of this matrix substracted with the values of the other matrix.
    * It resize the returned matrix if the other is bigger than this matrix.
    * 
    * @param other The matrix to subtract from this matrix.
    * @return A new Matrix object.
    */
   Matrix *subDynamic(const Matrix &other);

   /**
    * This function takes two matrices and multiplies them together into a new Matrix.
    * It resize the returned matrix if the other is bigger than this matrix.
    * 
    * @param other the other matrix to be multiplied with this matrix
    * @return The result of the multiplication in a new Matrix.
    */
   Matrix multStatic(const Matrix &other);

   /**
    * Multiply this matrix by the other matrix.
    * 
    * @param other the matrix to multiply with.
    */
   void multSelf(const Matrix &other);

   /**
    * This function takes two matrices and multiplies them together into a new Matrix.
    * It resize the returned matrix if the other is bigger than this matrix.
    * 
    * @param other the matrix to multiply with.
    * @return A new Matrix object that is the result of the multiplication.
    */
   Matrix *multDynamic(const Matrix &other);

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


   /**
    * Get the value at a position in the matrix.
    * 
    * @param row 
    * @param col 
    * @return unsigned 
    */
   unsigned getEl(size_t row, size_t col);

private:
   /**
    * Constructor that creates a matrix with the given number of rows and columns.
    * The modulo is applied to every value of the martix.
    * @param nbRows the number of rows
    * @param nbCols the number of columns
    * @param modulo the modulo
    * @param matrix 2D array with the values to copy
    */

   Matrix(size_t nbRows, size_t nbCols, unsigned modulo, unsigned **otherMatrix);

   /**
    * Allocate a matrix of unsigned integers
    * 
    * @param nbRows the number of rows in the matrix
    * @param nbCols the number of columns in the matrix
    * @return A pointer to a pointer to an array of unsigneds.
    */
   static unsigned **allocateMatrix(size_t nbRows, size_t nbCols);

   /**
    * It makes an opration between m1 and m2 and stores the result in m1
    * 
    * @param m1 The first matrix.
    * @param m2 The second matrix.
    * @param op the operation to perform.
    */
   static void operation(Matrix &m1, const Matrix &m2, const Operation &
   op);

   /**
    * This function deletes a matrix
    * 
    * @param matrixArray the array of pointers to the rows of the matrix
    * @param height The number of rows in the matrix.
    */
   static void deleteMatrix(unsigned **matrixArray, size_t height);


   unsigned **matrix;
   size_t nbRows;
   size_t nbCols;
   unsigned modulo;
};


#endif //POA_LABO1_MATRIXRELOADED_MATRIX_H
