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

   static void correctAddStaticWithSameSize();

   static void correctAddStaticWithDifferentSize();

   static void addStaticWithDifferentModulo();

   static void correctAddSelfWithSameSize();

   static void correctAddSelfWithDifferentSize();

   static void addSelfWithDifferentModulo();

   static void correctAddDynamicWithSameSize();

   static void correctAddDynamicWithDifferentSize();

   static void addDynamicWithDifferentModulo();

   static void correctSubStaticWithSameSize();

   static void correctSubStaticWithDifferentSize();

   static void subStaticWithDifferentModulo();

   static void correctSubSelfWithSameSize();

   static void correctSubSelfWithDifferentSize();

   static void subSelfWithDifferentModulo();

   static void correctSubDynamicWithSameSize();

   static void correctSubDynamicWithDifferentSize();

   static void subDynamicWithDifferentModulo();

   static void correctMultStaticWithSameSize();

   static void correctMultStaticWithDifferentSize();

   static void multStaticWithDifferentModulo();

   static void correctMultSelfWithSameSize();

   static void correctMultSelfWithDifferentSize();

   static void multSelfWithDifferentModulo();

   static void correctMultDynamicWithSameSize();

   static void correctMultDynamicWithDifferentSize();

   static void multDynamicWithDifferentModulo();

   static void affectationOperator();

private:
   static void printResults(std::string testName, std::string expected, std::string
   got);
};


#endif //POA_LABO1_MATRIXRELOADED_TESTS_H
