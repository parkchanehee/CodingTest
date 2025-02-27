#include <iostream>
#include <unordered_map>
#include <string>
using namespace std; 


int main()
{
	int iN{}, iM{};
	unordered_map<int, int> umapiN{};

	int iBuffer{};
	cin >> iN;

	for (int i = 0; i < iN; i++)
	{
		cin >> iBuffer;

		auto iter = umapiN.find(iBuffer);

		if (iter != umapiN.end())
			iter->second++;
		else
			umapiN.insert({iBuffer,1});

	}

	cin >> iM;
	string strResult = "";

	for (int i = 0; i < iM; i++)
	{
		cin >> iBuffer;

		auto iter = umapiN.find(iBuffer);

		if (iter == umapiN.end())
			strResult += "0";
		else
			strResult += to_string( iter->second);

		strResult += " ";
	}
	

	cout << strResult;


	return 0;
}