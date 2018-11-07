#include "pch.h"
#include "DataSource.h"
#include <fstream>
#include <cstdlib>


DataSource::DataSource()
{
}


DataSource::~DataSource()
{
}



void DataSource::LoadData()
{
	try
	{
		//opens file, throws exception if fails
		printf("Loading products.csv\n");
		auto inputFile = std::fstream("products.csv", std::fstream::in);
		if (!inputFile)
			throw std::exception("File not found.");

		std::string line;
		for (;;)
		{
			//reads one line
			getline(inputFile, line);
			if (inputFile.fail())
				break;

			//deserialize one line
			auto delim = line.find(";");
			auto sku = std::string(line.begin(), line.begin() + delim);
			auto price = std::string(line.begin() + delim + 1, line.end());
			_products[sku] = Product(atof(price.c_str()));
		}
	}
	catch (const std::exception& e)
	{
		fprintf(stderr, "%s\n", e.what());
	}

	try
	{
		printf("Loading custom.csv\n");
		auto inputFile = std::fstream("custom.csv", std::fstream::in);
		if (!inputFile)
			throw std::exception("File not found.");

		std::string line;
		for (;;)
		{
			getline(inputFile, line);
			if (inputFile.fail())
				break;

			auto delim = line.find(";");
			auto sku = std::string(line.begin(), line.begin() + delim);
			line = std::string(line.begin() + delim + 1, line.end());
			delim = line.find(";");
			auto rqCount = std::string(line.begin(), line.begin() + delim);
			auto packPrice = std::string(line.begin() + delim + 1, line.end());
			_customPricings[sku] = CustomPricing(atoi(rqCount.c_str()), atof(packPrice.c_str()));
		}
	}
	catch (const std::exception& e)
	{
		fprintf(stderr, "%s\n", e.what());
	}
}

void DataSource::LoadTestData()
{
	//Load test data
	try
	{
		_products["A1"] = Product(1.99);
		_products["A2"] = Product(2.99);
		_products["A3"] = Product(3.99);
		_products["A4"] = Product(4.99);
		_products["A5"] = Product(5.99);

		_customPricings["A3"] = CustomPricing(2, 5.99);
		_customPricings["A4"] = CustomPricing(3, 7.99);
	}

	catch (const std::exception& e)
	{
		fprintf(stderr, "%s\n", e.what());
	}
}
