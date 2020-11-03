#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	set<string> strings;
	for(int i = 0; i < N; ++i){
		string something;
		cin >> something;
		strings.insert(something);
	}
	cout << strings.size();
	return 0;
}
