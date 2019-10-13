#define OFF
#ifndef OFF

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

	int nTestCases = 0;
	cin >> nTestCases;
	cin.get();

	//fill the data
	std::vector<string> arrWords;
	for (int nCase = 0; nCase < nTestCases; nCase++) {
		string CurrentWord;

		getline(cin, CurrentWord);
		arrWords.push_back(CurrentWord);
	}

	for (auto& currentWord : arrWords) {
		string currentStr = currentWord;

		string strResult_1;
		string strResult_2;
		int Counter = 0;
		for (string::const_iterator it = currentStr.begin(); it != currentStr.end(); ++it, ++Counter) {
			if (Counter % 2 == 0) {
				strResult_2 += *it;
			}
			else {
				strResult_1 += *it;
			}
		}

		cout << strResult_2 << " " << strResult_1 << endl;
	}

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}

#endif