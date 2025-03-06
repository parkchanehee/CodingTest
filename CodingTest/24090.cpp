#include <iostream>

using namespace std;

static int iA{}, iB{}, iK{}, iCount{};

int Partition(int* _pArr, int _iBegin, int _iEnd)
{
    int iPivot = _pArr[_iEnd]; //피봇을 끝 값으로 
    int iLeftIndex{ _iBegin - 1 };//작은 원소들의 끝 지점 
    int iTmp{};

    for (int j = _iBegin; j < _iEnd; j++)
    {
        if (_pArr[j] <= iPivot) //피봇보다 작으면 
        {
            iTmp = _pArr[++iLeftIndex];
            _pArr[iLeftIndex] = _pArr[j];
            _pArr[j] = iTmp;
            iCount++;
            if (iCount == iK)
            {
                iA = _pArr[iLeftIndex];
                iB = _pArr[j];
            }
        }

    }

    //j 다돌리고 (end -1 까지)
    if (iLeftIndex + 1 != _iEnd) //끝지점+1 이 앤드가 아니면
    {
        iTmp = _pArr[iLeftIndex + 1];
        _pArr[iLeftIndex + 1] = _pArr[_iEnd];
        _pArr[_iEnd] = iTmp;

        iCount++;
        if (iCount == iK)
        {
            iA = _pArr[iLeftIndex + 1];
            iB = _pArr[_iEnd];
        }
    }

    return iLeftIndex + 1;
}

void Quick_Sort(int* _pArr, int _iBegin, int _iEnd)
{
    int iPartition{};

    if (_iBegin < _iEnd)
    {
        iPartition = Partition(_pArr, _iBegin, _iEnd);
        Quick_Sort(_pArr, _iBegin, iPartition - 1);
        Quick_Sort(_pArr,iPartition +1, _iEnd);

    }
}




int main()
{
    int iN{};
    int* pArr{ nullptr };

    cin >> iN >> iK;

    pArr = new int[iN];
    
    for (int i = 0; i < iN; i++)
        cin >> pArr[i];
    
    Quick_Sort(pArr, 0, iN - 1);

    if (iA != 0)
        cout << iA << " " << iB;
    else
        cout << -1;

    return 0;
}