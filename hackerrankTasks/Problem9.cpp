#include<vector>
#include <algorithm>
//C - 2D Arrays
using namespace std;


int accum(vector<vector<int>> &vec) {
	int Summ = 0;
	for_each(vec[0].begin(), vec[0].end(), [&Summ](int val) {Summ+= val; });
	for_each(vec[1].begin(), vec[1].end(), [&Summ](int val) {Summ+= val; });
	for_each(vec[2].begin(), vec[2].end(), [&Summ](int val) {Summ+= val; });
	return Summ;
}

vector<vector<int>> iterate(vector<vector<int>>& arr,int nFirstIndexRow = 0,int nFirstIndexCol = 0) {

	vector<vector<int>> arrRes(3);

	int nLastIndexRow = nFirstIndexRow + 2;
	int nLastIndexCol = nFirstIndexCol + 2;

	if (nLastIndexRow >= arr.size() || nLastIndexCol >= arr[nFirstIndexRow].size())
	{
		return arrRes;
	}
	int Summ1 = 0;
	for (; nFirstIndexRow < nFirstIndexRow+3; nFirstIndexRow++)
	{

		for (int nFirstIndexColIter = nFirstIndexCol; nFirstIndexColIter < nFirstIndexCol+3; nFirstIndexColIter++)
		{
			arrRes[0].push_back(arr[nFirstIndexRow][nFirstIndexColIter]);
			if (arrRes[1].size() == 0)
			{
				arrRes[1].push_back(arr[nFirstIndexRow + 1][nFirstIndexColIter + 1]);
			}
			
			arrRes[2].push_back(arr[nFirstIndexRow + 2][nFirstIndexColIter]);
		}

		nFirstIndexCol++;
		Summ1 = accum(arrRes);
		vector<vector<int>> arrNext(3);
		arrNext = iterate(arr, nFirstIndexRow, nFirstIndexCol);
		if (arrNext[0].size() == 0 && arrNext[1].size() == 0 && arrNext[2].size() == 0)
		{
			return arrRes;
		}
		int SummNext = accum(arrNext);
		if (SummNext > Summ1)
		{
			return arrNext;
		}
		else
		{
			return arrRes;
		}
	}
}

int hourglass(vector<vector<int>>& arr) {

	int MaxSummRes = 0;
	for (int nRow = 0; nRow < arr[0].size(); nRow++)
	{
		vector<vector<int>> arrRes(3);
		arrRes = iterate(arr, nRow);
		if (arrRes[0].size() == 0 && arrRes[1].size() == 0 && arrRes[2].size() == 0)
		{
			continue;
		}
		int SummNext = accum(arrRes);
		if (nRow == 0)
		{
			MaxSummRes = SummNext;
		}
		if (MaxSummRes < SummNext)
		{
			MaxSummRes = SummNext;
		}
	}

	return MaxSummRes;
}

int main() {

	vector<vector<int>> arr(6);

	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);
	}

	/*0 - 4 - 6 0 - 7 - 6
		- 1 - 2 - 6 - 8 - 3 - 1
		- 8 - 4 - 2 - 8 - 8 - 6
		- 3 - 1 - 2 - 5 - 7 - 4
		- 3 - 5 - 3 - 6 - 6 - 6
		- 3 - 6 0 - 8 - 6 - 7*/

	arr[0] = { 1 ,1 ,1 ,0 ,0 ,0 };
	arr[1] = { 0, 1, 0, 0, 0, 0 };
	arr[2] = { 1, 1, 1, 0, 0, 0 };
	arr[3] = { 0, 0, 2, 4, 4, 0 };
	arr[4] = { 0, 0, 0, 2, 0, 0 };
	arr[5] = { 0, 0, 1, 2, 4, 0 };
	
	/*arr[0] = { 0, - 4, - 6, 0, - 7, - 6 };
	arr[1] = { -1, - 2, - 6, - 8, - 3, - 1 };
	arr[2] = { -8, - 4, - 2, - 8, - 8, - 6 };
	arr[3] = { -3, - 1, - 2, - 5, - 7, - 4 };
	arr[4] = { -3, - 5, - 3, - 6, - 6, - 6 };
	arr[5] = { -3, - 6, 0, - 8, - 6, - 7 };*/

	hourglass(arr);

	
	return 0;
}