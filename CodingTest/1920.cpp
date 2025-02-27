#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iN{}, iM{};
	unordered_set<int> usetN {};
	vector<int> viM {};

	cin >> iN;
	for (int i = 0; i < iN; i++)
	{
		int iX;
		cin >> iX;
		usetN.insert(iX);
	}


	cin >> iM;
	for (int i = 0; i < iM; i++)
	{
		int iX;
		cin >> iX;
		viM.push_back(iX);
	}


	string strResult ="";
	for (auto iter : viM)
	{
		if (usetN.find(iter) != usetN.end())
			strResult += "1\n";
		else
			strResult += "0\n";
	}

	cout << strResult;
	return 0;
}