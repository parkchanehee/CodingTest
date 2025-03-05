#include <iostream>
#include <string>
using namespace std; 

int main()
{
	int* pArr{ nullptr };
	int iN{}, iK{}, iChangeCount{};
	string strResult = "-1";

	cin >> iN >> iK;
	pArr = new int[iN];

	for (int i = 0; i < iN; i++)
		cin >> pArr[i];
	

	for (int j = 1; j < iN; j++)
	{

		for (int i = 0; i < iN - j; i++)
		{

			if (pArr[i] > pArr[i + 1])
			{
				int iTmp{};
				iTmp = pArr[i];
				pArr[i] = pArr[i + 1];
				pArr[i + 1] = iTmp;
				iChangeCount++;

				if (iChangeCount == iK)
				{
					strResult = to_string(pArr[i])+" " + to_string(pArr[i + 1]);
				}
			}

		}

	}
	cout << strResult;
	return 0;
}

