#include <iostream>

using namespace std; 

int main()
{
	int iA{}, iB{}, iV{};
	cin >> iA >> iB >> iV;

	int iDays{};
	int iResult{};

	while(1)
	{
		iDays++;
		iResult += iA;
		if (iResult >= iV)
		{
			break;
		}
		iResult -= iB;
	}
	cout << iDays;
	return 0;
}