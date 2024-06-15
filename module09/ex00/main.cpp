#include "./BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        try
        {
            BitcoinExchange ecc(argv[1]);
            ecc.exchange();
        }
        catch (const std::exception &e)
        {            
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cerr << "ERROR: Wrong number of arguments" << std::endl;
    while(1){}
    return 0;
}