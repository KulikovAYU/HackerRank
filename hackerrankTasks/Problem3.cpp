#define OFF
#ifndef OFF
#include <iostream>
#include <vector>
using namespace std;

void staircase(int n) {

	for (int nRows = 0; nRows < n; nRows++) {

		int nSpaceIndex = n - nRows - 1;

		for (int nCol = 0; nCol < n; nCol++) {

			if (nSpaceIndex <= nCol) {
				cout << "#";
			
			}
			else {
				cout << " ";
			}
		}

		cout << endl;
	}
}

int main() {

	staircase(6);
	return 0;
}

#endif