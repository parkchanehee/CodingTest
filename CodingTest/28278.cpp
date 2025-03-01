#include <iostream>
#include <stack>
using namespace std; 



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int iN{};
	int iInputKey{};

	stack<int> MyStack{};
	cin >> iN;

	while (iN--)
	{
		cin >> iInputKey;
		int iTmp{};
		switch (iInputKey)
		{
		case 1:
			cin >> iTmp; 
			MyStack.push(iTmp);
			break;
		case 2:
			if (MyStack.empty())
				cout << -1 << "\n";
			else
			{
				cout << MyStack.top() << "\n";

				MyStack.pop();
			}
			break;
		case 3:
			cout << MyStack.size() << "\n";
			break;
		case 4:
			if (MyStack.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
			break;
		case 5:
			if (MyStack.empty())
				cout << -1 << "\n";
			else
				cout << MyStack.top() << "\n";
			break;
		default:
			break;
		}

	}

	return 0;
}