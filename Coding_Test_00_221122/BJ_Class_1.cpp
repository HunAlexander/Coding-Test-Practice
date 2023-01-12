#include "Default.h"

#define _PROBLEM_NUMBER 2742

/* == template ==

#include <iostream>
using namespace std;

#include <cmath>

int Solution_0000()
{
	return 0;
}
*/
#define ENDL '\n'

#define POW(a) ((a) * (a))

#pragma region 2920 : 음계

int Solution_2920()
{
	int arriInput[8] = { 0 };
	int arrAsc[8] = { 0 };
	int arrDec[8] = { 0 };
	int* pCmpArr = nullptr;
	bool bAsc = false;

	for (int i = 0; i < 8; i++)
	{
		arrAsc[i] = i + 1;
		arrDec[i] = 8 - i;
	}

	for (int& iInput : arriInput)
	{
		cin >> iInput;
	}

	if (1 == arriInput[0])
	{
		bAsc = true;
		pCmpArr = arrAsc;
	}
	else if (8 == arriInput[0])
	{
		bAsc = false;
		pCmpArr = arrDec;
	}
	else
	{
		cout << "mixed" << ENDL;
		return 0;
	}

	for (size_t i = 0; i < 8; i++)
	{
		if (arriInput[i] != pCmpArr[i])
		{
			cout << "mixed" << ENDL;
			return 0;
		}
	}

	if (bAsc)
		cout << "ascending" << ENDL;
	else
		cout << "descending" << ENDL;

	return 0;
}

int Solution_2920_00()
{
	int arriInput[8] = { 0 };

	for (int& iInput : arriInput)
	{
		cin >> iInput;
	}

	if (1 == arriInput[0])
	{
		for (int i = 1; i < 8; i++)
		{
			if (arriInput[i] != i + 1)
			{
				cout << "mixed" << ENDL;
				return 0;
			}
		}
		cout << "ascending" << ENDL;
		return 0;
	}
	else if (8 == arriInput[0])
	{
		for (int i = 1; i < 8; i++)
		{
			if (arriInput[i] != 8 - i)
			{
				cout << "mixed" << ENDL;
				return 0;
			}
		}
		cout << "descending" << ENDL;
		return 0;
	}
	else
	{
		cout << "mixed" << ENDL;
	}

	return 0;
}

#pragma endregion

#pragma region 2475 : 검증수

int Solution_2475()
{
	int iInput = 0;
	int N = 0;

	for (size_t i = 0; i < 5; i++)
	{
		cin >> iInput;
		N += POW(iInput);
	}
	cout << N % 10 << ENDL;

	return 0;
}

#pragma endregion

#pragma region 2577 : 숫자의 개수

int Solution_2577()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int A, B, C;
	int arrCount[10] = { 0 };
	int iTemp = 0;

	cin >> A >> B >> C;

	iTemp = A * B * C;

	while (iTemp > 0)
	{
		++arrCount[iTemp % 10];
		iTemp /= 10;
	}

	for (const int& iCount : arrCount)
	{
		cout << iCount << ENDL;
	}

	return 0;
}

#pragma endregion

#pragma region 2741 : N 찍기

int Solution_2741()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	size_t N = 0;
	cin >> N;

	for (size_t i = 1; i <= N; i++)
	{
		cout << i << ENDL;
	}

	return 0;
}

#pragma endregion

#pragma region 2742 : 기찍 N

int Solution_2742()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	size_t N = 0;
	cin >> N;

	for (size_t i = N; i > 0; i--)
	{
		cout << i << ENDL;
	}

	return 0;
}

#pragma endregion


int main()
{
	_APPEND_FUNC(Solution_, _PROBLEM_NUMBER);
	system("pause");
	return 0;
}