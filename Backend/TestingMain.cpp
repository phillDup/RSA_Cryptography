#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <set>

#include "SieveOfErastoshenes.h"

TEST_CASE("SieveOfErastoshenes_Test")
{
    SUBCASE("Prime generation up to 30")
    {
        SieveOfErastoshenes sieve(30);
        sieve.printSieve();

        // Check all contained primes are correct
        std::vector<int> prime_1_to_30 = {2,3,5,7,11,13,17,19,23,29};
        std::vector<long long int> calculatedPrimes_1_to_30 = sieve.getPrimes();

        CHECK(prime_1_to_30.size() == calculatedPrimes_1_to_30.size());
        for(u_int i=0; i<prime_1_to_30.size(); i++)
        {
            CHECK(prime_1_to_30.at(i) == calculatedPrimes_1_to_30.at(i));
        }

    }

    SUBCASE("getPrimeGreater than ")
    {
        SieveOfErastoshenes sieve(30);

        CHECK(sieve.getPrimeGreaterThan(0) > 0);
        CHECK(sieve.getPrimeGreaterThan(29) == -1);
        int result = sieve.getPrimeGreaterThan(13);
        std::set<int> validPrimes = {17, 19, 23, 29};
        CHECK(validPrimes.count(result) > 0); 


    }

    SUBCASE("Prime generation up to 10000")
    {
        SieveOfErastoshenes sieve(1000);
        sieve.printSieve();
    }
}