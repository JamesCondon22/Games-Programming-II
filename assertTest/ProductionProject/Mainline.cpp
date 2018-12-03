#include "Production.h"
#include <time.h>
#include <iostream>
#include <string>
#include <array>

void enterNumbers(std::vector<int> & v) {
	int a, b, c, d, e, f;
	v.clear();

	std::cin >> a;
	v.push_back(a);
	std::cin >> b;
	v.push_back(b);
	std::cin >> c;
	v.push_back(c);
	std::cin >> d;
	v.push_back(d);
	std::cin >> e;
	v.push_back(e);
	std::cin >> f;
	v.push_back(f);
	
	std::cout << std::endl;
}

void intro()
{
	std::cout << "Enter 6 numbers between 1 and 46." << std::endl;
	std::cout << "These number must be 6 different numbers." << std::endl;
	std::cout << "You cannot repeat the same number." << std::endl;
}

void lineBreak()
{
	std::cout << std::endl;
}

int main()
{
	Production p;
	int size = 6;
	int randomNumbers[6];
	std::vector<int> lotto;
	srand(time(NULL));
	std::vector<int> v;
	
	for (int i = 0; i < size; i++)
	{
		randomNumbers[i] = rand() % 46 + 1;
		lotto.push_back(randomNumbers[i]);

		while (p.checkRecurring(lotto) == 0 && !lotto.empty())
		{
			lotto.pop_back();
			randomNumbers[i] = rand() % 46 + 1;
			lotto.push_back(randomNumbers[i]);
		}	
	}

	intro();
	enterNumbers(v);	
	
	p.testSize(v);
	p.checkRecurring(v);
	p.checkRange(v);

	while(p.checkRecurring(v) == 0)
	{
		std::cout << "There are numbers recurring! You cannot have recurring numbers!" << std::endl;
		intro();
		lineBreak();
		enterNumbers(v);
	}
	
	while (p.checkRange(v) == 0)
	{
		std::cout << "Numbers must be between 1 and 46!" << std::endl;
		intro();
		lineBreak();
		enterNumbers(v);
	}
	
	std::cout << "The winning lottery numbers are" << std::endl;

	for (int i = 0; i < 6; i++)
	{
		std::cout << std::to_string(randomNumbers[i]) << " ";
	}

	lineBreak();

	for (int i = 0; i < size; i++)
	{
		p.checkForNumbers(v, randomNumbers[i]);
	}

	lineBreak();

	system("pause");
}
