#define OFF
#ifndef OFF

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main() {
	std::vector<int> s{ 5, 7, 4, 2, 8, 6, 9, 9, 0, 3 };
	std::sort(s.begin(), s.end(), std::greater<int>());
	int val = std::count_if(s.begin(), s.end(), [=](int val) {return val == s[0]; });
	return 0;
}

#endif