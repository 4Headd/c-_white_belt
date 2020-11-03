#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> queue;
	int Q;
	cin >> Q;
	string command; // ������, � ������� ����� ��������� �������� �������
	int index; // ����������, � ������� ����� ��������� �����, ������������� �������
	for (int i = 0; i < Q; ++i) {
		cin >> command;
		if (command == "WORRY") {
			cin >> index;
			queue[index] = "WORRY";
		}
		else {
			if (command == "QUIET") {
				cin >> index;
				queue[index] = "QUIET";
			}
			else {
				if (command == "WORRY_COUNT") {
					int counter = 0;
					for (auto j : queue) {
						if (j == "WORRY") {
							++counter;
						}
					}
					cout << counter << endl;
				}
				else {
					cin >> index;
					if (command == "COME" && index < 0) {
						queue.resize(queue.size() + index);
					}
					else {
						if (command == "COME" && index >= 0) {
							int temp = queue.size(); // ������ ������� ��� ������� ������ ����� ���������� ������� (���� �� ��� ��� ��������)
							queue.resize(queue.size() + index);
							for (int j = temp; j < queue.size(); ++j) {
								queue[j] = "QUIET";
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
