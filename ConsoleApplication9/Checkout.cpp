#include "pch.h"
#include <algorithm>
#include "Checkout.h"


Checkout::~Checkout()
{
}

size_t Checkout::Scan(std::string sku)
{
	auto pr = _pricingRules.getProducts();

	//if pricingRules doesn't contain item throws exception
	auto contains = pr.count(sku);
	if (contains == 0)
		throw std::exception(("invalid item " + sku).c_str());

	//If list doesn't contains item yet add it
	if (_items.find(sku) == _items.end())
		_items[sku] = 0;
	return _items[sku] += 1;
}

size_t Checkout::Void(std::string sku)
{

	auto count = _items[sku];
	//remove item from list, if list doesn't contain item throws exception
	if (count > 0)
		return _items[sku] -= 1;
	else
		throw std::exception((std::string("no item " + sku) + std::string(" in list")).c_str());
	return count;
}

double Checkout::getTotal()
{
	double total = 0;
	auto pr = _pricingRules.getProducts();
	auto cp = _pricingRules.getCustomPricings();

	for (auto item : _items)
	{
		//get custom pricing for item
		auto cpIt = cp.find(item.first);

		//get normal price for item
		auto prIt = pr.find(item.first);

		if (cpIt != cp.end())
		{
			//if item has custom pricing sums whole packs and add rest for normal price
			total += (item.second / cpIt->second.getReqCount()) * cpIt->second.getPackPrice();
			total += (item.second % cpIt->second.getReqCount()) * prIt->second.getPrice();
		}
		else
		{
			total += prIt->second.getPrice() * item.second;
		}
	}
	return total;
}

void Checkout::printAllItems(FILE * f)
{
	for (auto i : _items)
	{
		fprintf(f, "%i x %s\n", i.second, i.first.c_str());
	}
}
