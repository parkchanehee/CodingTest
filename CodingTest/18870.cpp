#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int iN{};
	vector<int> vX {};
	map<int, int > mapX {};

	cin >> iN;

	int iTmp{};
	for (int i = 0; i < iN; i++)
	{
		cin >> iTmp;
		vX.push_back(iTmp);
		mapX.insert({ iTmp,0 });
	}


	int iIndex{};
	for (auto& iter : mapX)
	{
		iter.second = iIndex++;
	}

	string strResult = "";

	for (auto& iter : vX)
	{

		strResult += to_string(mapX[iter]) + " ";

	}


	cout << strResult;


	return 0;
}