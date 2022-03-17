#include <cstdlib>
#include <ctime>
#include "RandomNumberGenerator.h"

int RandomNumberGenerator::generate(int min, int max) {
   int randNum = rand() % (max - min + 1) + min;
   return randNum;
}

RandomNumberGenerator::RandomNumberGenerator() {
   srand((unsigned) time(0));
}

RandomNumberGenerator &RandomNumberGenerator::getInstance() {
   static RandomNumberGenerator instance;
   return instance;
}
