#include "Tests.h"

int main() {
   Tests::buildCorrectMatrixWithRandomConstructor();
   Tests::buildMatrixWithNullNbRows();
   Tests::buildMatrixWithNullNbCols();
   Tests::buildMatrixWithNullModulo();
   Tests::buildCorrectMatrixWithCopyConstructor();
   Tests::affectationOperator();
   return 0;
}