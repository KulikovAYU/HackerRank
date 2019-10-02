#define OFF
#ifndef OFF
#include <iostream>
#include <vector>

using namespace std;

void plusMinus(vector<int> arr) {

	if (arr.size() == 0) {
		return;
	}

	size_t positiveCnt = 0;
	size_t negativeCnt = 0;
	size_t zeroCnt = 0;

	for (const auto& currVal : arr) {
		if (currVal > 0) {
			positiveCnt++;
		}
		else if (currVal < 0) {
			negativeCnt++;
		}
		else {
			zeroCnt++;
		}
	}

	std::cout << (double)positiveCnt / arr.size() << std::endl;
	std::cout << (double)negativeCnt / arr.size() << std::endl;
	std::cout << (double)zeroCnt / arr.size() << std::endl;

}



int main() {

	vector<int> testVector = { -4 ,3, -9, 0, 4, 1 };
	plusMinus(testVector);
	return 0;
}
#endif // OFF