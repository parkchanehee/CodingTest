#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int iN{};
	stack<int> stackTmp{};
	cin >> iN;
	
	int iCutNum { 1 }, iInput{};


	while (1)
	{
		if (!stackTmp.empty())
		{
			if (iCutNum == stackTmp.top())
			{
				stackTmp.pop();
				iCutNum++;
				continue;
			}
			else if (iCutNum != stackTmp.top() && iN <= 0)
			{
				cout << "Sad";
				return 0;
			}
		}
		else if (stackTmp.empty() && iN <= 0)
		{
			cout << "Nice";
			return 0;
		}

		if (iN > 0)
		{
			cin >> iInput;
			iN--;
			if (iInput == iCutNum)
			{
				iCutNum++;
			}
			else
			{
				stackTmp.push(iInput);
			}
		}



	}

	return 0;
}