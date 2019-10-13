#define OFF
#ifndef OFF
#include <iostream>
#include <string>


int factorial(int n) {
	int res = n;
	

	if (n == 1) {
		return 1;
	}
	n--;
	res = res * factorial(n);

	return res;
}

int main() {
	using namespace std;

	
	int n = 3;

	int res = factorial(n);

	return 0;
}
#endif