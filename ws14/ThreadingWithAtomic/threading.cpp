#include <thread>
#include <atomic>
#include <iostream>
#include <chrono>


using Counter=std::atomic<int>;

void show_counter(Counter const &theCounter){
	using std::chrono::milliseconds;
	while(theCounter.load()<10){
		std::cout << theCounter.load()<<std::endl;
		std::this_thread::sleep_for(milliseconds{100});
	}
}

void incrementer(Counter &theCounter){
	using std::chrono::seconds;
	for(int i=0; i < 20 ; ++i){
		std::this_thread::sleep_for(seconds{1});
		++theCounter;
		std::cout << "incrementer: "<< i << std::endl;
	}
}
void decrementer(Counter &theCounter){
	using std::chrono::milliseconds;
	for(int i=0; i < 10 ; ++i){
		--theCounter;
		std::cout << "decrementer: "<< i << std::endl;
		std::this_thread::sleep_for(milliseconds{200});
	}
}



int main(){
	Counter theCounter{};
	std::cout << "start"<< std::endl;
	std::thread show{show_counter,std::ref(theCounter)};
	std::thread inc{incrementer,std::ref(theCounter)};
	std::thread dec{decrementer,std::ref(theCounter)};
	std::cout << "ending..."<< std::endl;
	inc.join();
	dec.join();
	show.join();
}
