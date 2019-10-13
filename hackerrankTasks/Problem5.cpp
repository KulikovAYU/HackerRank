#define OFF
#ifndef OFF
#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

/*
 * Complete the timeConversion function below.
 */



int ConvertPM(string strHourValue) {
	int nHourValue = stoi(strHourValue);

	//Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.
	if (nHourValue < 12 && nHourValue > 0)
	{
		nHourValue += 12;
	}
	return nHourValue;
}


int ConvertAM(string strHourValue) {

	int nHourValue = stoi(strHourValue);

	//Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.
	if (nHourValue >= 12 && nHourValue > 0)
	{
		nHourValue -= 12;
	}
	return nHourValue;
}


string timeConversion(string s) {
	string strRes = s;
	std::size_t nFoundPM = s.find("PM"); //после полудня

	if (nFoundPM != string::npos)
	{
		strRes = strRes.substr(0, nFoundPM);
		std::size_t nHourPos = strRes.find(":");
		
		if (nHourPos != string::npos)
		{
			string strHourValue = strRes.substr(0, nHourPos);

			int nHourValue = ConvertPM(strHourValue);

			strHourValue = to_string(nHourValue);

			strRes.replace(0, nHourPos, strHourValue);
		}
	}
	else if(std::size_t nFoundAM = s.find("AM"))

	{
		strRes = strRes.substr(0, nFoundAM);

		std::size_t nHourPos = strRes.find(":");

		if (nHourPos != string::npos)
		{
			string strHourValue = strRes.substr(0, nHourPos);

			int nHourValue = ConvertAM(strHourValue);

			string zeroVal = "0";

			strHourValue = to_string(nHourValue);
			
			zeroVal += strHourValue;

			std::swap(zeroVal, strHourValue);

			strRes.replace(0, nHourPos, strHourValue);
		}
	}


	return strRes;
}

int main()
{
	string s = "06:40:03AM";
	string result = timeConversion(s);

	cout << result << "\n";

	return 0;
}
#endif