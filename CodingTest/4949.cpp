#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{

	stack<char> sPs{};
	
	string strResult = "";

	char strPs[101]{};

	while (1)
	{
		cin.getline(strPs,101);
		if (strPs[0] == '.')
			break;

		for (auto& X : strPs)
		{
			switch (X)
			{
			case ')':
				if (!sPs.empty() && sPs.top() == '(')
					sPs.pop();
				else
					sPs.push(X);
				break;

			case ']':
				if (!sPs.empty() && sPs.top() == '[')
					sPs.pop();
				else
					sPs.push(X);
				break;

			case '(':
			case '[':
				sPs.push(X);
				break;

			case '.':
				if (sPs.empty())
					strResult += "yes\n";
				else
					strResult += "no\n";

				sPs = stack<char>();
				break;

			default:
				break;
			}
		}
		memset(strPs, 0, sizeof(strPs));
	}
	
	cout << strResult;

	return 0;
}