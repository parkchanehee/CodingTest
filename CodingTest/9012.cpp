#include <iostream>
#include <stack>

using namespace std;


class CPS
{
public:
	CPS()
	{
		m_pPS = new char[50];
	}
	~CPS()
	{
		if (m_pPS)
		{
			delete[] m_pPS;
			m_pPS = nullptr;
		}
	}

public:
	void Push(char _cX)
	{
		if (m_pPS[m_iTop] == '(' && _cX == ')')
			Pop();
		else 
			m_pPS[++m_iTop] = _cX;
	}

	void Pop()
	{
		if(m_iTop>=0)
			m_pPS[m_iTop--] = '\0';
	}

	bool IsVPS()
	{
		if (m_iTop < 0)
			return true;
		else
			return false;
	}


private:
	int		m_iTop{-1};
	char*	m_pPS = nullptr;
};



int main()
{
	int iT{};
	cin >> iT;

	string strResult = "";
	string strPs = "";

	for (int i = 0; i < iT; i++)
	{
		CPS Ps{};

		cin >> strPs;

		for (auto& iter : strPs)
			Ps.Push(iter);

		if (Ps.IsVPS())
			strResult += "YES\n";
		else
			strResult += "NO\n";
		
	}

	cout << strResult;


	return 0;
}