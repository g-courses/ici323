#include <global.h>

int main(int argc, char** argv){
	
	uint32_t totalElementos = 1000000;
	
    uint32_t sumaSerial = 0;
	uint32_t sumaParcial1 = 0;
	uint32_t sumaParcial2 = 0;
	uint32_t sumaThreads = 0;
	
	std::vector<uint32_t> v;

	for(size_t i=0; i < totalElementos; i++){
		v.push_back(i);
	}
	
	//======SERIAL======
	for(auto& num : v){
		sumaSerial += num;
	}
	
	//======THREADS======
	//(1) Separación del trabajo
	auto sumaThread =[](std::vector<uint32_t> &vIn, uint32_t& suma , size_t left, size_t right) {
		suma = 0;
        for (size_t i = left; i < right; ++i){
            suma += vIn[i];
        }
    };
	
	std::thread t1( sumaThread, std::ref(v), std::ref(sumaParcial1), 0, v.size()/2 );
	std::thread t2( sumaThread, std::ref(v), std::ref(sumaParcial2), v.size()/2, v.size() );
	        
	t1.join();
    t2.join();
	
	//(2) Reducción (Consolidación de resultados parciales)
	sumaThreads = sumaParcial1 + sumaParcial2;

	std::cout << "====Serial====" << std::endl;
	std::cout << "sumaSerial: " << sumaSerial << std::endl;

	std::cout << "====Threads====" << std::endl;
	std::cout << "suma1: " << sumaParcial1 << std::endl;
	std::cout << "suma2: " << sumaParcial2 << std::endl;
	std::cout << "suma1 + suma2: " << sumaThreads << std::endl;

	return(EXIT_SUCCESS);
}

