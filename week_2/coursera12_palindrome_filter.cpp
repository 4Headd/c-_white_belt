
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string a) {
    for (size_t i = 0; i < a.size() / 2; ++i) {
        if (a[i] != a[a.size() - i - 1]) {
            return false;
        }
    }
    return true;
}


vector<string> PalindromFilter(vector<string> words, int minLength){
	vector<string> pal_words;
	for(auto i:words){
		if(IsPalindrom(i) && i.size() >= minLength){
			pal_words.push_back(i);
		}
	}
	return pal_words;
}

int main() {
	vector<string> a = {"","bro","code"};
	int length = 0;
	a = PalindromFilter(a,length);
	for(auto i:a){
		cout << i <<",";
	}
	return 0;
}
