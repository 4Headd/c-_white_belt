#include <iostream>
#include <vector>
using namespace std;


int main() {
	int N;
	cin >> N;
	int temperature;
	int AverageTemperature = 0;
	vector<int> DaysTemperature;
	for(int i = 0; i < N; ++i){
		cin >> temperature;
		DaysTemperature.push_back(temperature);
		AverageTemperature += temperature;
	}
	AverageTemperature /= N;
	int counter = 0;
	for(int i = 0; i < DaysTemperature.size(); ++i){
		if(DaysTemperature[i] > AverageTemperature){
			++ counter;
		}
	}
	cout << counter << endl;
	for(int i = 0; i < DaysTemperature.size(); ++i){
		if(DaysTemperature[i] > AverageTemperature){
			cout << i << " ";
		}
	}
	return 0;
}
