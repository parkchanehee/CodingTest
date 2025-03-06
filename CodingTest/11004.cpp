#include <iostream>
using namespace std;


int Partition(int* _pArr, int _iBegin, int _iEnd)
{
	int iPivot{}, iL{}, iR{}, iTmp{};

	iPivot = (_iBegin + _iEnd) / 2;
	iL = _iBegin;
	iR = _iEnd;

	
	while (iL < iR)
	{
		while (_pArr[iL] < _pArr[iPivot] && (iL<iR))iL++;
		while (_pArr[iR] >= _pArr[iPivot] && (iL < iR))iR--;


		if (iL < iR) {
			iTmp = _pArr[iL];
			_pArr[iL] = _pArr[iR];
			_pArr[iR] = iTmp;
		
			if (iL == iPivot)
				iPivot = iR;
		
		}
	}

	iTmp = _pArr[iPivot];
	_pArr[iPivot] = _pArr[iR];
	_pArr[iR] = iTmp;

	return iR; 
}


int QuickSort(int* _pArr, int _iBegin, int _iEnd, int _iFindIndex)
{
	int iPivot{};

	if (_iBegin < _iEnd)
	{
		iPivot = Partition(_pArr, _iBegin, _iEnd);

		if (iPivot == _iFindIndex)
			return _pArr[iPivot];
		else if(iPivot > _iFindIndex)
			return 		QuickSort(_pArr, _iBegin, iPivot - 1, _iFindIndex);
		else
		return QuickSort(_pArr, iPivot + 1,_iEnd, _iFindIndex);
	}
	return -1;
}


int main()
{
	int iN{}, iK{};
	int* pArr{ nullptr };

	cin >> iN >> iK;

	pArr = new int[iN];



	for (int i = 0; i < iN; i++)
	{
		cin >> pArr[i];
	}

int iResult= QuickSort(pArr, 0, iN-1,iK-1);


cout << iResult;


	return 0;
}