#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iN{};
	vector<int> vN {};

	cin >> iN;

	int iTmp{};
	for (int i = 0; i < iN; i++)
	{
		cin >> iTmp;
		vN.push_back(iTmp);
	}

	sort(vN.begin(), vN.end());


	string strResult = "";
	for (auto iter : vN)
	{
		strResult += (to_string(iter) + "\n");
	}


	cout << strResult;
	return 0;
}
