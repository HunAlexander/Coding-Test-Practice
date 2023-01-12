#include "Default.h"

/*

11-24 10:48
https://school.programmers.co.kr/learn/challenges?order=recent&levels=2&languages=cpp
두 큐의 합 같게 만들기

각자의 큐의 계산결과로 최종 결론?

*/

int Sum_Vector(vector<int> v)
{
	int iSum = 0;

	for (int iter : v)
	{
		iSum += iter;
	}

	return iSum;
}

int solution(vector<int> queue1, vector<int> queue2)
{
	int answer = -2;
	int iSize = queue1.size();

	vector<int> all = queue1;

	for (auto iter : queue2)
	{
		all.push_back(iter);
	}

	int iAllSize = all.size();

	vector<int> newq1, newq2;

	int iCount = 0;

	// 길이
	for (int i = 1; i < iAllSize; i++)
	{
		// 기준 인덱스
		for (int j = 0; j < iAllSize; j++)
		{
			newq1.clear();
			newq2.clear();

			if (i + j < iAllSize)
			{
				newq1.assign(all.begin() + j, all.begin() + j + i);

				// 처음부터 인덱스 전까지
				if (0 < j)
				{
					newq2.assign(all.begin(), all.begin() + j);
				}

				// 마지막 인덱스부터 마지막까지
				if (i + j < iAllSize)
				{
					if (newq2.empty())
					{
						newq2.assign(all.begin() + i + j, all.end());
					}
					else
					{
						for (int k = i + j; k < iAllSize; k++)
						{
							newq2.push_back(all[k]);
						}
					}
				}

			}
			else
			{
				// 두 번째 끝 인덱스
				int iSecondIndex = (i + j) % iAllSize;

				newq1.assign(all.begin() + j, all.end());

				if (newq1.empty())
				{
					newq1.assign(all.begin(), all.begin() + iSecondIndex);
				}
				else
				{
					for (int k = 0; k < iSecondIndex; k++)
					{
						newq1.push_back(all[k]);
					}
				}

				newq2.assign(all.begin() + iSecondIndex, all.begin() + j);
			}

			if (Sum_Vector(newq1) == Sum_Vector(newq2))
			{
				int iNew = 2 * j % iSize + abs(int(newq1.size()) - int(newq2.size()));

				if (iCount == 0)
				{
					iCount = iNew;
				}
				else if (iCount > iNew)
				{
					iCount = iNew;
				}
			}
		}
	}

	if (iCount == 0)
		return -1;
	else
		return iCount;
}

int main()
{
	//[1, 2, 1, 2]	[1, 10, 1, 2]
	cout << solution(vector<int>{3, 2, 7, 2}, vector<int>{4, 6, 5, 1}) << endl;
	cout << solution(vector<int>{1, 2, 1, 2}, vector<int>{1, 10, 1, 2}) << endl;

	system("pause");

	return 0;
}