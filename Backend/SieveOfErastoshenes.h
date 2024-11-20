#include "PrimeGenerator.h"

#include <vector>

class SieveOfErastoshenes : public PrimeGenerator
{

    private:
        std::vector<bool> numberList;
        int bound;

    public:
        SieveOfErastoshenes();
        ~SieveOfErastoshenes();
        long long int getPrime() override;

};