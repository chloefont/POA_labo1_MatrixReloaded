#include <iostream>
#include "Application.h"

using namespace std;


int main(int argc, char** argv) {
   try {
      unsigned n1 = stoi(argv[1]);
      unsigned m1 = stoi(argv[2]);
      unsigned n2 = stoi(argv[3]);
      unsigned m2 = stoi(argv[4]);
      unsigned modulo = stoi(argv[5]);

      Application app(n1, m1, n2, m2, modulo);
   } catch (const exception& e) {
      cout << "Veuillez entrer les valeurs suivantes :" << endl
           << "\tn1 : nb lignes de la premiere matrice" << endl
           << "\tm1 : nb colonnes de la premiere matrice" << endl
           << "\tn2 : nb lignes de la deuxieme matrice" << endl
           << "\tm2 : nb colonnes de la deuxieme matrice" << endl
           << "\tmodulo : modulo a appliquer aux matrices" << endl;
   }


   return EXIT_SUCCESS;
}
