#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	int Q;
	cin >> Q;
	map <vector<string>, int> roads;
	for(int i = 0; i < Q; ++i){
		int N;
		cin >> N;
		vector<string> stops;
		for (int j = 0; j < N; ++j){
			string stop;
			cin >> stop;
			stops.push_back(stop);
		}
		if(!roads.count(stops)){
			roads[stops]; 					// ����� �������� ���������� ��������� ������� ������ ���� + 1
			roads[stops] = roads.size();    // � ��������� Ũ �����
			cout << "New bus " << roads[stops] << endl;
		}else{
			cout << "Already exists for ";
			for(const auto& item : roads){ // ������ �� roads[stop] ������ ������ ��������
				if(item.first == stops){
					cout << item.second <<endl;
					break;
				}
			}
		}
	}
	return 0;
}
