#include <global.hh>
#include <json.hpp> 
using json = nlohmann::json;

#include <restclient-cpp/restclient.h>
#include <restclient-cpp/connection.h>
enum CURLerrorCode {COULDNT_CONNECT = 7};

#include <Timer.hpp>

/////////////////////////////////////////////////////////////////////////////////
//   Usage:
//           ./program_name  .......
//
//   Description:
//                ...................
//
/////////////////////////////////////////////////////////////////////////////////

/*
void uso(std::string pname)
{
	std::cerr << "Uso: " << pname << " ..... " << std::endl;
	exit(EXIT_FAILURE);
}
*/

int main(int argc, char** argv)
{
	Timer<std::chrono::milliseconds> timer;
	double networkTime, processTime;
	std::string hostURL, resourcePath; 
	RestClient::Response r;
	json response;

	hostURL = "https://imdb-api.com";
	//queryURL = "/es/API/SearchMovie/k_tj65h75n/freddy";
	resourcePath = "/en/API/Top250Movies/k_tj65h75n";
	
	timer.start();
	RestClient::Connection* conn = new RestClient::Connection(hostURL);
	r = conn->get(resourcePath);
	switch(r.code){
		case COULDNT_CONNECT:{
			std::cerr << "Could not connect to REST server." << std::endl;
			exit(EXIT_FAILURE);
		}
		case 200:{
			response = json::parse(r.body);
			break;
		}
		default:{
			std::cerr << "Code:" << r.code << std::endl;
			std::cout << "Response:\n" << r.body << std::endl;
			exit(EXIT_FAILURE);
		}
	}	
	timer.stop();
	networkTime = timer.elapsed();
	
	timer.start();
	std::vector<json> bestMovies = response["items"];
	std::cout << "Response:\n" << bestMovies.size() << std::endl;
	

	for(uint32_t idx = 0; idx < 10; idx++){
		auto movie = bestMovies[idx];	
		std::cout << "rank           : " << movie["rank"] << std::endl;
		std::cout << "title          : "  << movie["title"] << std::endl;
		std::cout << "year           : "  << movie["year"] << std::endl;
		std::cout << "imDbRating     : " <<movie["imDbRating"] << std::endl;
		std::cout << "imDbRatingCount: " <<movie["imDbRatingCount"] << std::endl;
		std::cout << "--------" << std::endl;
	}
	timer.stop();
	processTime = timer.elapsed();
	
	std::cout << "======stats======" << std::endl;
	std::cout << "Network Time: " << networkTime << std::endl;
	std::cout << "Process Time: " << processTime << std::endl;
	
	
	return(EXIT_SUCCESS);
}









/*
	//hostURL = "https://api.adderou.cl/";
	//resourcePath = "/tyaas/"


json listaHoroscopo = response["horoscopo"];

for(const auto& foo : listaHoroscopo.items()){
	std::cout << foo.key() << std::endl;
}

json miHoroscopo =  response["horoscopo"]["sagitario"];

for(const auto& foo : miHoroscopo.items()){
	std::cout << foo.key() << ": ";
	std::cout << foo.value() << std::endl;
}
*/

