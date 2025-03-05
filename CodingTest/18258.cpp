#include <iostream>
#include <cstring>
#include <string>

using namespace std; 

class CMyQueue
{
public:
	CMyQueue(int _iCapacity)
	{
		m_iCapacity = _iCapacity;
		m_pQueue = new int[m_iCapacity];
		m_iSize = 0;
	}

	~CMyQueue()
	{
		if (m_pQueue != nullptr)
		{
			delete[] m_pQueue;
			m_pQueue = nullptr;
		}
	}

public:
	void Resize()
	{
		if (m_iSize >= m_iCapacity)
		{
			m_iCapacity *= 2;
			int* pTmp = new int[m_iCapacity];
			if (m_iFront > m_iBack)
			{
				memcpy(pTmp, &m_pQueue[m_iFront], sizeof(int) * (m_iCapacity - m_iFront));
				memcpy(&pTmp[(m_iCapacity - m_iFront)], &m_pQueue[0], sizeof(int) * (m_iBack));
			}
			else
			{
				memcpy(pTmp, m_pQueue, sizeof(int) * m_iSize);
			}
			delete[] m_pQueue;
			m_pQueue = pTmp;
		}
		else if (m_iSize < (m_iCapacity/2-1))
		{

		}


	}


	void Push(int _iX)
	{
		Resize();

		m_iSize++;

		m_iBack = (m_iBack + 1) % m_iCapacity;

		m_pQueue[m_iBack] = _iX;
				

		
	}


	int Pop()
	{
		Resize();

		int iTmp{-1};
		
		if (!IsEmpty())
		{
			m_iSize--;
			iTmp = m_pQueue[m_iFront];
		
			m_iFront = (m_iFront + 1) % m_iCapacity;
		}

		 
		return iTmp;
	}

	bool IsEmpty()
	{
		if (m_iSize <= 0)
			return true;
		else
			return false;
	}

	int Get_iSize()
	{
		return m_iSize;
	}

	int Get_iBack()
	{
		if (IsEmpty())
			return -1;
		else
			return m_pQueue[m_iBack];
	}

	int Get_iFront()
	{
		if (IsEmpty())
			return -1;
		else
			return m_pQueue[m_iFront];
	}


private:
	int*	m_pQueue		{nullptr};
	int		m_iCapacity		{};
	int		m_iSize			{0};

	int		m_iFront		{0};
	int		m_iBack         {-1};
};




int main()
{
	int iCommandCount{};
	string strCommand = "";
	string strResult = "";
	cin >> iCommandCount;

	CMyQueue Queue(iCommandCount);

	for (int i = 0; i < iCommandCount; i++)
	{
		cin >> strCommand;
		
		if (strCommand == "push")
		{
			int iTmp{};
			cin >> iTmp;
			Queue.Push(iTmp);
		}
		else if (strCommand == "pop")
		{
			//cout<<Queue.Pop()<<endl;
			strResult += (to_string(Queue.Pop()) + "\n");
		}
		else if (strCommand == "size")
		{
			//cout << Queue.Get_iSize() << endl;
			strResult += (to_string(Queue.Get_iSize()) + "\n");
		}
		else if (strCommand == "empty")
		{
			if (Queue.IsEmpty())
				//cout << '1' << endl;
				strResult += ("1\n");
			else
				//cout << '0' << endl;
				strResult += ("0\n");
		}
		else if (strCommand == "front")
		{
			//cout << Queue.Get_iFront() << endl;
			strResult += (to_string(Queue.Get_iFront()) + "\n");

		}
		else if (strCommand == "back")
		{
			cout << Queue.Get_iBack() << endl;
			strResult += (to_string(Queue.Get_iBack()) + "\n");

		}

	}

	cout << strResult;

	return 0;
}