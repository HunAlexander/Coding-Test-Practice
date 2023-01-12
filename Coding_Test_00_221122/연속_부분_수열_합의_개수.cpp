#include "Default.h"

/*

22-11-23 16:30
https://school.programmers.co.kr/learn/challenges?order=recent&levels=2&languages=cpp
���� �κ� ���� ���� ����

*/

using namespace std;

int solution(vector<int> elements) {
	int answer = 0;
	set<int> setSum;
	int iSize = elements.size();

	// ����
	for (int i = 1; i <= iSize; ++i)
	{
		// ���� �ε���
		for (int j = 0; j < iSize; ++j)
		{
			int iSum = 0;

			// ����� �ε��� ������
			for (int k = 0; k < i; ++k)
			{
				if (j + k < iSize)
					iSum += elements[j + k];
				else
					iSum += elements[j + k - iSize];
			}

			cout << "iSum : " << iSum << endl;
			setSum.emplace(iSum);
		}
		cout << " ===== " << endl;
	}

	answer = setSum.size();

	return answer;
}

#pragma region == �ٸ� ����� Ǯ�� ==

// from õ��ȣ, ������
//
// �߰� ������ ����, ���� �ٽ� �ڵ� �Է�����
// ����, ���� �ڵ�� �ٸ� �� ����

int solution_other_00(vector<int> elements) {
	int			iSize	= elements.size();
	int			iSum	= 0; // ���̿� ���� ���� ��
	set<int>	setSum; // ���� ���� set

	// ����
	for (int i = 0; i < iSize; ++i)
	{
		iSum = 0;

		for (int j = i; j < i + iSize; ++j)
		{
			iSum += elements[j % iSize];
			setSum.insert(iSum);
		}
	}

	return setSum.size();
}

#pragma endregion ! == �ٸ� ����� Ǯ�� ==


int main()
{
	cout << solution(vector<int>{7, 9, 1, 1, 4}) << endl;
	cout << solution_other_00(vector<int>{7, 9, 1, 1, 4}) << endl;

	system("pause");

	return 0;
}