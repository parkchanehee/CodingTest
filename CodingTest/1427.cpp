#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Down(char cA, char cB)
{
	return cA > cB;
}

int main()
{
	string strA = "";
	cin >> strA;

	vector<char> vA(strA.begin(), strA.end());
	
	sort(vA.begin(), vA.end(), Down);

	strA = { vA.begin(), vA.end() };

	cout << strA;
	return 0;
}