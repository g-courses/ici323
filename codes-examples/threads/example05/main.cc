#include <global.h>

static volatile int balance = 0;

void depositar(const uint32_t thID, const uint32_t totalDinero){
	
	for(size_t i = 0; i < totalDinero; i++) {
		balance = balance + 1;
	}
	
	std::cout << "Thread:" << thID << " FIN." << std::endl;
}

std::mutex mux;

void depositar_safe(const uint32_t thID, const uint32_t totalDinero){
	
	for(size_t i = 0; i < totalDinero; i++) {
		mux.lock();
		balance = balance + 1;
		mux.unlock();
	}
	
	std::cout << "Thread:" << thID << " FIN." << std::endl;
}


int main(int argc, char** argv){
	
	std::cout << "MAIN: balance=" << balance << std::endl;
	
	std::thread t00(depositar, 0, 1000000);
	std::thread t01(depositar, 1, 1000000);

	t00.join();
	t01.join();
	
	std::cout << "MAIN: balance=" << balance << std::endl;
	
	return(EXIT_SUCCESS);
}

