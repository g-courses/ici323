#include <global.h>

std::mutex g_mux;

void threadMain(const uint32_t threadID){
	
	size_t i;

	i = 666;
	
	g_mux.lock();
	std::cout << "threadID:"<< threadID << " ==> &i:"<< &i << std::endl;
	std::cout << "threadID:"<< threadID << " ==> &g_mux:"<< &g_mux << std::endl;
	g_mux.unlock();

}




int main(int argc, char** argv){
	std::cout << "PID        :"<< getpid()<< std::endl;
	
	std::thread t01(threadMain, 1);
	std::thread t02(threadMain, 2);

	t01.join();
	t02.join();
	
	std::cout << std::endl;

	std::cout << "&t01       :"<< &t01 << std::endl;
	std::cout << "&threadMain:"<< (void*)&threadMain << std::endl;
	std::cout << "&g_mux     :"<< &g_mux << std::endl;
	
	return(EXIT_SUCCESS);
}

