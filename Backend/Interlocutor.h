#include "KeyPair.h"

#include <vector>
#include <string> 

class Interlocutor
{

    private:
        KeyPair& keys;

    public:
        Interlocutor(KeyPair& key);
        ~Interlocutor();
        std::tuple<long long int, long long int> getPublicKey();
        std::vector<int> encrypt(std::string message);
        std::string decrypt(std::vector<int>);

};