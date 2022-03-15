#include "Tests.h"

int main() {
   Tests::buildCorrectMatrixWithRandomConstructor();
   Tests::buildMatrixWithNullNbRows();
   Tests::buildMatrixWithNullNbCols();
   Tests::buildMatrixWithNullModulo();
   Tests::buildCorrectMatrixWithCopyConstructor();
   Tests::affectationOperator();

   Tests::correctAddStaticWithSameSize();
   Tests::correctAddStaticWithDifferentSize();
   Tests::addStaticWithDifferentModulo();
   Tests::correctAddSelfWithSameSize();
   Tests::correctAddSelfWithDifferentSize();
   Tests::addSelfWithDifferentModulo();
   Tests::correctAddDynamicWithSameSize();
   Tests::correctAddDynamicWithDifferentSize();
   Tests::addDynamicWithDifferentModulo();

   Tests::correctSubStaticWithSameSize();
   Tests::correctSubStaticWithDifferentSize();
   Tests::subStaticWithDifferentModulo();
   Tests::correctSubSelfWithSameSize();
   Tests::correctSubSelfWithDifferentSize();
   Tests::subSelfWithDifferentModulo();
   Tests::correctSubDynamicWithSameSize();
   Tests::correctSubDynamicWithDifferentSize();
   Tests::subDynamicWithDifferentModulo();

   Tests::correctMultStaticWithSameSize();
   Tests::correctMultStaticWithDifferentSize();
   Tests::multStaticWithDifferentModulo();
   Tests::correctMultSelfWithSameSize();
   Tests::correctMultSelfWithDifferentSize();
   Tests::multSelfWithDifferentModulo();
   Tests::correctMultDynamicWithSameSize();
   Tests::correctMultDynamicWithDifferentSize();
   Tests::multDynamicWithDifferentModulo();
   return 0;
}