#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string a){
	if(!a.empty()){
		string b;
		for(int i = a.size() - 1; i >= 0; --i){
			b += a[i];
		}
		if(a == b){
			return true;
		}
		else{
			return false;
		}
	}
	return true;
}

int main() {
	string a;
	cin >> a;
	if(IsPalindrom(a)){
		cout << "true";
	}
	else{
		cout << "false";
	}
	return 0;
}
