#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename)
{
    this->_file = filename;
}

BitcoinExchange::~BitcoinExchange()
{

}

std::string trim(const std::string& str) {
    std::string result;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isspace(*it)) {
            result += *it;
        }
    }
    return result;
}

std::string* ognich(char ch, std::string line)
{

    std::string *ret = new std::string[2];

    int tex = line.find(ch);
    if (tex <= 0)
        throw std::runtime_error("Wrong format of file");
    ret[0] = line.substr(0, tex);
    ret[1] = line.substr(tex + 1, line.size() - 1);
    if (!ret[1].find(ch))
        throw std::runtime_error("Wrong format of file");
    ret[0] = trim(ret[0]);
    ret[1] = trim(ret[1]);
    return ret;
}

bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

void BitcoinExchange::checkFile()
{
    this->_input.open(this->_file);
    std::string line;

    if (!this->_input.is_open())
        throw std::runtime_error("Could not open file");
    std::getline(this->_input, line);
    int tex = line.find('|');
    if (tex <= 0)
        throw std::runtime_error("Wrong format of file");
    std::string data = line.substr(0, tex);
    std::string value = line.substr(tex + 1, line.size() - 1);
    if (value.find('|') != std::string::npos)
        throw std::runtime_error("Wrong format of file");
    data = trim(data);
    if (data.compare("data"))
        throw std::runtime_error("Wrong format of file");
    value = trim(value);
    if (value.compare("value"))
        throw std::runtime_error("Wrong format of file");
}

void check_date(std::string date)
{
    for (size_t i = 0; i < date.size(); i++)
    {
        if (!isdigit(date[i]) && date[i] != '-')
            throw std::runtime_error("error with dates");
    }
    size_t  tex = date.find('-');
    if (tex <= 0)
        throw std::runtime_error("Wrong format of file");
    std::string year = date.substr(0, tex);
    std::string month = date.substr(tex + 1, date.size() - 1);
    tex = month.find('-');
    if (tex == std::string::npos)
        throw std::runtime_error("Wrong format of file");
    month = month.substr(0, tex);
    std::string day = date.substr(tex  + month.size() + year.size(), date.size() - 1);
    int year_i = std::atoi(year.c_str());
    if (year_i < 2009 || year_i > 2022 )
            throw std::runtime_error("error with dates");
    int month_i = std::atoi(month.c_str());
    if (month_i < 1 || month_i > 12)
        throw std::runtime_error("error with dates");
    int day_i = std::atoi(day.c_str());
    if (month_i == 2 && isLeapYear(year_i) && day_i > 29)
        throw std::runtime_error("error with dates");
    else if (month_i == 2 && !isLeapYear(year_i) && day_i > 28)
        throw std::runtime_error("error with dates");
    if (day_i < 1 || (month_i % 2 == 0 && day_i > 31) || (month_i % 2 && day_i > 30))
        throw std::runtime_error("error with dates");
}

double check_value(std::string value)
{
    long tiv = std::atol(value.c_str());
    if (tiv > 1000)
        throw std::runtime_error("too large a number");
    double ret = std::strtod(value.c_str(), NULL);
    if (ret < 0)
        throw std::runtime_error("negative number");
    return ret;
}

void BitcoinExchange::ready_print()
{

    std::string line;
    std::string *inputik;
    std::map<std::string, std::string>::iterator bound;
    std::getline(this->_input, line);
    if (line.empty())
        throw std::runtime_error("empty file");
    while (!line.empty())
    {
        inputik = ognich('|', line);
        bound = this->_values.lower_bound(inputik[0]);
        check_date(inputik[0]);
        double value = check_value(inputik[1]);
        std::cout << inputik[0] << " => " << inputik[1] << " = " << value * std::strtod(bound->second.c_str(),NULL) << std::endl;
        if (this->_input.eof())
            break ;
        std::getline(this->_input, line);
    }
}

void BitcoinExchange::exchange()
{
    this->checkFile();
    this->get_data();
    this->ready_print();
}

void BitcoinExchange::get_data()
{
    std::ifstream database;
    database.open("data.csv");
    std::string line;

    if (!database.is_open())
        throw std::runtime_error("Could not open file");
    std::getline(database, line);
    int tex = line.find(',');
    if (tex <= 0)
        throw std::runtime_error("Wrong format of file");
    std::string data = line.substr(0, tex);
    std::string value = line.substr(tex + 1, line.size() - 1);
    if (!value.find(','))
        throw std::runtime_error("Wrong format of file");
    data = trim(data);
    if (data.compare("date"))
        throw std::runtime_error("Wrong format of file");
    value = trim(value);
    if (value.compare("exchange_rate"))
        throw std::runtime_error("Wrong format of file");
    std::getline(database, line);
    while (!line.empty())
    {
        std::string *datastik = ognich(',', line);
        this->_values.insert(std::pair<std::string, std::string>(datastik[0], datastik[1]));
        delete[] datastik;
        if (database.eof())
            break ;
        std::getline(database, line);
    }
    database.close();
}