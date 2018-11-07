#pragma once
#include "pch.h"

class Product
{
public:
	Product();
	Product(double price) { _price = price; }
	~Product();

	const double getPrice() { return _price; }
	void setPrice(double value) { _price = value; }

private:
	double _price;
};

