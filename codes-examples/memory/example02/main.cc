#include <global.h>


uint32_t fibonacci(uint32_t a)
{
	
	
	if((a <= 2)) {
		return 1;
	} else {
		return(fibonacci(a-1)+fibonacci(a-2));
	}
}



int main(int argc, char** argv)
{

	if(argc != 2) {
		std::cerr << "Use: "<< argv[0] << " num" <<std::endl;
		return EXIT_FAILURE;
	}

	uint32_t fib = std::atoi(argv[1]);

	std::cout << "Fibonacci("<< fib <<") = ";
	
	uint32_t res = fibonacci(fib);
	
	std::cout << res <<"\n";
	
	return(EXIT_SUCCESS);
}

