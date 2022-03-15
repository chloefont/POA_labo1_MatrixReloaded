//
// Created by cfont on 24.02.2022.
//

#ifndef POA_LABO1_MATRIXRELOADED_ADD_H
#define POA_LABO1_MATRIXRELOADED_ADD_H

#include "Operation.h"


class Add : public Operation {
public:
   /**
    * @brief Does an addition on two numbers and returns the result.
    * 
    * @param num1 
    * @param num2 
    * @return int 
    */
   int calculate(int num1, int num2) const override;
};


#endif //POA_LABO1_MATRIXRELOADED_ADD_H
