#include <iostream>
#include <thread>
#include <vector>


int turn;


const int AMOUNT = 5;

int in[AMOUNT];
int last[AMOUNT];

bool flag[4];

std::vector<std::thread> m_threads;

/// <summary>
/// function to thread n processes 
/// </summary>
/// <param name="s">the current number</param>
void CS(void * s)
{
	//casts s(current number) to an interger 
	int n = (int)s;

	while (true)
	{
		for (int j = 0; j < AMOUNT; j++)
		{

			in[n] = j;//sets the current
			last[j] = n;//sets the last 

			for (int k = 0; k < AMOUNT; k++)
			{
				if (k != n)
				{
					//wait if process k is in a higher stage and i was last to enter stage j
					while (in[k] >= in[n] && last[j] == n);
				}
			}
		}
		//critical section
		std::cout << "PROCESS: " << n << std::endl;
		in[n] = -1;
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
	
	for (int i = 0; i < AMOUNT; ++i)
	{
		m_threads[i].join();
	}

	//system("PAUSE");
	return 0;
}