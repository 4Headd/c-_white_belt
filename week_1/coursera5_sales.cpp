#include <iostream>
using namespace std;

int main() {
	double N,A,B,X,Y,newprice;
	cin >> N >> A >> B >> X >> Y;
	if(A<B){
		if(N > B){
			newprice = N*(100-Y)/100;
			cout << newprice;
		}
		else{
			if(N > A){
				newprice = N*(100-X)/100;
				cout << newprice;
			}
			else{
				cout << N;
			}
		}
	}
	return 0;
}
