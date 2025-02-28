#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int iCount = 5;
	vector<int> vScore{};

	int iAverage{};

	int iScore{}, iCenter{};
	for (int i = 0; i < iCount; i++)
	{
		cin >> iScore;
		
		if (i != 0) 
		{
			for (int j = 0; j < vScore.size(); j++)
			{
				if (vScore[j] >= iScore)
				{
					int iTmp = vScore[j];
					vScore.insert(vScore.begin() + j + 1, iTmp);
					vScore[j] = iScore;
					break;

				}
				else
				{
					if (j == (vScore.size() - 1))
					{
						vScore.push_back(iScore);
						break;
					}
				}

			}
		}
		else
		{
			vScore.push_back(iScore);

		}

		iAverage += iScore;
	}
	iAverage /= iCount;
	iCenter = vScore[iCount / 2 ];


		cout << iAverage << endl;
		cout << iCenter << endl;





	return 0;
}