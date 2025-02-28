#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class CPerson
{
public:
	CPerson(int _iAge, string& strName,int _iRecord)
		:m_iAge(_iAge)
		, m_strName(strName) 
		, m_iRecord(_iRecord)
	{}

public:
	bool operator<(const CPerson& _Other) const
	{
		if (this->m_iAge == _Other.m_iAge)
			return this->m_iRecord < _Other.m_iRecord;
		return this->m_iAge < _Other.m_iAge;
	}

public:
	const string& Get_strName() const{ return m_strName; }
	const int		Get_iAge() const { return m_iAge; }

private:
	string	m_strName{};
	int		m_iAge{};
	int		m_iRecord{};
};

int main()
{
	vector<CPerson> vPerson {};
	int iN{};
	cin >> iN;



	int iAge{};
	string strName{};
	for (int i = 0; i < iN; i++)
	{
		cin >> iAge;
		cin >> strName;
		vPerson.push_back(CPerson(iAge, strName,i));
	}

	sort(vPerson.begin(), vPerson.end());

	string strResult = "";
	for (const auto& Person : vPerson)
	{
		strResult += to_string(Person.Get_iAge()) + " " + Person.Get_strName() + "\n";
	}

	cout << strResult;
	return 0;
}