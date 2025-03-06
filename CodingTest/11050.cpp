#include <iostream>

using namespace std;

int Factorial(int _iX)
{
	int iResult{ 1 };
	for (int i = 1; i <= _iX; i++)
		iResult *= i;

	return iResult;
}


int Binomial_Coefficient(int _iN, int _iK)
{
	int iResult = Factorial(_iN) / (Factorial(_iK) * Factorial(_iN - _iK));
	return iResult;
}


int main()
{
	int iN{}, iK{}, iResult{};

	cin >> iN >> iK;
	
	iResult=Binomial_Coefficient(iN, iK);

	cout << iResult;

	return 0;
}