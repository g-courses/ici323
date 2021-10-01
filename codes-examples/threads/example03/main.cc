#include <global.h>

std::mutex g_incMutex;

int32_t g_index;

void threadMain(){
	
	//std::lock_guard<std::mutex> lock(g_incMutex);
	
	g_incMutex.lock();
	++g_index;
	
	std::cout << std::this_thread::get_id() << 
		": " << g_index << std::endl;
	
	g_incMutex.unlock();
}


int main(int argc, char** argv){
	
	uint32_t maxThreads = 10;
	
	std::vector<std::thread*> threads;
	
	for(size_t i = 0; i < maxThreads; ++i){
		threads.push_back( new std::thread(threadMain) );
	}
	
	//std::thread t01(threadMain);
	//std::thread t02(threadMain);

	
	for(auto& th : threads){
		th->join();
	}
	
	//t01.join();
	//t02.join();
	
	std::cout << "main thread: " << g_index << 
		std::endl;

	return(EXIT_SUCCESS);
}

