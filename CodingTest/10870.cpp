#include <iostream>
#include "Define.h"
using namespace std;

int main() {
	INFO* m_pRecord = new INFO[10];



	return 0;
}





bool Load(INFO* _pRecord)
{
	FILE* pLoad = NULL;
	errno_t err = fopen_s(&pLoad, "../UserInfo.txt", "rb");
	if (0 == err)
	{
		fread(_pRecord, sizeof(INFO) * 10, 1, pLoad);
		fclose(pLoad);
		cout << "불러오기 성공" << endl;
		system("pause");
		return 0;
	}
	else
	{
		cout << "불러오기 실패" << endl;
		system("pause");
		return 1;
	}
}


void Save(INFO* _pRecord)
{
	FILE* pSave = NULL;
	errno_t err = fopen_s(&pSave, "../UserInfo.txt", "wb");
	if (0 == err)
	{
		fwrite(_pRecord, sizeof(INFO)*10, 1, pSave);
		cout << "저장 완료" << endl;
		fclose(pSave);
	}
	else
		cout << "저장 실패" << endl;
}
