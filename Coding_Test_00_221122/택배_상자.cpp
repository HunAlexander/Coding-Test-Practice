#include "Default.h"

/*

22-11-23
https://school.programmers.co.kr/learn/challenges?order=recent&levels=2&languages=cpp
택배 상자

*/

int solution(vector<int> order)
{
	int answer = 0;
	int iSize = static_cast<int>(order.size());
	int iIndex = 0;

	list<int> sub;

	for (int i = 1; i < iSize + 1; ++i)
	{
		if (order[iIndex] == i)
		{
			++answer;
			++iIndex;
		}
		else
		{
			sub.push_back(i);
		}

		while (!sub.empty() && sub.back() == order[iIndex])
		{
			++answer;
			++iIndex;
			sub.pop_back();
		}
	}

	return answer;
}

#pragma region		== 다른 사람의 풀이 ==

int solution_other_00(vector<int> order)
{
	int answer = 0;
	stack<int> stSub;

	for (int i = 1; i <= order.size(); ++i)
	{
		stSub.push(i);

		while (!stSub.empty() && stSub.top() == order[answer])
		{
			stSub.pop();
			++answer;
		}
	}

	return answer;
}

#pragma endregion ! == 다른 사람의 풀이 ==

int main()
{
	cout << solution(vector<int>{4, 3, 1, 2, 5}) << endl;
	cout << solution(vector<int>{5, 4, 3, 2, 1}) << endl;

	cout << solution_other_00(vector<int>{4, 3, 1, 2, 5}) << endl;
	cout << solution_other_00(vector<int>{5, 4, 3, 2, 1}) << endl;

	system("pause");

	return 0;
}