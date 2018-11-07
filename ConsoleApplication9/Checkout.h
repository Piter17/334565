#pragma once
#include "pch.h"
#include <map>
#include "Product.h"
#include "CustomPricing.h"
#include "DataSource.h"

class Checkout
{
public:
	Checkout(DataSource pricingRules) { _pricingRules = pricingRules; };
	~Checkout();

	const std::map<std::string, size_t> getItems() { return _items; }
	size_t Scan(std::string product);
	size_t Void(std::string product);

	double getTotal();
	void printAllItems(FILE* f = stdout);

private:
	std::map<std::string, size_t> _items;
	DataSource _pricingRules;
};

