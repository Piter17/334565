#pragma once

#include "pch.h"
#include "Product.h"
#include "CustomPricing.h"


class DataSource
{
public:
	DataSource();
	~DataSource();

	void LoadData();
	void LoadTestData();

	//wanted to use SQL on the beginning but in I think it would consume too much time
	//all SQL queries were planned to be added as stored procedures

	//not implemented methods which I wanted to use to manage data
	//void SaveData();

	//void AddProduct(Product& product);
	//void AddCustomPricing(CustomPricing& pricing);

	//void RemoveProduct(std::string sku);
	//void RemoveCustomPricing(CustomPricing& pricing);

	//This should be maps instead of vector, would make code easier and shorter
	const std::map< std::string, Product >& getProducts() { return _products; }
	const std::map<std::string, CustomPricing>& getCustomPricings() { return _customPricings; }

private:
	std::map<std::string, Product> _products;
	std::map<std::string, CustomPricing> _customPricings;
};

