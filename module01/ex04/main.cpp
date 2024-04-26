#include <iostream>
#include <fstream>

void manip(std::string &all_file, std::string s1, std::string s2)
{
	std::string::size_type pos = all_file.find(s1);
	while (pos != std::string::npos)
	{
		all_file.erase(pos, s1.length());
		all_file.insert(pos, s2);
		pos = all_file.find(s1);
	}
}

int main(int argc, char *argv[])
{
	std::ifstream inputFile;
	std::string line;
	std::string all_file;
	std::ofstream outputFile;
	if (argc == 4)
	{
		inputFile.open(argv[1]);
		if (!inputFile.is_open())
        	std::cerr << "Error: Unable to open file " << argv[1] << "\n";
		std::string rep =  ".replace";
		outputFile.open(argv[1] + rep);
		if (!outputFile.is_open())
		{
        	std::cerr << "Error: Unable to open file.\n";
        	return 1;
   		}
		while (std::getline(inputFile, line))
			all_file += (line + '\n');
		manip(all_file, argv[2], argv[3]);
		outputFile << all_file;
		inputFile.close();
		outputFile.close();
	}
	else if (argc < 4)
		std::cout << "I think you miss something\n";
	else
		std::cout << "I think you give more arguments\n";
	return 0;
}