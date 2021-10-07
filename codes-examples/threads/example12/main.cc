#include <global.hh>


std::mutex g_sync;

std::vector<std::string> g_textoConsolidado; 

void fooOperation(std::string pathFile)
{	
	std::random_device device;
	std::uniform_int_distribution<> unif(0, 100);
	
	
	std::ifstream inputFile(pathFile);
	
	if(inputFile.fail()) {
		std::string msgError;
		msgError = "Open error in file "+ pathFile; 
		perror(msgError.c_str());
		exit(EXIT_FAILURE);
	}
	
	//g_sync.lock();
	for(std::string line; std::getline(inputFile, line); ){
		//std::this_thread::sleep_for(std::chrono::milliseconds( unif(device) ));
	
		//g_sync.lock();
		g_textoConsolidado.push_back(pathFile + ": " + line);
		//g_sync.unlock();
	}
	//g_sync.unlock();
	
	
	inputFile.close();
	
}

int main(int argc, char* argv[])
{
	std::string pathFile01, pathFile02;
	
	if(argc != 3){
		std::cerr << "Uso: " << argv[0] << " file1 file2 \n";
		exit(EXIT_FAILURE);
	}
	
	pathFile01 = argv[1];
	pathFile02 = argv[2];

	
	std::thread helper1(fooOperation, pathFile01);
	std::thread helper2(fooOperation, pathFile02);
	helper1.join();
	helper2.join();
	
	for(auto& l : g_textoConsolidado){
		std::cout << l << std::endl;
	}


	exit(EXIT_SUCCESS);
}