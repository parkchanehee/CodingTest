#include <iostream>
#include <set>

using namespace std;


void Input_String(set<string>* _setN, int _iCount)
{
	string strBuffer = "";
	for (int i = 0; i < _iCount; i++) 
	{
		cin >> strBuffer;
		_setN->insert(strBuffer);
	}
}

int main()
{
	int iN{}, iM{};
	set<string> setN{}, setM{};
	
	cin >> iN >> iM;

	Input_String(&setN, iN);
	Input_String(&setM, iM);

	string strResult = "";


	int iResultCount{};

		for (auto iterM : setM)
		{
			if (setN.find(iterM) != setN.end())
			{
				strResult += (iterM + "\n");
				iResultCount++;
			}
		}
	 
		cout << iResultCount << endl;
		cout << strResult;


	return 0;
}