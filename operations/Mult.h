//
// Created by cfont on 24.02.2022.
//

#ifndef POA_LABO1_MATRIXRELOADED_MULT_H
#define POA_LABO1_MATRIXRELOADED_MULT_H

#include "Operation.h"

class Mult : public Operation {
public:
   /**
    * @brief Does a multiplication on two numbers and returns the result.
    * 
    * @param num1 
    * @param num2 
    * @return unsigned
    */
   unsigned calculate(unsigned num1, unsigned num2) const override;
};


#endif //POA_LABO1_MATRIXRELOADED_MULT_H
