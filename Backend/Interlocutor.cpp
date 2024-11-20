#include "Interlocutor.h"

Interlocutor::Interlocutor(KeyPair &key) : keys(key)
{
}

Interlocutor::~Interlocutor()
{
}

std::tuple<long long int, long long int> Interlocutor::getPublicKey()
{
    return std::tuple<long long int, long long int>();
}

std::vector<int> Interlocutor::encrypt(std::string message)
{
    return std::vector<int>();
}

std::string Interlocutor::decrypt(std::vector<int>)
{
    return std::string();
}
