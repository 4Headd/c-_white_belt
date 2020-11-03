#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int Q;
	cin >> Q;
	map<string,vector<string>> bus_to_stop, stop_to_bus;
	for(int i = 0; i < Q; ++i){
		string command;
		cin >> command;
		if(command == "NEW_BUS"){
			string bus_name, stop_name;
			int stop_count;
			cin >> bus_name >> stop_count;
			for(int j = 0; j < stop_count; ++j){
				cin >> stop_name;
				bus_to_stop[bus_name].push_back(stop_name);
				stop_to_bus[stop_name].push_back(bus_name);
			}
		}else{
			if(command == "BUSES_FOR_STOP"){
				string stop_name;
				cin >> stop_name;
				if(stop_to_bus.count(stop_name)){
					for(int j = 0; j < stop_to_bus[stop_name].size(); ++j){
						cout << stop_to_bus[stop_name][j] << " ";
					}
				}
				else{
					cout << "No stop";
				}
				cout << endl;
			}else{
				if(command == "STOPS_FOR_BUS"){
					string bus_name;
					cin >> bus_name;
					if(bus_to_stop.count(bus_name)){
					for(int j = 0; j < bus_to_stop[bus_name].size(); ++j){
						cout << "Stop " << bus_to_stop[bus_name][j] << ": ";
						for(int k = 0; k < stop_to_bus[bus_to_stop[bus_name][j]].size(); ++k){
							if(stop_to_bus[bus_to_stop[bus_name][j]].size() == 1){
								cout << "no interchange";
							}else{
								if(stop_to_bus[bus_to_stop[bus_name][j]][k] != bus_name){
									cout << stop_to_bus[bus_to_stop[bus_name][j]][k] << " ";
								}
							}
						}
						cout << endl;
					}
					}else{
						cout << "No bus" << endl;
					}
				}else{
					if(command == "ALL_BUSES"){
						if(bus_to_stop.size()){
						for(const auto& [bus,stops] : bus_to_stop){
							cout << "Bus " << bus << ": ";
							for(int j = 0; j < stops.size(); ++j){
								cout << stops[j] << " ";
							}
							cout << endl;
						}
					}else{
						cout << "No buses" << endl;
					}
					}
				}

			}
		}

	}
	return 0;
}
