#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

int main() {
	int Q;
	cin >> Q;
	map<set<string>,int> m;
	for(int i = 0; i < Q; ++i){
		int N;
		set<string> stops;
		cin >> N;
		for(int j = 0; j < N; ++j){
			string stop;
			cin >> stop;
			stops.insert(stop);
		}
		if(m.count(stops)){
			cout << "Already exists for " << m[stops] << endl;
		}else{
			const int index = m.size() + 1;
			m[stops] = index;
			cout << "New bus " << m[stops] << endl;
		}
	}
	return 0;
}
