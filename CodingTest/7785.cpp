#include <iostream>
#include <map>
using namespace std;

int main()
{
	int iRecord{};
	map<string, string,greater<string>> umapRecord{};
	cin >> iRecord;

	for (int i = 0; i < iRecord; i++)
	{
		string key, value;
		cin >> key >> value;
		umapRecord[key] = value;
	}

	string strResult = "";
	for (const auto& pair : umapRecord)
	{
		if (pair.second == "enter")
		{
			strResult += pair.first;
			strResult += "\n";
		}
	}

	cout << strResult;

	return 0;
}