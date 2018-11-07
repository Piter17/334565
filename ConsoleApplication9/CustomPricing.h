#pragma once
#include "pch.h"
class CustomPricing
{
public:
	CustomPricing();
	CustomPricing(int reqCount, double packPrice) { _reqCount = reqCount; _packPrice = packPrice; }
	~CustomPricing();

	int getReqCount() { return _reqCount; }
	void setReqCount(int value) { _reqCount = value; }

	double getPackPrice() { return _packPrice; }
	void setPackPrice(double value) { _packPrice = value; }

private:
	int _reqCount;
	double _packPrice;
};

