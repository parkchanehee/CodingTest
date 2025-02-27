#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	int iN{}, iM{};
	unordered_set<string> usetNStr{};

	cin >> iN >> iM;
	
	for (int i = 0; i < iN; i++)
	{
		string strN{};
		cin >> strN;
		usetNStr.insert(strN);
	}

	int iCount{};

	for (int i = 0; i < iM; i++)
	{
		string strM{};
		cin >> strM;
		if (usetNStr.find(strM) != usetNStr.end())
			iCount++;
	}

	cout << iCount;
	
	return 0;
}