#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*

22-11-23
https://school.programmers.co.kr/learn/challenges?order=recent&levels=1&languages=cpp
기사단원의 무기

*/

int Get_Divisor_Count_00(int _number) {

	int iCount = 1; // 약수 개수

	for (int i = 1; i < _number; ++i)
	{
		if (0 == _number % i)
		{
			++iCount;
		}
	}

	cout << _number << " : " << iCount << endl;

	return iCount;
}

int Get_Divisor_Count_01(int _number) {

	int iCount = 0; // 약수 개수

	for (int i = 1; i * i <= _number; ++i)
	{
		if (0 == _number % i)
		{
			++iCount;
			if (i * i < _number)
			{
				++iCount;
			}
		}
	}

	cout << _number << " : " << iCount << endl;

	return iCount;
}

int solution(int number, int limit, int power) {
	int answer = 0;

	for (int i = 1; i <= number; ++i)
	{
		int iCount = Get_Divisor_Count_01(i);
		if (iCount > limit)
		{
			answer += power;
		}
		else
		{
			answer += iCount;
		}
	}

	return answer;
}

int main()
{
	cout << solution(5, 3, 2) << endl;

	system("pause");

	return 0;
}