#include <iostream>
#include "Matrix.h"

using namespace std;


int main() {
   Matrix m(5, 5, 5);
   Matrix m2(4, 4, 6);

   cout << m << endl << m2 << endl;
   m.addStatic(m2);
   cout << m;
   return 0;
}
