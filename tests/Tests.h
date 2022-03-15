//
// Created by cfont on 15.03.2022.
//

#ifndef POA_LABO1_MATRIXRELOADED_TESTS_H
#define POA_LABO1_MATRIXRELOADED_TESTS_H


#include <string>

class Tests {
public:
   static void buildCorrectMatrixWithRandomConstructor();

   static void buildMatrixWithNullNbRows();

   static void buildMatrixWithNullNbCols();

   static void buildMatrixWithNullModulo();

   static void buildCorrectMatrixWithCopyConstructor();

   static void correctAdditionWithSameSize();

   static void wrongAdditionWithSameSize();

   static void correctSoustractionWithSameSize();

   static void correctMultiplicationWithSameSize();

   static void additionWithDifferentRows();

   static void additionWithDifferentColumns();

   static void affectationOperator();

private:
   static void printResults(std::string testName, std::string expected, std::string
   got);
};


#endif //POA_LABO1_MATRIXRELOADED_TESTS_H
