#include "Tests.h"

int main() {
   Tests::buildCorrectMatrixWithRandomConstructor();
   Tests::buildMatrixWithNullNbRows();
   Tests::buildMatrixWithNullNbCols();
   Tests::buildCorrectMatrixWithCopyConstructor();
   return 0;
}