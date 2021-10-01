#include <global.h>

#include <future>

int main(int argc, char** argv){
	
	uint32_t totalElementos = 100000000;
	
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
	
	auto sumaParcial = [](std::vector<uint32_t> &v, size_t left, size_t right) {
        uint32_t suma = 0;
        for (size_t i = left; i < right; ++i){
            suma += v[i];
        }

        return suma;
    };

	
	//======THREADS======
	//(1) Separación del trabajo
	auto t1 = std::async(std::launch::async, sumaParcial, std::ref(v), 0, v.size() / 2);				
    auto t2 = std::async(std::launch::async, sumaParcial, std::ref(v), v.size() / 2, v.size());
	        
	sumaParcial1 = t1.get();
	sumaParcial2 = t2.get();
	
	//(2) Reducción (Consolidación de resultados parciales)
	//sumaThreads = suma1.suma() + suma2.suma();
	sumaThreads = sumaParcial1 + sumaParcial2;

	std::cout << "====Serial====" << std::endl;
	std::cout << "sumaSerial: " << sumaSerial << std::endl;

	std::cout << "====Threads====" << std::endl;
	std::cout << "suma1: " << sumaParcial1 << std::endl;
	std::cout << "suma2: " << sumaParcial2 << std::endl;
	std::cout << "suma1 + suma2: " << sumaThreads << std::endl;

	return(EXIT_SUCCESS);
}

