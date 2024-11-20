#include "KeyPair.h"

KeyPair::KeyPair(PrimeGenerator *primeGenerator)
{
}

KeyPair::KeyPair(const KeyPair & key)
{
}

KeyPair::~KeyPair()
{
}

std::tuple<long long int, long long int> KeyPair::getPublicKeyRepresentation()
{
    return std::tuple<long long int, long long int>();
}

std::tuple<long long int, long long int> KeyPair::getPrivateKeyRepresentation()
{
    return std::tuple<long long int, long long int>();
}
