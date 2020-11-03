#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a,b,c;
	cin >> a >> b >> c;
	if(a != 0){
		double D;
		D = sqrt(b*b - 4*a*c);
		if (D >= 0){
			double x1,x2;
			x1 = ((-b + D)/2/a);
			x2 = ((-b - D)/2/a);
			if(x1 != x2){
				cout << x1 << " " << x2;
			}
			else{
				cout << x1;
			}
			}
		}
	else{
		if(b != 0){
			cout << (-c)/b;
		}
	}
	return 0;
}
