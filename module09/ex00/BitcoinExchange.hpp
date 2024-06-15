#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstring>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();
        void get_data();
        void exchange();
        void checkFile();
        void ready_print();
    private:
        std::map<std::string, std::string> _values;
        std::string _file;
        std::ifstream _input;
};