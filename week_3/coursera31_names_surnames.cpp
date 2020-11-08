#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		current_name = first_name;
		year_to_first_name[year] = current_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		current_surname = last_name;
		year_to_last_name[year] = current_surname;
	}
	string GetFullName(int year) {
		int temp_year_name = -1;
		int temp_year_last = -1;
		for (const auto& item : year_to_first_name) {
			if (year >= item.first){
				temp_year_name = item.first;
			}
		}
		for (const auto& item : year_to_last_name) {
			if (year >= item.first) {
				temp_year_last = item.first;
			}
		}
		if (temp_year_name == -1 && temp_year_last == -1) {
			return "Incognito";
		}
		else {
			if (temp_year_name == -1) {
				return (year_to_last_name[temp_year_last] + " with unknown first name");
			}
			else {
				if (temp_year_last == -1) {
					return (year_to_first_name[temp_year_name] + " with unknown last name");
				}
				else {
					return(year_to_first_name[temp_year_name] + " " + year_to_last_name[temp_year_last]);
				}
			}
		}
	}
private:
	string current_name, current_surname;
	map<int, string> year_to_first_name;
	map<int, string> year_to_last_name;
};

int main() {
	Person dude;
	dude.ChangeFirstName(1965, "Polina");
	dude.ChangeLastName(1967, "Sergeeva");
	for (int year : {1950, 1965, 1967}) {
		cout << dude.GetFullName(year) << endl;
	}
	dude.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << dude.GetFullName(year) << endl;
	}
	dude.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << dude.GetFullName(year) << endl;
	}
	return 0;
}
