
#include <iostream>
using namespace std;

int Factorial(int N){
	int factorialN = 1;
	if(N > 1){ // inecessary because for starts from 2
		for(int i = 1; i <= N; ++i){ // change i = 1 to i = 2
			factorialN *= i;
		}
	}
	return factorialN;
}


// recursion
int Factorial_recursion(int x) {
  if (x <= 1) {
    return 1;
  } else {
    return x * Factorial_recursion(x - 1);  // calculating (x - 1) factorial and multiplying it by x
  }
}

int main() {
	int N;
	cin >> N;
	cout << Factorial(N);
	return 0;
}
