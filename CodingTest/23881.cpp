#include <iostream>
#include <string>
using namespace std;

int main()
{
	int iN{}, iK{};
	int* pArr{nullptr};

	cin >> iN >> iK;
	
	pArr = new int[iN];

	for (int i = 0; i < iN; i++)
		cin >> pArr[i];

	int iTmpIndex{  };
	int iChangeCount{};

	string strResult = "-1";

	for (int j = iN - 1; 0 <= j; j--)
	{
		iTmpIndex = j;

		for (int i = 0; i<j; i++)
		{
			if (pArr[iTmpIndex] < pArr[i])
			{
				iTmpIndex = i;
			}

		}

		if (iTmpIndex != j)
		{
			int iTmp = pArr[iTmpIndex];
			pArr[iTmpIndex] = pArr[j];
			pArr[j] = iTmp;
			iChangeCount++;

			if (iChangeCount == iK)
				strResult = (to_string(pArr[iTmpIndex]) + " " + to_string(pArr[j]));

		}

	}

	cout << strResult;

	delete[] pArr;

	return 0;
}