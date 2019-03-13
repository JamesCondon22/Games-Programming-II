#include <iostream>
#include <assert.h>
#include <vector>

#include "../ProductionProject/Production.h"

using namespace std;


int main()
{
	Production p;
	std::vector<int> v;
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 46;

	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	v.push_back(f);

	cout << p.someMethod(a) << endl;
	cout << p.testSize(v) << endl;
	cout << p.checkRecurring(v) << endl;
	cout << p.checkRange(v) << endl;
	assert(p.someMethod(a) == 0);
	assert(p.testSize(v) == 6);
	assert(p.checkRecurring(v) == true);
	assert(p.checkRange(v) == true);
	
	
	cin.get();
}