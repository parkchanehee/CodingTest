#include <iostream>
#include <set>
using namespace std;


void Insert_Set(set<int>& _setX, int _iCount)
{
	int iBuffer{};
	for (int i = 0; i < _iCount; i++)
	{
		cin >> iBuffer;
		_setX.insert(iBuffer);
	}
}

int main()
{
	int iA{}, iB{};
	set<int> setA{}, setB{};

	cin >> iA >> iB;
	Insert_Set(setA, iA);
	Insert_Set(setB, iB);

	for (auto iterA = setA.begin(); iterA != setA.end();)
	{
		auto iterB = setB.find(*iterA);
		if (iterB != setB.end())
		{
			iterA=setA.erase(iterA);
			setB.erase(iterB);
		}
		else
			iterA++;
	}

	int iResult{};
	iResult = setA.size() + setB.size();
	cout << iResult;

	return 0;
}