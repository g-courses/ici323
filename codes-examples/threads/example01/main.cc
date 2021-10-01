#include <global.h>




void threadMain(const std::string& msg){
	
	std::cout << "thread child: start" << 
		std::endl;
	
	std::cout << "thread child: id = " << 
		std::this_thread::get_id() << 
		std::endl;
	
	std::cout << "thread child: msg=" << 
		msg <<
		std::endl;
}


int main(int argc, char** argv){
	
	std::cout << "Total threads = " <<
		std::thread::hardware_concurrency() << 
		std::endl;
	
	std::string msg = "hello!!";
	std::thread t01(threadMain, msg);
	
	std::cout << "main thread" <<
		std::endl;
	std::cout << "main thread: id = " << 
		std::this_thread::get_id() <<
		std::endl;
	std::cout << "main thread: child id = " << 
		t01.get_id() <<
		std::endl;
	
	t01.join();

	return(EXIT_SUCCESS);
}

