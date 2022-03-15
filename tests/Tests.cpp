//
// Created by cfont on 15.03.2022.
//

#include "Tests.h"
#include "../Matrix.h"

using namespace std;

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

void Tests::printResults(std::string testName, std::string expected, std::string
got) {
   cout << "Test " << testName << endl
        << "\texpected : " << expected << endl
        << "\tgot : " << got << endl;
}

void Tests::affectationOperator() {
   size_t nbRows = 5,
      nbCols = 5,
      nbRows2 = 7,
      nbCols2 = 9;
   unsigned modulo = 7, modulo2 = 10;

   string expected = "ok",
      got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(nbRows2, nbCols2, modulo);

      if (m1 != m2)
         got = "failed";
   } catch (const runtime_error& e) {
      got = "failed";
   }

   printResults("build correct matrix with copy contructor", expected, got);
}




