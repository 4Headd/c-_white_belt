#include <iostream>
#include <map>
#include <string>
using namespace std;


map<char,int> BuildCharCounters(const string& word){
	map<char,int> CharCounter;
	for(const auto& letter : word){
		++CharCounter[letter];
	}
	return CharCounter;
}
int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i){
		map<char,int> first_word_counter, second_word_counter;
		string first_word, second_word;
		cin >> first_word >> second_word;
		first_word_counter = BuildCharCounters(first_word); // ������
		second_word_counter = BuildCharCounters(second_word); // ������
		if(first_word_counter == second_word_counter){ // ��������� ������� ����� �������� �����
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
