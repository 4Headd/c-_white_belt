#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	 int Q;
	 cin >> Q;
	 map<string,string> country_capital;
	 for(int i = 0; i < Q; ++i){
		 string command;
		 cin >> command;
		 if(command == "CHANGE_CAPITAL"){
			 string country, new_capital;
			 cin >> country >> new_capital;
			 if(!country_capital.count(country)){
				 cout << "Introduce new country " << country  << " with capital " <<new_capital << endl;
				 country_capital[country] = new_capital;
			 }else{
			       // const string& old_capital = country_to_capital[country];
				 if(country_capital[country] == new_capital){
					 cout << "Country " << country << " hasn't changed its capital" << endl;
				 }else{
					 cout << "Country " << country << " has changed its capital from " << country_capital[country] << " to " << new_capital << endl;
					 country_capital[country] = new_capital;
				 }
			 }
		 }else{
			 if(command == "RENAME"){
				 string old_country_name, new_country_name;
				 cin >> old_country_name >> new_country_name;
				 if(old_country_name == new_country_name || !country_capital.count(old_country_name) || country_capital.count(new_country_name)){
					 cout << "Incorrect rename, skip" << endl;
				 }else{
					country_capital[new_country_name] = country_capital[old_country_name];
					cout << "Country " << old_country_name << " with capital " << country_capital[old_country_name] << " has been renamed to " << new_country_name << endl;
					country_capital.erase(old_country_name);
				 }
			 }else{
				 if(command == "ABOUT"){
					 string country;
					 cin >> country;
					 if(!country_capital.count(country)){
						 cout << "Country " << country << " doesn't exist" << endl;
					 }else{
						 cout << "Country " << country << " has capital " << country_capital[country] << endl;
					 }
				 }else{
					 if(command == "DUMP"){
						 if(country_capital.size() == 0){
							 cout << "There are no countries in the world" << endl;
						 }
						 else{
							 for(const auto& [country,capital] : country_capital){
								 cout << country << "/" << capital << " ";
							 }
							 cout << endl;
						 }
					 }
				 }
			 }

		 }
	 }
	return 0;
}
