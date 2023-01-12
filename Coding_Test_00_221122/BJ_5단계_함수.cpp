#include "Default.h"

#define _PROBLEM_NUMBER 1065

#ifndef _PROBLEM_NUMBER
#include <iostream>
using namespace std;
#endif // !_PROBLEM_NUMBER

// 0000 : 양식
int Solution_0000()
{
	return 0;
}

#pragma region 15596 : 정수 N개의 합

long long sum_15596(std::vector<int> &a) {
	long long ans = 0;

	for (long long iter : a)
	{
		ans += iter;
	}

	return ans;
};

int Solution_15596()
{
	vector<int> v { 10, 20, 30 };
	cout << sum_15596(v) << endl;

	return 0;
}

#pragma endregion ! 15596 : 정수 N개의 합

#pragma region 4673 : 셀프 넘버

int d_4673(int n)
{
	//int iCount = 0;
	//int iTemp = n;
	//int iAnswer = n;

	//while (iTemp != 0)
	//{
	//	iTemp = iTemp / 10;
	//	++iCount;
	//}

	//for (int i = 0; i <= iCount; i++)
	//{
	//	iAnswer += (n / (int)pow(10, i)) % 10;
	//}

	//return iAnswer;

	int iAnswer = n;
	while (n > 0)
	{
		iAnswer += n % 10;
		n = n / 10;
	}
	return iAnswer;
}

int Solution_4673()
{
	int arr[10000] = { 0 };

	for (int i = 0; i < 10000; i++)
	{
		int iIndex = d_4673(i + 1) - 1;
		if (iIndex >= 10000)
			continue;
		arr[iIndex] = iIndex + 1;
	}

	for (int i = 0; i < 10000; i++)
	{
		if (arr[i] == 0)
			cout << i + 1 << endl;
	}

	return 0;
}

#pragma endregion 

#pragma region 1065 : 한수

bool IsHansoo_1065(int n)
{
	if (100 > n)
		return true;

	int iCur = n % 10;
	int iNext = (n / 10) % 10;
	int iCurSub = 0;
	int iPreSub = iCur - iNext;

	while (true)
	{
		n = n / 10;

		if (0 == n)
			break;

		iNext = n % 10;

		iCurSub = iCur - iNext;

		if (iCurSub != iPreSub)
			return false;

		iPreSub = iCurSub;
		iCur = iNext;
	}
	return true;
}

int Solution_1065()
{
	int N = 0;
	int iCount = 0;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		if (true == IsHansoo_1065(i))
		{
			++iCount;
		}
	}
	cout << iCount << '\n';

	return 0;
}
#pragma endregion

int main()
{
	_APPEND_FUNC(Solution_, _PROBLEM_NUMBER);
	system("pause");
	return 0;
}