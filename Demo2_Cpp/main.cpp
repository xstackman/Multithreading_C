#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono_literals;

void UpdateTemperatures(map<string,int> forecast){
	while(1){
		for(auto& item: forecast){
			item.second++;
			cout << item.first <<" " << item.second << endl;
		}
		this_thread::sleep_for(2000ms);
	}
}

int main(){
	
	map<string,int> forecastMap{
		{"Guayaquil",39},
		{"Quito",24},
		{"Cuenca",15}
	};

	thread main_worker(UpdateTemperatures,forecastMap);
	main_worker.join();

	return  0;


}
