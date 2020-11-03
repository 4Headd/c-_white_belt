#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int Q;
	cin >> Q;
	vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int current_month = 0;
	vector<vector<string>> affairs(months[current_month]);
	for (int i = 0; i < Q; ++i) {
		string command;
		cin >> command;
		if (command == "ADD") {
			int day;
			string affair;
			cin >> day >> affair;
			affairs[day - 1].push_back(affair);
		}
		else {
			if (command == "DUMP") {
				int day;
				cin >> day;
				cout << affairs[day - 1].size() << " ";
				for (int j = 0; j < affairs[day - 1].size(); ++j) {
					cout << affairs[day - 1][j] << " ";
				}
				cout << endl;
			}
			else {
				if (command == "NEXT") {
					if (current_month != 11) {
						++current_month;
					}
					else {
						current_month = 0;
					}
					if (affairs.size() < months[current_month]) {
						affairs.resize(months[current_month]);
					}
					else {
						if (affairs.size() > months[current_month]) {
							for (int j = affairs.size() - 1; j > months[current_month] - 1; --j) {
								affairs[months[current_month] - 1].insert(end(affairs[months[current_month] - 1]), begin(affairs[j]), end(affairs[j]));
							}
						}
						affairs.resize(months[current_month]);
					}
				}
			}
		}

	}
	return 0;
}
