#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

struct Counter { // A Monitor Object
	void inc();
	void dec();
	int get() const;
private:
	mutable std::mutex lock;
	int counter{};
};


void Counter::inc() {
	std::lock_guard<std::mutex> guard(lock);
	++counter;
}

void Counter::dec() {
	std::lock_guard<std::mutex> guard(lock);
	--counter;
}

int Counter::get() const {
	std::lock_guard<std::mutex> guard(lock);
	return counter;
}

void show_counter(Counter const &theCounter){
	using std::chrono::milliseconds;
	while(theCounter.get()<10){
		std::cout << theCounter.get()<<std::endl;
		std::this_thread::sleep_for(milliseconds{100});
	}
}

void incrementer(Counter &theCounter){
	using std::chrono::seconds;
	for(int i=0; i < 20 ; ++i){
		std::this_thread::sleep_for(seconds{1});
		theCounter.inc();
		std::cout << "incrementer: "<< i << std::endl;
	}
}
void decrementer(Counter &theCounter){
	using std::chrono::milliseconds;
	for(int i=0; i < 10 ; ++i){
		theCounter.dec();
		std::cout << "decrementer: "<< i << std::endl;
		std::this_thread::sleep_for(milliseconds{900});
	}
}



int main(){
	Counter theCounter;
	std::cout << "start"<< std::endl;
	std::thread show{show_counter,std::ref(theCounter)};
	std::thread inc{incrementer,std::ref(theCounter)};
	std::thread dec{decrementer,std::ref(theCounter)};
	std::cout << "ending..."<< std::endl;
	inc.join();
	dec.join();
	show.join();
}
