#include "PrimeGenerator.h"

#include <tuple>

class KeyPair {

    private:
        long long int p_prime;
        long long int q_prime;
        long long int e_value;
        long long int d_value;

    public:
        KeyPair(PrimeGenerator* primeGenerator);
        KeyPair(const KeyPair& key);
        ~KeyPair();

        std::tuple<long long int, long long int> getPublicKeyRepresentation();
        std::tuple<long long int, long long int> getPrivateKeyRepresentation();

};