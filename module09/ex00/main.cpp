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
        catch(const std::exception& e)
        {
            std::cerr << "ERROR: " << e.what() << '\n';
        }
    }
    else
        std::cerr << "ERROR: Wrong number of arguments" << std::endl;
    return 0;
}