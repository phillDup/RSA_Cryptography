#include "vector"

class PrimeGenerator
{   

    public:
        PrimeGenerator();
        virtual	~PrimeGenerator();
        virtual long long int getPrimeGreaterThan(int lowerBound) = 0;
        virtual std::vector<long long int> getPrimes() = 0;

};