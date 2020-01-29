// a_star.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <json/json.h>
#include <iostream>
#include <fstream>

int main()
{
	std::string fileName = "..\\data\\problem1.json";
	std::ifstream infile(fileName);

	if (infile.good() == false) 
	{
		std::cout << "File \"" << fileName << "\" cannot be found." << std::endl;
		return EXIT_FAILURE;
	}
	
	std::cout << "Parsing \"" << fileName << "\"" << std::endl;
	infile.open(fileName);

	Json::CharReaderBuilder builder;
	JSONCPP_STRING errors;
	Json::Value root;

	if (!Json::parseFromStream(builder, infile, &root, &errors))
	{
		std::cout << "Unable to parse file." << std::endl;
		std::cout << errors << std::endl;
		infile.close();
		return EXIT_FAILURE;
	}

	infile.close();



	//Json::Value root;
	//std::ifstream ifs;
	//ifs.open(fileName);

	//Json::CharReaderBuilder builder;
	//builder["collectComments"] = true;
	//JSONCPP_STRING errs;
	//
	//
	//if (!parseFromStream(builder, ifs, &root, &errs)) 
	//{
	//	std::cout << errs << std::endl;
	//	return EXIT_FAILURE;
	//}

	std::cout << "Process completed." << std::endl;
	return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
