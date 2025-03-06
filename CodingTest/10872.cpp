#include <iostream>

using namespace std;

int main()
{
	int iN{ -1 };

	while (0 > iN || iN > 12)
		cin >> iN;

	int iResult{1};
	for (int i = 1; i <= iN; i++)
		iResult *= i;

	cout << iResult;
	return 0;
}