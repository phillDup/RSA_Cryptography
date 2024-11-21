class PrimeGenerator;

#include <tuple>
#include <iostream>

class KeyPair {

    friend class MockKeyPairTester; // Used for private method testing

    private:
        long long int p_prime;
        long long int q_prime;
        long long int e_value;
        long long int d_value;

        int extendedEuclideanAlgorithm(long long int, long long int);

    public:
        KeyPair(PrimeGenerator* primeGenerator);
        KeyPair(const KeyPair& key);
        virtual ~KeyPair();

        std::tuple<long long int, long long int> getPublicKeyRepresentation();
        std::tuple<long long int, long long int> getPrivateKeyRepresentation();

};