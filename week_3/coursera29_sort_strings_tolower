#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*bool ToLowerString(const string& a, const string& b){
	int k = 0;
	vector<bool> check;
	while(a[k] && b[k]){
		if(tolower(a[k]) < tolower(b[k])){
			check.push_back(tolower(a[k]) < tolower(b[k]));
		}
		++k;
	}
	for(const auto& item : check){
		if(item == 1){
			return true;
		}else{
			if(count(begin(check), end(check),0) == 0){
				return (a.size() < b.size());
			}else{
				return false;
			}
		}
	}
}*/

bool ToLowerString(const string& a, const string& b){
	string a_lower, b_lower;
	for(const auto& k : a){
		a_lower += tolower(k);
	}
	for(const auto& k : b){
		b_lower += tolower(k);
	}
	if(a_lower < b_lower){
		return true;
	}
	return false;
}

int main() {
	int N;
	cin >> N;
	vector<string> strings(N);
	for(auto& i : strings){
		cin >> i;
	}
	sort(begin(strings), end(strings), ToLowerString);
	for(const auto& i : strings){
		cout << i << " ";
	}
	return 0;
}
