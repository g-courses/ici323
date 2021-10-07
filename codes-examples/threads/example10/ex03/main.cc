#include <global.hh>

bool getFileContent(std::string fileIn, std::vector<std::string>& out)
{
	std::ifstream inputFileStream;
	inputFileStream.open(fileIn,std::ifstream::in);
	
	if(!inputFileStream){
		return false;
	}
	
	std::string lineIn;
	
	while(std::getline(inputFileStream, lineIn)) {
		out.push_back(lineIn);
	}
	
	inputFileStream.close();
	
	return true;
}


int main(int argc, char* argv[])
{
	std::vector<std::string> fileLines1, fileLines2;
	
	std::string fName1, fName2;
	
	if(argc != 3){
		std::cerr << "Use: "<< argv[0] << " file1 file2" <<std::endl;
		return EXIT_FAILURE;
	}
	
	fName1 = argv[1];
	fName2 = argv[2];
	
	auto start = std::chrono::high_resolution_clock::now();
	fileLines1.clear();
	fileLines2.clear();
	
	if(!getFileContent(fName1, fileLines1)){
		std::cerr << "Cannot open the File : "<<fName1<<std::endl;
		return EXIT_FAILURE;
	}
	
	auto end     = std::chrono::high_resolution_clock::now(); 
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	auto totalTime = elapsed.count();
	
	std::cout << "Time elapsed (1 file): " << 	totalTime << std::endl;
	
		
	start = std::chrono::high_resolution_clock::now();
	fileLines1.clear();
	fileLines2.clear();
	
	if(!getFileContent(fName1, fileLines1)){
		std::cerr << "Cannot open the File : "<<fName1<<std::endl;
		return EXIT_FAILURE;
	}
	
	if(!getFileContent(fName2, fileLines2)){
		std::cerr << "Cannot open the File : "<<fName2<<std::endl;
		return EXIT_FAILURE;
	}
	
	end     = std::chrono::high_resolution_clock::now(); 
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	totalTime = elapsed.count();
	
	std::cout << "Time elapsed (2 files, Secuential case): " << 	totalTime << std::endl;
	
	start = std::chrono::high_resolution_clock::now();
	
	fileLines1.clear();
	fileLines2.clear();
	
	auto task1 = std::async(std::launch::async, getFileContent, fName1, std::ref(fileLines1));
	auto task2 = std::async(std::launch::async, getFileContent, fName2, std::ref(fileLines2));
	
	//std::cerr << "Cargando datos de: "<<fName1<<std::endl;
	//std::cerr << "Cargando datos de: "<<fName2<<std::endl;
	
	bool retTask1 = task1.get();
	bool retTask2 = task2.get();
	if(!retTask1){
		std::cerr << "Cannot open the File : "<<fName1<<std::endl;
		return EXIT_FAILURE;
	}
	if(!retTask2){
		std::cerr << "Cannot open the File : "<<fName2<<std::endl;
		return EXIT_FAILURE;
	}
	
	end     = std::chrono::high_resolution_clock::now(); 
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	totalTime = elapsed.count();
	
	std::cout << "Time elapsed (2 files, Task case): " << 	totalTime << std::endl;
		
	/*
	for(auto& line : fileLines){
		std::cout << "# " << line << std::endl;
	}
	*/
	
	return EXIT_SUCCESS;
}
