// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define OFF

#ifndef OFF
#include <iostream>

int diagonalDifference(int arr_rows, int arr_columns, int** arr) {

	int nLeftDiagonalAcommulate = 0;
	int nRightDiagonalAcommulate = 0;

	for (int nRow = 0; nRow < arr_rows; nRow++)
	{
		int* pRowPointer = arr[nRow]; //указатель на строку массива

		for (int nColumnLeft = nRow;
			nColumnLeft < arr_columns &&  pRowPointer; nColumnLeft++) {
			int nColumnRight = arr_columns - nColumnLeft - 1;


			bool bIsFirstInRange = pRowPointer[nColumnLeft] >= -100 && pRowPointer[nColumnLeft] <= 100;
			bool bIsSecondInRange = pRowPointer[nColumnRight] >= -100 && pRowPointer[nColumnRight] <= 100;

			if (bIsFirstInRange && bIsSecondInRange) {
				nLeftDiagonalAcommulate += pRowPointer[nColumnLeft];
				nRightDiagonalAcommulate += pRowPointer[nColumnRight];//т.к. с 0
				break;
			}

		}
	}
	return abs(nLeftDiagonalAcommulate - nRightDiagonalAcommulate);
}

int main()
{
	A s;
	s.Method();
	const int nRows = 3;
	const int nCols = 3;

	int arr[nRows][nCols] = { {11,2,4},
							  {4,5,6},
							  {10,8,-12} 
							};


	int** pPointer = new int*[nRows + nCols];

	pPointer[0] = new int[3];
	pPointer[1] = new int[3];
	pPointer[2] = new int[3];


	pPointer[0][0] = 11;
	pPointer[0][1] = 2;
	pPointer[0][2] = 4;

	pPointer[1][0] = 4;
	pPointer[1][1] = 5;
	pPointer[1][2] = 6;

	pPointer[2][0] = 10;
	pPointer[2][1] = 8;
	pPointer[2][2] = -12;

	int res = diagonalDifference(nRows, nCols, pPointer);

    std::cout << "Hello World!\n";
}
#endif // OFF
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
