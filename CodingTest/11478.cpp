#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	string strS = "";
	unordered_set<string> usetS{};
	int iLastIndex{};

	cin >> strS;

	iLastIndex = strS.size() - 1;

	for (int i = 1; i <= iLastIndex+1; i++)
	{
		for (int j = 0; j <= iLastIndex-i+1; j++)
		{
			usetS.insert(strS.substr(j, i));
		}
	}

	cout << usetS.size();

	return  0;
}