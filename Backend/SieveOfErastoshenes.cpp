#include "SieveOfErastoshenes.h"
#include <random>

// Initialize number list of size to false
// Note: The first element in the vector represents 2 thus to calculate primes up to value n you need only n-1 array elements
SieveOfErastoshenes::SieveOfErastoshenes(int size)
{   
    // Initialize array to false
    for(int i=0; i<size - 1; i++)
    {
        this->numberList.push_back(false);
    }

    // Apply sieve algorithm
    // Loop through entire list
    int currentNumber; // Initialize current number (The number which multiples will be marked)
    for(u_int i=0; i < numberList.size(); i++)
    {   
        currentNumber = (i + 2); 

        if(numberList.at(i) == false)
        {
            // Mark all multiples of current number
            int nrElementsMarked = 0;
            for(u_int j = currentNumber * 2; j < numberList.size() + 2; j += currentNumber)
            {   
                if(numberList.at(j - 2) != true)
                {
                    numberList.at(j - 2) = true;       
                    nrElementsMarked++;         
                }
            }

            // Check if no elements were marked ==> algorithm is complete
            if(nrElementsMarked == 0) {return;}            
        }


    }


}

SieveOfErastoshenes::~SieveOfErastoshenes()
{
}

// Returns random prime greater than parameter
long long int SieveOfErastoshenes::getPrimeGreaterThan(int lowerBound)
{
    // Get a vector of all primes
    std::vector<long long int> generatedPrimes = this->getPrimes();

    // Ensure the vector is not empty
    if (generatedPrimes.empty()) {
        return -1; // No primes generated
    }

    // Iterate to the point where a prime is larger than the lower bound
    for (u_int i = 0; i < generatedPrimes.size(); i++) {
        if (generatedPrimes.at(i) > lowerBound) {
            // Calculate remaining valid range
            size_t remainingPrimes = generatedPrimes.size() - i;

            // If there are no additional primes, return the current one
            if (remainingPrimes <= 1) {
                return generatedPrimes.at(i);
            }

            // Generate random offset in [1, remainingPrimes - 1]
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(1, remainingPrimes - 1);

            size_t randomOffset = distrib(gen);
            return generatedPrimes.at(i + randomOffset);
        }
    }

    return -1; // No prime found greater than lowerBound
}



// Return all non marked numbers in the numberlist
std::vector<long long int> SieveOfErastoshenes::getPrimes()
{
    std::vector<long long int> vectorOfPrimes;
    for(u_int i=0; i<numberList.size(); i++)
    {
        if(numberList.at(i) == false)
        {
            vectorOfPrimes.push_back(i + 2);
        }
    }

    return vectorOfPrimes;
}

void SieveOfErastoshenes::printSieve()
{       
    std::string output = "[ ";
    for(u_int i=0; i<numberList.size(); i++)
    {
        if(numberList.at(i) == false)
        {
            output += (std::to_string(i + 2) + ", ");
        }
    }
    output = output.substr(0, output.length() - 2);
    output += " ]\n";

    std::cout << output;
}
