#include <iostream>

using namespace std;

class CMyStack
{
public: 
	CMyStack(int _iCapacity)
	{
		m_iCapacity = _iCapacity;
		m_pStack = new int[m_iCapacity];
	}


public:
	void Push(int _iPush)
	{
		if (Resize())
			m_pStack[++m_iTop] = _iPush;
	}

	void Pop()
	{
		if (m_iTop >= 0)
			m_pStack[m_iTop--] = 0;
	}

	bool Resize()
	{
		if (m_iCapacity-1 <= m_iTop)
		{
			m_iCapacity *= 2;
			int* pTmp = new int[m_iCapacity];
			for (int i = 0; i <= m_iTop; i++)
			{
				pTmp[i] = m_pStack[i];
			}
			delete[] m_pStack;
			m_pStack = pTmp;
			pTmp = nullptr;
		}

		return true;
	}

	int Size()
	{
		return m_iTop+1;
	}


	int Sum()
	{
		int iSum{};
		for (int i = 0; i <= m_iTop; i++)
			iSum += m_pStack[i];
		
		return iSum;
	}

private:
	int  m_iCapacity {};
	int  m_iTop{-1};
	int* m_pStack = { nullptr };
};


int main()
{

	int iK{};
	cin >> iK;

	CMyStack MyStack(iK);

	int iInputKey{};
	for (int i = 0; i < iK; i++)
	{
		cin >> iInputKey;
		if (iInputKey == 0)
			MyStack.Pop();
		else
			MyStack.Push(iInputKey);
	}

	cout << MyStack.Sum();

	return 0;
}