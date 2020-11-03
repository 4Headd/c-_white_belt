#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v){
	vector<int> v_reversed;
	for(int i = v.size() - 1; i >= 0; --i){
		v_reversed.push_back(v[i]);
	}
	return v_reversed;
}


int main() {
	vector<int> v = {1,5,3,4,2};
	vector<int> v_reversed = Reversed(v);
	for(auto i:v_reversed){
		cout << i << " ";
	}
	return 0;
}
