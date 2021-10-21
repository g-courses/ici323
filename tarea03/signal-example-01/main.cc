#include <global.hh>

#include <unistd.h> 

void signal_handler( int signal_num ) { 
	static uint32_t trials = 0;
	
	trials++;
	std::cout << "Interrupt signal is (" << signal_num << ").\n"; 
  
	if(trials == 2){
		exit(signal_num);  
	} 
} 

int main(int argc, char* argv[])
{
	int count = 0; 
	
	// register the signals and the signal handler   
	std::signal(SIGTERM, signal_handler);   
	std::signal(SIGINT, signal_handler);  
	   
	  
	while(++count) { 
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Hello ... PID=" << getpid() << std::endl; 
		if( count == 50 ) {
			std::raise(SIGTERM); 
		} 
	}
	
	return EXIT_SUCCESS;
}
