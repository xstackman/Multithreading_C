#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>

using namespace std::literals;
std::binary_semaphore sender(0), receiver(0);


void threadproc(){
	sender.acquire();
	std::cout << "[proc] Signal received" << std::endl;
	std::this_thread::sleep_for(3s);
	std::cout << "[proc] Signal sent" << std::endl;
	receiver.release();

}

int main(){

	std::thread mainWorker(threadproc);
	std::cout << "[main] Send signal" << std::endl;
	sender.release();
	receiver.acquire();
	std::cout << "[main] Receive te signal" << std::endl;
	mainWorker.join();

	return 0;
}
