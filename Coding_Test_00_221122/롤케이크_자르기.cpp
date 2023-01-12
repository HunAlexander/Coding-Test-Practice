#include "Default.h"

/*

22-11-23 (시작)
https://school.programmers.co.kr/learn/challenges?order=recent&levels=2&languages=cpp
롤케이크 자르기

*/
using namespace std;

int solution1(vector<int> topping) {
	int answer = 0;
	int iSize = topping.size();

	set<int> t1;
	set<int> t2;

	for (int i = 0; i < iSize; ++i)
	{
		t1.clear();
		t2.clear();

		for (int j = 0; j < iSize; ++j)
		{
			if (i >= j)
			{
				t1.emplace(topping[j]);
			}
			else
			{
				t2.emplace(topping[j]);
			}
		}

		if (t1.size() == t2.size())
		{
			++answer;
		}
	}

	return answer;
}

int Count_Topping(vector<int> topping)
{
	set<int> tSet;

	for (int iter : topping)
	{
		tSet.emplace(iter);
	}

	return int(tSet.size());
}

int solution(vector<int> topping) {
	int answer = 0;
	int iSize = topping.size();

	vector<int> t1;
	vector<int> t2;

	auto begin = topping.begin();
	auto end = topping.end();


	for (int i = 1; i < iSize; ++i)
	{
		t1.clear();
		t2.clear();

		t1.assign(begin, begin + i);
		t2.assign(begin + i, end);

		if (Count_Topping(t1) == Count_Topping(t2))
			++answer;
	}

	return answer;
}

int main()
{
	vector<int> topping { 1, 2, 1, 3, 1, 4, 1, 2 };

	cout << solution(topping) << endl;

	system("pause");

	return 0;
}