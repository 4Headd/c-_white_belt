#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

string GetNameFromMap(const map<int, string>& m, int year) {
	string NameFromMap;
	for (const auto& item : m) {
		if (year >= item.first) {
			NameFromMap = item.second;
		}
		else {
			break;
		}
	}
	return NameFromMap;
}

void FindString(vector<string>& names) {
	if (names.size() > 1) {
		for (int i = 0; i < names.size() - 1; ++i) {
			if (names[i] == names[i + 1]) {
				names.erase(begin(names) + i);
				--i;
			}
		}
	}
}

vector<string> GetNamesFromMap(const map<int, string>& m, int year) {
	vector<string> NamesFromMap;
	for (const auto& item : m) {
		if (year >= item.first) {
			NamesFromMap.push_back(item.second);
		}
		else {
			break;
		}
	}
	FindString(NamesFromMap);
	return NamesFromMap;
}

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
		if (GetNameFromMap(year_to_first_name, year).size() && GetNameFromMap(year_to_last_name, year).size()) {
			return (GetNameFromMap(year_to_first_name, year) + " " + GetNameFromMap(year_to_last_name, year));
		}
		else {
			if (GetNameFromMap(year_to_first_name, year).size()) {
				return (GetNameFromMap(year_to_first_name, year) + " with unknown last name");
			}
			else {
				if (GetNameFromMap(year_to_last_name, year).size()) {
					return (GetNameFromMap(year_to_last_name, year) + " with unknown first name");
				}
				else {
					return "Incognito";
				}
			}
		}
	}
	string GetFullNameWithHistory(int year) {
		const vector<string> names_history = GetNamesFromMap(year_to_first_name, year);
		const vector<string> surnames_history = GetNamesFromMap(year_to_last_name, year);
		string name_vec_to_string, surname_vec_to_string;
		string cur_name = "";
		string cur_surname = "";
		if (names_history.size()) {
			cur_name = names_history[names_history.size() - 1];
		}
		if (surnames_history.size()) {
			cur_surname = surnames_history[surnames_history.size() - 1];
		}
		if (names_history.size() > 1) {
			for (int i = names_history.size() - 2; i >= 0; --i) {
				name_vec_to_string += names_history[i] + ", ";
			}
			name_vec_to_string.erase(name_vec_to_string.size() - 1);
			name_vec_to_string.erase(name_vec_to_string.size() - 1);
		}
		if (surnames_history.size() > 1) {
			for (int i = surnames_history.size() - 2; i >= 0; --i) {
				surname_vec_to_string += surnames_history[i] + ", ";
			}
			surname_vec_to_string.erase(surname_vec_to_string.size() - 1);
			surname_vec_to_string.erase(surname_vec_to_string.size() - 1);
		}
		if (names_history.size() > 1 && surnames_history.size() > 1) {
			return (cur_name + " (" + name_vec_to_string + ") " + cur_surname + " (" + surname_vec_to_string + ")");
		}
		else {
			if (names_history.size() > 1 && surnames_history.size() == 0) {
				return (cur_name + " (" + name_vec_to_string + ") with unknown last name");
			}
			else {
				if (surnames_history.size() > 1 && names_history.size() == 0) {
					return (cur_surname + " (" + surname_vec_to_string + ") with unknown first name");
				}
				else {
					if (names_history.size() == 1 && surnames_history.size() == 1) {
						return (cur_name + " " + cur_surname);
					}
					else {
						if (names_history.size() > 1 && surnames_history.size() == 1) {
							return (cur_name + " (" + name_vec_to_string + ") " + cur_surname);
						}
						else {
							if (surnames_history.size() > 1 && names_history.size() == 1) {
								return (cur_name + " " + cur_surname + " (" + surname_vec_to_string + ")");
							}
							else {
								if (names_history.size() == 1 && surnames_history.size() == 0) {
									return (cur_name + " with unknown last name");
								}
								else {
									if (surnames_history.size() == 1 && names_history.size() == 0) {
										return (cur_surname + " with unknown first name");
									}
									else {
										return "Incognito";

									}
								}
							}
						}
					}
				}
			}
		}
		// �������� ��� ����� � ������� �� ��������� �� ����� ���� year
	}
private:
	string current_name, current_surname;
	map<int, string> year_to_first_name;
	map<int, string> year_to_last_name;
};

int main() {
	/*Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;*/
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;
	return 0;
}
