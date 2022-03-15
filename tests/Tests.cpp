//
// Created by cfont on 15.03.2022.
//

#include "Tests.h"
#include "../Matrix.h"

using namespace std;

void Tests::buildCorrectMatrixWithRandomConstructor() {
   size_t nbRows = 5,
          nbCols = 5;
   int modulo = 7;

   string expected = "ok",
          got = "ok";

   try {
      Matrix m(nbRows, nbCols, modulo);
   } catch (runtime_error e) {
      got = "failed";
   }

   printResults("build correct matrix with random contructor", expected, got);
}

void Tests::buildCorrectMatrixWithCopyConstructor() {
   size_t nbRows = 5,
          nbCols = 5;
   int modulo = 7;

   string expected = "ok",
          got = "ok";

   try {
      Matrix m1(nbRows, nbCols, modulo);
      Matrix m2(m1);

      cout << m1 << endl << m2 << endl;

      if (!Matrix::equals(m1, m2))
         got = "failed";
   } catch (runtime_error e) {
      got = "failed";
   }

   printResults("build correct matrix with copy contructor", expected, got);
}

void
Tests::printResults(std::string testName, std::string expected, std::string got) {
   cout << "Test " << testName << endl
        << "\texpected : " << expected << endl
        << "\tgot : " << got << endl;
}
