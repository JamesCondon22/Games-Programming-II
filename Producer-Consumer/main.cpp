#include <thread>
#include <iostream>
#include <queue>
#include <mutex>

//used to protect shared data from multi threads
std::mutex mx;
//used to block a thread at the same time 
std::condition_variable cv;
//queue of integers
std::queue<int> q;

bool finished = false;

/// <summary>
/// passes in number of items to produce 
/// </summary>
/// <param name="n"></param>
void producer(int n) {
	for (int i = 0; i<n; ++i)
	{
		{
			//uses lock to access mutex
			std::unique_lock<std::mutex> lk(mx);
			std::cout << "pushing " << i << std::endl;
			q.push(i);
			
		}
		//unblocks all threads waiting for this condition 
		cv.notify_all();
	}
	
	{
		//used to access mutex
		std::lock_guard<std::mutex> lk(mx);
		finished = true;
	}
	cv.notify_all();
}

void consumer() {
	while (true) {
		//used to access mutex
		std::unique_lock<std::mutex> lk(mx);
		//thread waits while its not empty
		cv.wait(lk, [] { return finished || !q.empty(); });
		while (!q.empty()) {
			std::cout << "consuming " << q.front() << std::endl;
			q.pop();//pop off the queue	
		}
		if (finished) break;
	}
}

int main() {
	//thread for producer 10000 integers
	std::thread t1(producer, 10000);
	//thread for consumer 
	std::thread t2(consumer);
	//blocks current thread
	t1.join();
	//blocks current thread 
	t2.join();
	std::cout << "finished!" << std::endl;
	
	system("PAUSE");
}