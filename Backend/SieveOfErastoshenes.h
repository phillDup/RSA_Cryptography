#include "PrimeGenerator.h"
#include <iostream>

class SieveOfErastoshenes : public PrimeGenerator
{

    private:
        std::vector<bool> numberList;
        int bound;

    public:
        SieveOfErastoshenes(int size);
        ~SieveOfErastoshenes();
        long long int getPrimeGreaterThan(int lowerBound) override;
        std::vector<long long int> getPrimes() override;
        void printSieve();

};