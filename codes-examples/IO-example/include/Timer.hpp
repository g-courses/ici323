#ifndef __TIMER_CLASS__
#define __TIMER_CLASS__ 

//Versión 1.0 : 2021-08-22

/*
	Forma de uso:

	Timer<std::chrono::milliseconds> timer1;

	timer1.start();
	//Bloque a medir;
	timer1.stop();

	//...

	std::cout << "Elapsed time: " << time1.elapsed() << std::endl;
	
*/

#include <chrono>
#include <ratio>

template <class TIME>
class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;

public:
	Timer(){}

	void start();
	void stop();
	
	
	double curr();
	
	double elapsed();

};

template <class TIME>
void Timer<TIME>::start()
{
	startTime = std::chrono::high_resolution_clock::now();
}

template <class TIME>
void Timer<TIME>::stop()
{
	endTime = std::chrono::high_resolution_clock::now();
}

template <class TIME>
double Timer<TIME>::curr()
{
	endTime = std::chrono::high_resolution_clock::now();
	auto e = std::chrono::duration_cast<TIME>(endTime - startTime);
	//auto e = std::chrono::duration<double, TIME>(endTime - startTime);
	return(e.count());
}


template <class TIME>
double Timer<TIME>::elapsed()
{
	//auto e = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
	auto e = std::chrono::duration_cast<TIME>(endTime - startTime);
	//auto e = std::chrono::duration<double, TIME>(endTime - startTime);
	return(e.count());
}


#endif