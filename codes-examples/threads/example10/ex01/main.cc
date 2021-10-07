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
	std::vector<std::string> fileLines;
	
	std::string fName;
	
	if(argc != 2){
		std::cerr << "Use: "<< argv[0] << " file1" <<std::endl;
		return EXIT_FAILURE;
	}
	
	fName = argv[1];
	
	if(!getFileContent(fName, fileLines)){
		std::cerr << "Cannot open the File : "<<fName<<std::endl;
		return EXIT_FAILURE;
	}
	
	for(auto& line : fileLines){
		std::cout << "# " << line << std::endl;
	}
	
	return EXIT_SUCCESS;
}
