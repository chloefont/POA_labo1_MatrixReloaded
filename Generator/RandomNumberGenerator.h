#ifndef POA_LABO1_MATRIXRELOADED_RANDOMNUMBERGENERATOR_H
#define POA_LABO1_MATRIXRELOADED_RANDOMNUMBERGENERATOR_H


class RandomNumberGenerator {
public:

   int generate(int min, int max);

   static RandomNumberGenerator &getInstance();

   RandomNumberGenerator(RandomNumberGenerator const &) = delete;

   RandomNumberGenerator &operator=(RandomNumberGenerator const &) = delete;

private:
   RandomNumberGenerator();
};


#endif //POA_LABO1_MATRIXRELOADED_RANDOMNUMBERGENERATOR_H
