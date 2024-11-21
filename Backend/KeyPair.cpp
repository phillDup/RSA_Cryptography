#include "KeyPair.h"

// Extended Euclidean algorithm function
// Writes some number as quotient remainder theorem: p = (q)n + r with 0 <= r <= n-1
// Repeat for gcd(n,r) 
int KeyPair::extendedEuclideanAlgorithm(long long int num1, long long int num2)
{   
    // gcd(0,0) defined as 0 for use-case
    if(num1 == 0 && num2 == 0)
    {
        return 0;
    }

    // gcd(a, a) = a
    if(num1 == num2)
    {
        return num1;
    }

    // Ensure num1 > num2
    if(num1 < num2)
    {
        return extendedEuclideanAlgorithm(num2, num1);
    }


    // Create tuple <q, n, r> where q = num1 / num2 | n = num2 | r = p - (n * q)
    int quotient = num1 / num2;
    std::tuple<int, int, int> quotient_remainder = std::make_tuple(quotient, num2, (num1 - (num2 * quotient)));

    // std::cout << "p = qn + r | " << num1 << " = " << "(" << std::get<0>(quotient_remainder) << ")" << num2 << " + " << std::get<2>(quotient_remainder) << "\n"; 

    // Recursive case: Check if remainder is 0 ==> gcd(n, 0) == n otherwise call recurisvely
    if(std::get<2>(quotient_remainder) != 0 )
    {
        return extendedEuclideanAlgorithm(std::get<1>(quotient_remainder), std::get<2>(quotient_remainder));
    } 
    else
    {
        return std::get<1>(quotient_remainder);        
    }

}


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
