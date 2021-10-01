#include <global.h>


void sumaParcial(const std::vector<uint32_t> &v, 
                 uint32_t &suma, 
                 size_t beginIndex, 
				 size_t endIndex) {
    suma = 0;
    for (size_t i = beginIndex; i < endIndex; ++i){
        suma += v[i];
    }
}

int main(int argc, char** argv){
	
	uint32_t totalElementos = 100000000;
	
    uint32_t sumaSerial = 0;
	uint32_t suma1 = 0;
	uint32_t suma2 = 0;
	uint32_t sumaThreads = 0;
	
	std::vector<uint32_t> v;
	
	for(size_t i=0; i < totalElementos; i++){
		v.push_back(i);
	}
	
	//======SERIAL======
	sumaParcial( std::ref(v), std::ref(sumaSerial), 0, v.size() );
	
	//======THREADS======
	//(1) Separación del trabajo
	std::thread t1(sumaParcial, std::ref(v), std::ref(suma1), 0, v.size() / 2);
	std::thread t2(sumaParcial, std::ref(v), std::ref(suma2), v.size() / 2, v.size());
	
	t1.join();
	t2.join();
	
	//(2) Reducción (Consolidación de resultados parciales)
	sumaThreads = suma1 + suma2;

	std::cout << "====Serial====" << std::endl;
	std::cout << "sumaSerial: " << sumaSerial << std::endl;

	std::cout << "====Threads====" << std::endl;
	std::cout << "suma1: " << suma1 << std::endl;
	std::cout << "suma2: " << suma2 << std::endl;
	std::cout << "suma1 + suma2: " << sumaThreads << std::endl;

	return(EXIT_SUCCESS);
}

