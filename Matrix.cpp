#include <iostream>
#include <string>
#include <cstring>
#include "Matrix.h"
#include "operations/Add.h"
#include "operations/Sub.h"
#include "operations/Mult.h"
#include "Generator/RandomNumberGenerator.h"

using namespace std;

ostream& operator<< (ostream& os, const Matrix& matrix) {
   string str;

   for (size_t i = 0; i < matrix.nbRows; i++) {
      for (size_t j = 0; j < matrix.nbCols; j++) {
         str += to_string(matrix.matrix[i][j]);
         if (j < (matrix.nbCols - 1))
            str += " ";
      }
      str += "\n";
   }

   return os << str;
}


bool operator==(const Matrix &m1, const Matrix &m2) {
   if (&m1 == &m2)
      return true;

   if (m1.nbRows != m2.nbRows || m1.nbCols != m2.nbCols || m1.modulo != m2.modulo)
      return false;

   for (size_t i = 0; i < m1.nbRows; i++) {
      if(memcmp(m1.matrix[i], m2.matrix[i], m1.nbCols * sizeof(unsigned)) != 0)
         return false;
   }

   return true;
}


bool operator!=(const Matrix &m1, const Matrix &m2) {
   return !operator==(m1, m2);
}

Matrix::Matrix (size_t n, size_t m, unsigned modulo): nbRows(n), nbCols(m), modulo
(modulo) {
   if (n <= 0 || m <= 0 || modulo <= 0)
      throw runtime_error("Les nombres de lignes et colonnes ainsi que le modulo "
                          "doivent etre strictement positifs.");

   matrix = allocateMatrix(n, m);

   for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
         auto& gen = RandomNumberGenerator::getInstance();
         unsigned rdm = gen.generate(0,(int)modulo - 1);
         matrix[i][j] = rdm;
      }
   }
}

Matrix::Matrix(const Matrix &other): Matrix(other.nbRows, other.nbCols, other
.modulo, other.matrix) {}

Matrix::~Matrix() {
   deleteMatrix(matrix, nbRows);
}

Matrix::Matrix(size_t nbRows, size_t nbCols, unsigned modulo, unsigned** otherMatrix) :
   nbRows(nbRows),
   nbCols(nbCols), modulo(modulo) {
   if (otherMatrix == nullptr)
      throw runtime_error("La matrice ne peut pas être un pointeur sur null");

   if (nbRows <= 0 || nbCols <= 0 || modulo <= 0)
      throw runtime_error("Les nombres de lignes et colonnes ainsi que le modulo "
                          "doivent etre strictement positifs.");

   matrix = allocateMatrix(nbRows, nbCols);

   for (size_t i = 0; i < nbRows; i++) {
         memcpy(matrix[i], otherMatrix[i], nbCols * sizeof(unsigned));
   }
}


unsigned** Matrix::allocateMatrix(size_t nbRows, size_t nbCols) {
   unsigned** matrix = new unsigned*[nbRows];

   for (size_t i = 0; i < nbRows; i++) {
      matrix[i] = new unsigned[nbCols];
   }
   return matrix;
}


Matrix Matrix::addStatic(const Matrix &other) {
   Matrix newMatrix(*this);
   operation(newMatrix, other, Add());
   return newMatrix;
}


Matrix Matrix::subStatic(const Matrix &other) {
   Matrix newMatrix(*this);
   operation(newMatrix, other, Sub());
   return newMatrix;
}


Matrix Matrix::multStatic(const Matrix &other) {
   Matrix newMatrix(*this);
   operation(newMatrix, other, Mult());
   return newMatrix;
}


void Matrix::addSelf(const Matrix &other) {
   operation(*this, other, Add());
}


void Matrix::subSelf(const Matrix &other) {
   operation(*this, other, Sub());
}


void Matrix::multSelf(const Matrix &other) {
   operation(*this, other, Mult());
}


Matrix* Matrix::addDynamic(const Matrix &other) {
   Matrix* newMatrix = new Matrix(*this);
   operation(*newMatrix, other, Add());
   return newMatrix;
}


Matrix* Matrix::subDynamic(const Matrix &other) {
   Matrix* newMatrix = new Matrix(*this);
   operation(*newMatrix, other, Sub());
   return newMatrix;
}


Matrix* Matrix::multDynamic(const Matrix &other) {
   Matrix* newMatrix = new Matrix(*this);
   operation(*newMatrix, other, Mult());
   return newMatrix;
}


void Matrix::operation(Matrix &m1, const Matrix &m2, const Operation &op) {
   if (m1.modulo != m2.modulo)
      throw invalid_argument("Les modulos des matrices sont differents.");

   size_t rowLengthMax = max(m1.getNbRows(), m2.getNbRows());
   size_t colLengthMax = max(m1.getNbCols(), m2.getNbCols());
   unsigned ** temp = m1.matrix;
   bool allocated = false;

   if (m1.getNbCols() < m2.getNbCols() || m1.getNbRows() < m2.getNbRows()) {
      m1.matrix = allocateMatrix(rowLengthMax, colLengthMax);
      allocated = true;

      if(temp == nullptr) {
         throw runtime_error("L'allocation de la nouvelle matrice a échoue.");
      }

   }

   for(size_t i = 0; i < rowLengthMax; i++){
      for(size_t j = 0; j < colLengthMax; j++){
         unsigned valM2 = i < m2.nbRows && j < m2.nbCols ? m2.matrix[i][j] : 0;
         unsigned valTemp = i < m1.nbRows && j < m1.nbCols ? temp[i][j] : 0;

         m1.matrix[i][j] = op.calculate(valTemp, valM2) % m1.modulo;
      }
   }

   if (allocated) {
      for (size_t i = 0; i < m1.nbRows; i++)
         delete[] temp[i];

      delete[] temp;
   }

   m1.nbRows = rowLengthMax;
   m1.nbCols = colLengthMax;
}


size_t Matrix::getNbRows() const {
   return nbRows;
}


size_t Matrix::getNbCols() const {
   return nbCols;
}

Matrix& Matrix::operator=(const Matrix &other) {
   if(&other == this) return *this;
   deleteMatrix(this->matrix, this->nbRows);
   this->matrix = allocateMatrix(other.nbRows, other.nbCols);

   for (int i = 0; i < other.nbRows; ++i) {
      memcpy(matrix[i], other.matrix[i], other.nbCols * sizeof(unsigned));
   }


   this->nbRows = other.nbRows;
   this->nbCols = other.nbCols;
   this->modulo = other.modulo;

   return *this;
}


void Matrix::deleteMatrix(unsigned int **matrixArray, size_t height) {
   if(matrixArray == nullptr){
      throw runtime_error("matrixArray is null");
   }
   for (int i = 0; i < height; ++i) {
         delete[] matrixArray[i];
   }
   delete[] matrixArray;
}

unsigned Matrix::getEl(size_t row, size_t col) {
   return matrix[row][col];
}
