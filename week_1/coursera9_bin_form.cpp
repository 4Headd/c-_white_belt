#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> bin;
	cin >> N;
	if(N > 0){
		while(N != 0){
			if(N % 2 == 1){
				bin.push_back(1);
			}
			else{
				bin.push_back(0);
			}
			N = N / 2;
		}
		for(int i = bin.size()-1; i >= 0; --i){
			cout << bin[i];
		}
	}
	else{
		if(N == 0){
			cout << 0;
		}
	}
	return 0;
}
