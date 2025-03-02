#include <iostream>
#include <unordered_set>

using namespace std; 

int main()
{
	int iN{}, iM{}, iTmp{};
	unordered_set<int> usetN {};
	cin >> iN;

	for (int i = 0; i < iN; i++)
	{
		cin >> iTmp;
		usetN.insert(iTmp);
	}

	string strResult = "";

	cin >> iM;
	for (int i = 0; i < iM; i++)
	{
		cin >> iTmp;

		auto iter = usetN.find(iTmp);
		if (iter != usetN.end())
			strResult += "1 ";
		else 
			strResult += "0 ";
	}

	cout << strResult;

	return 0;
}