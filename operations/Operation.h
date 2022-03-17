#ifndef POA_LABO1_MATRIXRELOADED_OPERATION_H
#define POA_LABO1_MATRIXRELOADED_OPERATION_H


class Operation {
public:
   /**
    * @brief Does an operation on two numbers and returns the result.
    * 
    * @param num1 
    * @param num2 
    * @return unsigned
    */
   virtual unsigned calculate(unsigned num1, unsigned num2) const = 0;
};

#endif //POA_LABO1_MATRIXRELOADED_OPERATION_H
