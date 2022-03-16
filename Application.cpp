//
// Created by cfont on 24.02.2022.
//

#include "Application.h"
#include "Matrix.h"

using namespace std;

Application::Application(unsigned int n1, unsigned int m1, unsigned int n2,
                         unsigned int m2, unsigned modulo) {
   Matrix matrice1(n1,m1,modulo);
   Matrix matrice2(n2,m2,modulo);

   cout << "-- one" << endl;
   cout << matrice1 << endl;
   cout << "-- two" << endl;
   cout << matrice2 << endl << endl;

   Matrix cp1matrice1(matrice1);

   cout << "-- one + two" << endl;
   cout << "- dynamic" << endl;
   cout << *cp1matrice1.addDynamic(matrice2) << endl;
   cout << "- static" << endl;
   cout << cp1matrice1.addStatic(matrice2) << endl;
   cout << "- self" << endl;
   cp1matrice1.addSelf(matrice2);
   cout << cp1matrice1 << endl << endl;

   Matrix cp2matrice1(matrice1);

   cout << "-- one - two" << endl;
   cout << "- dynamic" << endl;
   cout << *cp2matrice1.subDynamic(matrice2) << endl;
   cout << "- static" << endl;
   cout << cp2matrice1.subStatic(matrice2) << endl;
   cout << "- self" << endl;
   cp2matrice1.subSelf(matrice2);
   cout << cp2matrice1 << endl << endl;

   Matrix cp3matrice1(matrice1);

   cout << "-- one * two" << endl;
   cout << "- dynamic" << endl;
   cout << *cp3matrice1.multDynamic(matrice2) << endl;
   cout << "- static" << endl;
   cout << cp3matrice1.multStatic(matrice2) << endl;
   cout << "- self" << endl;
   cp3matrice1.multSelf(matrice2);
   cout << cp3matrice1 << endl;

}
