#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


class CPoint
{
public:
	CPoint(int _iX, int _iY)
		:iX(_iX)
		, iY(_iY) {}
	
public:
	bool operator<(const CPoint& _Other)const
	{
		if (this->iX == _Other.iX)
			return this->iY < _Other.iY;
		return this->iX < _Other.iX;
	}

public:
	 int Get_iX()const { return iX; }
	 int Get_iY() const  { return iY; }

private:
	int iX	{};
	int iY	{};
};


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iN{};
	vector<CPoint> vPoint {};

	cin >> iN;


	int iX{}, iY{};
	for (int i = 0; i < iN; i++)
	{
		cin >> iX >> iY;
		vPoint.push_back(CPoint(iX, iY));
	}

	//sort(vPoint.begin(), vPoint.end(), [](const CPoint& _PointA, const CPoint& _PointB)->bool
	//	{
	//		if (_PointA.Get_iX() == _PointB.Get_iX())
	//			return _PointA.Get_iY() < _PointB.Get_iY();
	//		return _PointA.Get_iX() < _PointB.Get_iX();
	//	});

	sort(vPoint.begin(), vPoint.end());


	string strResult = "";
	for (const auto& iter : vPoint)
	{
		strResult += to_string(iter.Get_iX()) + " " + to_string(iter.Get_iY()) + "\n";
		//cout << iter.Get_iX() << " " << iter.Get_iY() << endl;
	}
	cout << strResult;
	return 0;
}