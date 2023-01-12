#include "Default.h"

/*

22-11-23 16:30
https://school.programmers.co.kr/learn/challenges?order=recent&levels=2&languages=cpp
연속 부분 수열 합의 개수

*/

using namespace std;

int solution(vector<int> elements) {
	int answer = 0;
	set<int> setSum;
	int iSize = elements.size();

	// 길이
	for (int i = 1; i <= iSize; ++i)
	{
		// 시작 인덱스
		for (int j = 0; j < iSize; ++j)
		{
			int iSum = 0;

			// 연결된 인덱스 오프셋
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

#pragma region == 다른 사람의 풀이 ==

// from 천민호, 김정식
//
// 추가 복습을 위해, 직접 다시 코드 입력했음
// 따라서, 원래 코드와 다를 수 있음

int solution_other_00(vector<int> elements) {
	int			iSize	= elements.size();
	int			iSum	= 0; // 길이에 따른 수열 합
	set<int>	setSum; // 수열 합의 set

	// 길이
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

#pragma endregion ! == 다른 사람의 풀이 ==


int main()
{
	cout << solution(vector<int>{7, 9, 1, 1, 4}) << endl;
	cout << solution_other_00(vector<int>{7, 9, 1, 1, 4}) << endl;

	system("pause");

	return 0;
}