//
// Created by cfont on 15.03.2022.
//

#include "Tests.h"
#include "../Matrix.h"

using namespace std;

void Tests::printResults(std::string testName, std::string expected, std::string
got) {
   cout << "Test " << testName << endl
        << "\texpected : " << expected << endl
        << "\tgot : " << got << endl;
}

void Tests::buildCorrectMatrixWithRandomConstructor() {
   size_t nbRows = 5,
          nbCols = 5;
   unsigned modulo = 7;

   string expected = "ok",
          got = "ok";

   try {
      Matrix m(nbRows, nbCols, modulo);
   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("build correct matrix with random contructor", expected, got);
}

void Tests::buildMatrixWithNullNbRows() {
   size_t nbRows = 0,
      nbCols = 5;
   unsigned modulo = 7;

   string expected = "failed",
      got = "ok";

   try {
      Matrix m(nbRows, nbCols, modulo);
   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("build matrix with null number of rows", expected, got);
}

void Tests::buildMatrixWithNullNbCols() {
   size_t nbRows = 5,
          nbCols = 0;
   unsigned modulo = 7;

   string expected = "failed",
      got = "ok";

   try {
      Matrix m(nbRows, nbCols, modulo);
   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("build matrix with null number of cols", expected, got);
}

void Tests::buildMatrixWithNullModulo() {
   size_t nbRows = 5,
          nbCols = 5;
   unsigned modulo = 0;

   string expected = "failed",
      got = "ok";

   try {
      Matrix m(nbRows, nbCols, modulo);
   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("build matrix with null modulo", expected, got);
}

void Tests::buildCorrectMatrixWithCopyConstructor() {
   size_t nbRows = 5,
          nbCols = 5;
   unsigned modulo = 7;

   string expected = "ok",
          got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(m1);

      if (m1 != m2)
         got = "failed";
   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("build correct matrix with copy contructor", expected, got);
}

void Tests::affectationOperator() {
   size_t nbRows = 5,
      nbCols = 5,
      nbRows2 = 7,
      nbCols2 = 9;
   unsigned modulo = 7,
      modulo2 = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows2, nbCols2, modulo2);

      m1 = m2;

      if (m1 != m2)
         got = "failed";
   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("affection operator", expected, got);
}

void Tests::correctAddStaticWithSameSize() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows, nbCols, modulo);

      Matrix m3 = m1.addStatic(m2);

      if (m3.getNbRows() != nbRows || m3.getNbCols() != nbCols)
         got = "failed";

      for (size_t i = 0; i < nbRows; i++) {
         for (size_t j = 0; j < nbCols; j++) {
            if (m3.getEl(i, j) != (m1.getEl(i, j) + m2.getEl(i, j)) % modulo)
               got = "failed";
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct static addition with same size", expected, got);
}

void Tests::correctAddStaticWithDifferentSize() {
   const size_t nbRows1 = 4,
      nbCols1 = 3,
      nbRows2 = 3,
      nbCols2 = 4;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows1, nbCols1, modulo);
      Matrix m2(nbRows2, nbCols2, modulo);

      Matrix m3 = m1.addStatic(m2);

      if (m3.getNbRows() != nbRows1 || m3.getNbCols() != nbCols2)
         got = "failed";
      else {
         for (size_t i = 0; i < nbRows1; i++) {
            for (size_t j = 0; j < nbCols2; j++) {

               unsigned val1 = i < m1.getNbRows() && j < m1.getNbCols() ? m1.getEl
                  (i, j) : 0;
               unsigned val2 = i < m2.getNbRows() && j < m2.getNbCols() ? m2.getEl
                  (i, j) : 0;

               if (m3.getEl(i, j) != (val1 + val2) % modulo)
                  got = "failed";
            }
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct static addition with different size", expected, got);
}

void Tests::addStaticWithDifferentModulo() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo1 = 10,
      modulo2 = 7;

   string expected = "failed",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo1);
      Matrix m2(nbRows, nbCols, modulo2);

      Matrix m3 = m1.addStatic(m2);

   } catch (const invalid_argument& e) {
      got = "failed";
   }

   printResults("static addition with different modulo", expected, got);
}

void Tests::correctAddSelfWithSameSize() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows, nbCols, modulo);
      Matrix tmp(m1);

      m1.addSelf(m2);

      if (m1.getNbRows() != nbRows || m1.getNbCols() != nbCols)
         got = "failed";

      for (size_t i = 0; i < nbRows; i++) {
         for (size_t j = 0; j < nbCols; j++) {
            if (m1.getEl(i, j) != (tmp.getEl(i, j) + m2.getEl(i, j)) % modulo)
               got = "failed";
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct self addition with same size", expected, got);
}

void Tests::correctAddSelfWithDifferentSize() {
   const size_t nbRows1 = 4,
      nbCols1 = 3,
      nbRows2 = 3,
      nbCols2 = 4;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows1, nbCols1, modulo);
      Matrix m2(nbRows2, nbCols2, modulo);
      Matrix tmp(m1);

      m1.addSelf(m2);

      if (m1.getNbRows() != nbRows1 || m1.getNbCols() != nbCols2)
         got = "failed";
      else {
         for (size_t i = 0; i < nbRows1; i++) {
            for (size_t j = 0; j < nbCols2; j++) {

               unsigned val1 = i < tmp.getNbRows() && j < tmp.getNbCols() ? tmp.getEl
                  (i, j) : 0;
               unsigned val2 = i < m2.getNbRows() && j < m2.getNbCols() ? m2.getEl
                  (i, j) : 0;

               if (m1.getEl(i, j) != (val1 + val2) % modulo)
                  got = "failed";
            }
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct self addition with different size", expected, got);
}

void Tests::addSelfWithDifferentModulo() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo1 = 10,
      modulo2 = 7;

   string expected = "failed",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo1);
      Matrix m2(nbRows, nbCols, modulo2);

      m1.addSelf(m2);

   } catch (const invalid_argument& e) {
      got = "failed";
   }

   printResults("self addition with different modulo", expected, got);
}

void Tests::correctAddDynamicWithSameSize() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   Matrix* m3;

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows, nbCols, modulo);

      m3 = m1.addDynamic(m2);

      if (m3->getNbRows() != nbRows || m3->getNbCols() != nbCols)
         got = "failed";

      for (size_t i = 0; i < nbRows; i++) {
         for (size_t j = 0; j < nbCols; j++) {
            if (m3->getEl(i, j) != (m1.getEl(i, j) + m2.getEl(i, j)) % modulo)
               got = "failed";
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
      delete m3;
   }

   delete m3;

   printResults("correct dynamic addition with same size", expected, got);
}

void Tests::correctAddDynamicWithDifferentSize() {
   const size_t nbRows1 = 4,
      nbCols1 = 3,
      nbRows2 = 3,
      nbCols2 = 4;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   Matrix* m3;

   try {
      Matrix m1(nbRows1, nbCols1, modulo);
      Matrix m2(nbRows2, nbCols2, modulo);

      m3 = m1.addDynamic(m2);

      if (m3->getNbRows() != nbRows1 || m3->getNbCols() != nbCols2)
         got = "failed";
      else {
         for (size_t i = 0; i < nbRows1; i++) {
            for (size_t j = 0; j < nbCols2; j++) {

               unsigned val1 = i < m1.getNbRows() && j < m1.getNbCols() ? m1.getEl
                  (i, j) : 0;
               unsigned val2 = i < m2.getNbRows() && j < m2.getNbCols() ? m2.getEl
                  (i, j) : 0;

               if (m3->getEl(i, j) != (val1 + val2) % modulo)
                  got = "failed";
            }
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
      delete m3;
   }

   delete m3;

   printResults("correct dynamic addition with different size", expected, got);
}

void Tests::addDynamicWithDifferentModulo() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo1 = 10,
      modulo2 = 7;

   string expected = "failed",
      got = "ok";

   Matrix* m3;
   try {
      Matrix m1(nbRows, nbCols, modulo1);
      Matrix m2(nbRows, nbCols, modulo2);

      m3 = m1.addDynamic(m2);

      delete m3;

   } catch (const invalid_argument& e) {
      got = "failed";
   }

   printResults("dynamic addition with different modulo", expected, got);
}

void Tests::correctSubStaticWithSameSize() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows, nbCols, modulo);

      Matrix m3 = m1.subStatic(m2);

      if (m3.getNbRows() != nbRows || m3.getNbCols() != nbCols)
         got = "failed";

      for (size_t i = 0; i < nbRows; i++) {
         for (size_t j = 0; j < nbCols; j++) {
            if (m3.getEl(i, j) != (m1.getEl(i, j) - m2.getEl(i, j)) % modulo)
               got = "failed";
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct static substraction with same size", expected, got);
}

void Tests::correctSubStaticWithDifferentSize() {
   const size_t nbRows1 = 4,
      nbCols1 = 3,
      nbRows2 = 3,
      nbCols2 = 4;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows1, nbCols1, modulo);
      Matrix m2(nbRows2, nbCols2, modulo);

      Matrix m3 = m1.subStatic(m2);

      if (m3.getNbRows() != nbRows1 || m3.getNbCols() != nbCols2)
         got = "failed";
      else {
         for (size_t i = 0; i < nbRows1; i++) {
            for (size_t j = 0; j < nbCols2; j++) {

               unsigned val1 = i < m1.getNbRows() && j < m1.getNbCols() ? m1.getEl
                  (i, j) : 0;
               unsigned val2 = i < m2.getNbRows() && j < m2.getNbCols() ? m2.getEl
                  (i, j) : 0;

               if (m3.getEl(i, j) != (val1 - val2) % modulo)
                  got = "failed";
            }
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct static substraction with different size", expected, got);
}

void Tests::subStaticWithDifferentModulo() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo1 = 10,
      modulo2 = 7;

   string expected = "failed",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo1);
      Matrix m2(nbRows, nbCols, modulo2);

      Matrix m3 = m1.subStatic(m2);

   } catch (const invalid_argument& e) {
      got = "failed";
   }

   printResults("static substraction with different modulo", expected, got);
}

void Tests::correctSubSelfWithSameSize() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows, nbCols, modulo);
      Matrix tmp(m1);

      m1.subSelf(m2);

      if (m1.getNbRows() != nbRows || m1.getNbCols() != nbCols)
         got = "failed";

      for (size_t i = 0; i < nbRows; i++) {
         for (size_t j = 0; j < nbCols; j++) {
            if (m1.getEl(i, j) != (tmp.getEl(i, j) - m2.getEl(i, j)) % modulo)
               got = "failed";
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct self substraction with same size", expected, got);
}

void Tests::correctSubSelfWithDifferentSize() {
   const size_t nbRows1 = 4,
      nbCols1 = 3,
      nbRows2 = 3,
      nbCols2 = 4;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows1, nbCols1, modulo);
      Matrix m2(nbRows2, nbCols2, modulo);
      Matrix tmp(m1);

      m1.subSelf(m2);

      if (m1.getNbRows() != nbRows1 || m1.getNbCols() != nbCols2)
         got = "failed";
      else {
         for (size_t i = 0; i < nbRows1; i++) {
            for (size_t j = 0; j < nbCols2; j++) {

               unsigned val1 = i < tmp.getNbRows() && j < tmp.getNbCols() ? tmp.getEl
                  (i, j) : 0;
               unsigned val2 = i < m2.getNbRows() && j < m2.getNbCols() ? m2.getEl
                  (i, j) : 0;

               if (m1.getEl(i, j) != (val1 - val2) % modulo)
                  got = "failed";
            }
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct self substraction with different size", expected, got);
}

void Tests::subSelfWithDifferentModulo() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo1 = 10,
      modulo2 = 7;

   string expected = "failed",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo1);
      Matrix m2(nbRows, nbCols, modulo2);

      m1.subSelf(m2);

   } catch (const invalid_argument& e) {
      got = "failed";
   }

   printResults("self substraction with different modulo", expected, got);
}

void Tests::correctSubDynamicWithSameSize() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   Matrix* m3;

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows, nbCols, modulo);

      m3 = m1.subDynamic(m2);

      if (m3->getNbRows() != nbRows || m3->getNbCols() != nbCols)
         got = "failed";

      for (size_t i = 0; i < nbRows; i++) {
         for (size_t j = 0; j < nbCols; j++) {
            if (m3->getEl(i, j) != (m1.getEl(i, j) - m2.getEl(i, j)) % modulo)
               got = "failed";
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
      delete m3;
   }

   delete m3;

   printResults("correct dynamic substraction with same size", expected, got);
}

void Tests::correctSubDynamicWithDifferentSize() {
   const size_t nbRows1 = 4,
      nbCols1 = 3,
      nbRows2 = 3,
      nbCols2 = 4;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   Matrix* m3;

   try {
      Matrix m1(nbRows1, nbCols1, modulo);
      Matrix m2(nbRows2, nbCols2, modulo);

      m3 = m1.subDynamic(m2);

      if (m3->getNbRows() != nbRows1 || m3->getNbCols() != nbCols2)
         got = "failed";
      else {
         for (size_t i = 0; i < nbRows1; i++) {
            for (size_t j = 0; j < nbCols2; j++) {

               unsigned val1 = i < m1.getNbRows() && j < m1.getNbCols() ? m1.getEl
                  (i, j) : 0;
               unsigned val2 = i < m2.getNbRows() && j < m2.getNbCols() ? m2.getEl
                  (i, j) : 0;

               if (m3->getEl(i, j) != (val1 - val2) % modulo)
                  got = "failed";
            }
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
      delete m3;
   }

   delete m3;

   printResults("correct dynamic substraction with different size", expected, got);
}

void Tests::subDynamicWithDifferentModulo() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo1 = 10,
      modulo2 = 7;

   string expected = "failed",
      got = "ok";

   Matrix* m3;
   try {
      Matrix m1(nbRows, nbCols, modulo1);
      Matrix m2(nbRows, nbCols, modulo2);

      m3 = m1.subDynamic(m2);

      delete m3;

   } catch (const invalid_argument& e) {
      got = "failed";
   }

   printResults("dynamic substraction with different modulo", expected, got);
}

void Tests::correctMultStaticWithSameSize() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows, nbCols, modulo);

      Matrix m3 = m1.multStatic(m2);

      if (m3.getNbRows() != nbRows || m3.getNbCols() != nbCols)
         got = "failed";

      for (size_t i = 0; i < nbRows; i++) {
         for (size_t j = 0; j < nbCols; j++) {
            if (m3.getEl(i, j) != (m1.getEl(i, j) * m2.getEl(i, j)) % modulo)
               got = "failed";
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct static multiplication with same size", expected, got);
}

void Tests::correctMultStaticWithDifferentSize() {
   const size_t nbRows1 = 4,
      nbCols1 = 3,
      nbRows2 = 3,
      nbCols2 = 4;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows1, nbCols1, modulo);
      Matrix m2(nbRows2, nbCols2, modulo);

      Matrix m3 = m1.multStatic(m2);

      if (m3.getNbRows() != nbRows1 || m3.getNbCols() != nbCols2)
         got = "failed";
      else {
         for (size_t i = 0; i < nbRows1; i++) {
            for (size_t j = 0; j < nbCols2; j++) {

               unsigned val1 = i < m1.getNbRows() && j < m1.getNbCols() ? m1.getEl
                  (i, j) : 0;
               unsigned val2 = i < m2.getNbRows() && j < m2.getNbCols() ? m2.getEl
                  (i, j) : 0;

               if (m3.getEl(i, j) != (val1 * val2) % modulo)
                  got = "failed";
            }
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct static multiplication with different size", expected, got);
}

void Tests::multStaticWithDifferentModulo() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo1 = 10,
      modulo2 = 7;

   string expected = "failed",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo1);
      Matrix m2(nbRows, nbCols, modulo2);

      Matrix m3 = m1.multStatic(m2);

   } catch (const invalid_argument& e) {
      got = "failed";
   }

   printResults("static multiplication with different modulo", expected, got);
}

void Tests::correctMultSelfWithSameSize() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows, nbCols, modulo);
      Matrix tmp(m1);

      m1.multSelf(m2);

      if (m1.getNbRows() != nbRows || m1.getNbCols() != nbCols)
         got = "failed";

      for (size_t i = 0; i < nbRows; i++) {
         for (size_t j = 0; j < nbCols; j++) {
            if (m1.getEl(i, j) != (tmp.getEl(i, j) * m2.getEl(i, j)) % modulo)
               got = "failed";
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct self multiplication with same size", expected, got);
}

void Tests::correctMultSelfWithDifferentSize() {
   const size_t nbRows1 = 4,
      nbCols1 = 3,
      nbRows2 = 3,
      nbCols2 = 4;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows1, nbCols1, modulo);
      Matrix m2(nbRows2, nbCols2, modulo);
      Matrix tmp(m1);

      m1.multSelf(m2);

      if (m1.getNbRows() != nbRows1 || m1.getNbCols() != nbCols2)
         got = "failed";
      else {
         for (size_t i = 0; i < nbRows1; i++) {
            for (size_t j = 0; j < nbCols2; j++) {

               unsigned val1 = i < tmp.getNbRows() && j < tmp.getNbCols() ? tmp.getEl
                  (i, j) : 0;
               unsigned val2 = i < m2.getNbRows() && j < m2.getNbCols() ? m2.getEl
                  (i, j) : 0;

               if (m1.getEl(i, j) != (val1 * val2) % modulo)
                  got = "failed";
            }
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("correct self multiplication with different size", expected, got);
}

void Tests::multSelfWithDifferentModulo() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo1 = 10,
      modulo2 = 7;

   string expected = "failed",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo1);
      Matrix m2(nbRows, nbCols, modulo2);

      m1.multSelf(m2);

   } catch (const invalid_argument& e) {
      got = "failed";
   }

   printResults("self multiplication with different modulo", expected, got);
}

void Tests::correctMultDynamicWithSameSize() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   Matrix* m3;

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows, nbCols, modulo);

      m3 = m1.multDynamic(m2);

      if (m3->getNbRows() != nbRows || m3->getNbCols() != nbCols)
         got = "failed";

      for (size_t i = 0; i < nbRows; i++) {
         for (size_t j = 0; j < nbCols; j++) {
            if (m3->getEl(i, j) != (m1.getEl(i, j) * m2.getEl(i, j)) % modulo)
               got = "failed";
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
      delete m3;
   }

   delete m3;

   printResults("correct dynamic multiplication with same size", expected, got);
}

void Tests::correctMultDynamicWithDifferentSize() {
   const size_t nbRows1 = 4,
      nbCols1 = 3,
      nbRows2 = 3,
      nbCols2 = 4;
   unsigned modulo = 10;

   string expected = "ok",
      got = "ok";

   Matrix* m3;

   try {
      Matrix m1(nbRows1, nbCols1, modulo);
      Matrix m2(nbRows2, nbCols2, modulo);

      m3 = m1.multDynamic(m2);

      if (m3->getNbRows() != nbRows1 || m3->getNbCols() != nbCols2)
         got = "failed";
      else {
         for (size_t i = 0; i < nbRows1; i++) {
            for (size_t j = 0; j < nbCols2; j++) {

               unsigned val1 = i < m1.getNbRows() && j < m1.getNbCols() ? m1.getEl
                  (i, j) : 0;
               unsigned val2 = i < m2.getNbRows() && j < m2.getNbCols() ? m2.getEl
                  (i, j) : 0;

               if (m3->getEl(i, j) != (val1 * val2) % modulo)
                  got = "failed";
            }
         }
      }

   } catch (const runtime_error& e) {
      got = "failed";
      delete m3;
   }

   delete m3;

   printResults("correct dynamic multiplication with different size", expected, got);
}

void Tests::multDynamicWithDifferentModulo() {
   const size_t nbRows = 3,
      nbCols = 3;
   unsigned modulo1 = 10,
      modulo2 = 7;

   string expected = "failed",
      got = "ok";

   Matrix* m3;
   try {
      Matrix m1(nbRows, nbCols, modulo1);
      Matrix m2(nbRows, nbCols, modulo2);

      m3 = m1.multDynamic(m2);

      delete m3;

   } catch (const invalid_argument& e) {
      got = "failed";
   }

   printResults("dynamic multiplication with different modulo", expected, got);
}

