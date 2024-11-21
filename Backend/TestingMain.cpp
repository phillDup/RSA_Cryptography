#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <set>

#include "SieveOfErastoshenes.h"
#include "KeyPair.h"

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

// Mock class that instantiates a KeyPair and has friend class Key Pair
// This allows testing of private methods in KeyPair
class MockKeyPairTester
{

    private:
        KeyPair* testKeyPair;

    public: 
        MockKeyPairTester() {testKeyPair = new KeyPair(nullptr);};
        ~MockKeyPairTester() {delete testKeyPair;};
        int testExtendedEuclid(int testNum1, int testNum2) {
            int gcd = testKeyPair->extendedEuclideanAlgorithm(testNum1, testNum2);
            return gcd;
        };

};

TEST_CASE("KeyPair_Test")
{   

    SUBCASE("Test extended euclidean algorithm")
    {   
        MockKeyPairTester mockKeyPair;
        int gcd_17_5 = mockKeyPair.testExtendedEuclid(17, 5);
        CHECK(gcd_17_5 == 1);
        MESSAGE("GCD(17,5) Calculated: " << gcd_17_5);

        int gcd_5_17 = mockKeyPair.testExtendedEuclid(5, 17);
        CHECK(gcd_5_17 == 1);
        MESSAGE("GCD(5,17) Calculated: " << gcd_5_17);

        int gcd_0_0 = mockKeyPair.testExtendedEuclid(0, 0);
        CHECK(gcd_0_0 == 0);
        MESSAGE("GCD(0,0) Calculated: " << gcd_0_0);

        int gcd_14_14 = mockKeyPair.testExtendedEuclid(14, 14);
        CHECK(gcd_14_14 == 14);
        MESSAGE("GCD(14,14) Calculated: " << gcd_14_14);

        int gcd_large = mockKeyPair.testExtendedEuclid(32523, 333);
        CHECK(gcd_large == 111);
        MESSAGE("GCD(32523,333) Calculated: " << gcd_large);
        
        int gcd_other = mockKeyPair.testExtendedEuclid(22, 2222);
        CHECK(gcd_other == 22);
        MESSAGE("GCD(22,2222) Calculated: " << gcd_other);

    }

}
