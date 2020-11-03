#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	cin >> a;
	int counter = 0;
	for(int i = 0; i < a.size(); ++i){
		if(a[i] == 'f'){
			++counter;
		}
		if(counter == 2){
			cout << i;
			break;
		}
	}
	if(counter == 0){
		cout << -2;
	}
	else {
		if(counter == 1){
			cout << -1;
		}
	}
	return 0;
}
