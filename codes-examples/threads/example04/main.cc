#include <global.h>

std::mutex g_mux;

void threadMain(std::string sym, const uint32_t cMax){
	
	g_mux.lock();
	for(size_t i = 0; i < cMax; ++i) {
		//g_mux.lock();
		std::cout << sym << std::endl;
		//g_mux.unlock();
	}
	//g_mux.unlock();
	
}


int main(int argc, char** argv){
	
	std::thread t01(threadMain, "." , 600);
	std::thread t02(threadMain, "*", 600);

	t01.join();
	t02.join();
	
	std::cout << std::endl;
	
	return(EXIT_SUCCESS);
}

