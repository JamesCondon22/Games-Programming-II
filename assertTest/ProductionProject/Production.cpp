#include "Production.h"

int Production::someMethod(int a)
{
	return a - a;
}

int Production::testSize(std::vector<int> v)
{
	return v.size();
}

bool Production::checkRecurring(std::vector<int> v) {

	std::sort(v.begin(), v.end());
	auto it = std::unique(v.begin(), v.end());

	bool unique = (it == v.end());
	return unique;
	
}

bool Production::checkRange(std::vector<int> v) 
{

	for (auto it = v.begin(); it != v.end(); ++it)
	{
		if ((*it) < 1 && (*it) > 46)
		{
			return 0;
		}
	}

	return 1;
}