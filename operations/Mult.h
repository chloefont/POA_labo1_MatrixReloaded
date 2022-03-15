//
// Created by cfont on 24.02.2022.
//

#ifndef POA_LABO1_MATRIXRELOADED_MULT_H
#define POA_LABO1_MATRIXRELOADED_MULT_H

#include "Operation.h"

class Mult : public Operation {
public:
   int calculate(int num1, int num2) const override;
};


#endif //POA_LABO1_MATRIXRELOADED_MULT_H
