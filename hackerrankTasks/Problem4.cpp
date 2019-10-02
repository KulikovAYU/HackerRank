#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long int(*pFunc)(vector<int> arr, int nPos);

unsigned long int MinSumm(vector<int> arr, int nPos = 0) {

	unsigned long int Value = 0;
	for (int nEl = 0; nEl < arr.size(); nEl++)
	{
		if (nEl == nPos) {
			continue;
		}
		Value += arr[nEl];
	}
	nPos++;
	if (nPos != arr.size()) {
		unsigned long int result = MinSumm(arr, nPos);
		if (result < Value) {
			Value = result;
		}
	}
	return Value;
}


unsigned long int MaxSumm(vector<int> arr, int nPos = 0) {

	unsigned long int Value = 0;
	for (int nEl = 0; nEl < arr.size(); nEl++)
	{
		if (nEl == nPos) {
			continue;
		}
		Value += arr[nEl];
	}
	nPos++;
	if (nPos != arr.size()) {
		long long result = MaxSumm(arr, nPos);
		if (result  >Value) {
			Value = result;
		}
	}
	return Value;
}

long long Calculate(vector<int> arr, pFunc func) {
	return func(arr,0);
}

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {

	unsigned long int nMinSumm = Calculate(arr, MinSumm);
	unsigned long int nMaxSumm = Calculate(arr, MaxSumm);

	std::cout << nMinSumm << " " << nMaxSumm;
}

int main() {

	vector<int> arrInput = { 396285104, 573261094, 759641832, 819230764, 364801279 };
	miniMaxSum(arrInput);

	return 0;
}