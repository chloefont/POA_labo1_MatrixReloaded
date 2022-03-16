#include <iostream>
#include "Application.h"

using namespace std;


int main(int argc, char** argv) {
   unsigned n1 = stoi(argv[1]);
   unsigned m1 = stoi(argv[2]);
   unsigned n2 = stoi(argv[3]);
   unsigned m2 = stoi(argv[4]);
   unsigned modulo = stoi(argv[5]);

   Application app(n1, m1, n2, m2, modulo);

   return EXIT_SUCCESS;
}
