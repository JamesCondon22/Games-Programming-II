#include <iostream>
#include <thread>
#include <vector>


int turn;


int AMOUNT = 4;

bool flag[4];

std::vector<std::thread> m_threads;

void CS(void * s)
{

	int n = (int)s;

	while (true)
	{
		
	}

}

void * funcOne()
{
	while (true)
	{
		flag[0] = true;
		turn = 1;

		while (flag[1] == true && turn == 1)
		{
			break;
		}

		std::cout << "0" << std::endl;

		flag[0] = false;
	}
}


void * functwo()
{
	while (true)
	{
		flag[1] = true;
		turn = 0;

		while (flag[0] == true && turn == 0)
		{
			break;
		}
		std::cout << "1" << std::endl;

		flag[1] = false;
	}
}


int main()
{

	for (int i = 0; i < AMOUNT; i++)
	{
		m_threads.push_back(std::thread(CS, (void*)i));
	}
	
	for (int i = 0; i < AMOUNT; i++)
	{
		m_threads[i].join();
	}

	system("PAUSE");
	return 0;
}