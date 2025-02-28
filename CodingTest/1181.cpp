#include <iostream>
#include <set>

using namespace std;


class MyString
{
public:
	MyString(const string& strString)
		: strMyString(strString) {}


public:
	bool operator<(const MyString& _Other) const
	{
		if(this->strMyString.size() == _Other.strMyString.size())
			return this->strMyString < _Other.strMyString;

		return this->strMyString.size() < _Other.strMyString.size();
	}

public:
	const string& Get_Mystring() const { return strMyString; }

private:
	 
	string strMyString{};
};

int main() 
{
	set<MyString> setWord {};
	int iN{};
	cin >> iN;


	string strTmp = "";
	for (int i = 0; i < iN; i++)
	{
		cin >> strTmp;
		setWord.insert(MyString(strTmp));
	}

	string strResult = "";
	for (const auto& iter : setWord)
	{
		strResult += iter.Get_Mystring() + "\n";
	}

	cout << strResult;

	return 0;
}