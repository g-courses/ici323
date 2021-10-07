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
	std::vector<std::string> fileLines1;
	
	std::string fName1;
	
	if(argc != 2){
		std::cerr << "Use: "<< argv[0] << " file1" <<std::endl;
		return EXIT_FAILURE;
	}
	
	fName1 = argv[1];
	
	
	fileLines1.clear();
	
	auto task1 = std::async(std::launch::async, getFileContent, fName1, std::ref(fileLines1));
	
	std::cerr << "Cargando datos de: "<<fName1<<std::endl;
	
	bool retTask1 = task1.get();
	if(!retTask1){
		std::cerr << "Cannot open the File : "<<fName1<<std::endl;
		return EXIT_FAILURE;
	}
	
	
	for(auto& line : fileLines1){
		std::cout << "# " << line << std::endl;
	}
	
	return EXIT_SUCCESS;
}
