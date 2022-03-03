//
// Created by cfont on 24.02.2022.
//

#ifndef POA_LABO1_MATRIXRELOADED_MATRIX_H
#define POA_LABO1_MATRIXRELOADED_MATRIX_H


class Matrix {
public:
   Matrix(size_t N, size_t M, unsigned modulo);



private:
   int** matrix;
   int modulo;
};


#endif //POA_LABO1_MATRIXRELOADED_MATRIX_H
