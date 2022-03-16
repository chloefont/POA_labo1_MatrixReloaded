#include <iostream>
#include "Matrix.h"

using namespace std;


int main() {
   Matrix m(5, 5, 5);
   Matrix m2(4, 4, 5);

   Matrix* ptr = nullptr;

   m = *ptr;

   cout << m << endl << m2 << endl;
   m.addStatic(m2);
   cout << m;
   return 0;
}
