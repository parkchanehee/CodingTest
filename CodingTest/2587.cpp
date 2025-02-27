#include <iostream>

using namespace std;

int main()
{
	int arrScore[5]{};

	int iAverage{};

	for (auto& iter : arrScore)
	{
		cin >> arrScore[iter];
		iAverage += arrScore[iter];
	}


	iAverage /= 5;
	cout << iAverage;

	return 0;
}