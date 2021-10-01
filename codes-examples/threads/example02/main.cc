#include <global.h>


std::mutex g_DMutex;

void threadMain(const std::string& msg){
	
	g_DMutex.lock();
	std::cout << "thread child: start" << 
		std::endl;
	g_DMutex.unlock();
	
	g_DMutex.lock();
	std::cout << "thread child: id = " << 
		std::this_thread::get_id() << 
		std::endl;
	g_DMutex.unlock();
	
	g_DMutex.lock();
	std::cout << "thread child: msg=" << 
		msg <<
		std::endl;
	g_DMutex.unlock();
}


int main(int argc, char** argv){
	
	g_DMutex.lock();
	std::cout << "Total threads = " <<
		std::thread::hardware_concurrency() << 
		std::endl;
	g_DMutex.unlock();
	
	std::string msg = "hello!!";
	std::thread t01(threadMain, msg);
	
	g_DMutex.lock();
	std::cout << "main thread" <<
		std::endl;
	g_DMutex.unlock();
	
	g_DMutex.lock();
	std::cout << "main thread: id = " << 
		std::this_thread::get_id() <<
		std::endl;
	g_DMutex.unlock();
	
	g_DMutex.lock();
	std::cout << "main thread: child id = " << 
		t01.get_id() <<
		std::endl;
	g_DMutex.unlock();
	
	t01.join();

	return(EXIT_SUCCESS);
}

