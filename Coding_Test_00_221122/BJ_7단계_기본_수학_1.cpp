#include "Default.h"

#define _PROBLEM_NUMBER 2869

#ifndef _PROBLEM_NUMBER
#include <iostream>
using namespace std;

#include <cmath>
#endif // !_PROBLEM_NUMBER
#define ENDL '\n'

int Solution_0000()
{
	return 0;
}

#pragma region 1712 : 손익분기점

int Solution_1712()
{
	int A, B, C, N;

	cin >> A >> B >> C;

	if (B >= C)
	{
		cout << -1 << ENDL;
	}
	else
	{
		N = A / (C - B);
		cout << N + 1 << ENDL;
	}

	return 0;
}

#pragma endregion

#pragma region 2292 : 벌집

int Solution_2292()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// 점화식
	// 3 * (n - 1) * n + 1 = 'a(n)'

	int N;
	int n = 0, a = 0;
	cin >> N;

	while (a < N)
	{
		//a = 3 * (n - 1) * n + 1; // 수행횟수를 줄이기 위해 다음 코드로 변경
		a = 3 * n * (n + 1) + 1;
		++n;
	}

	cout << n << ENDL;

	return 0;
}

#pragma endregion

#pragma region 1193 : 분수찾기

int Solution_1193()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int X;
	int n = 0;
	int iPreLine = 0, iCurrentLine = 0; // 해당 라인의 마지막 인덱스 + 1
	cin >> X;

	while (true)
	{
		iCurrentLine = (n + 1) * n / 2;
		if (X <= iCurrentLine)
			break;

		iPreLine = iCurrentLine;
		++n;
	}

	// n이 홀수
	if (n % 2)
	{
		cout
			<< iCurrentLine - X + 1
			<< '/'
			<< X - iPreLine;
	}
	// n이 짝수
	else
	{
		cout
			<< X - iPreLine
			<< '/'
			<< iCurrentLine - X + 1;
	}

	return 0;
}

#pragma endregion

#pragma region 2869 : 달팽이는 올라가고 싶다

int Solution_2869()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int V; // 높이
	int A; // 낮 이동거리
	int B; // 밤 미끄러지는 거리

	cin >> A >> B >> V;

	cout << static_cast<int>(ceil((V - B) / double(A - B))) << ENDL;

	return 0;
}

#pragma endregion

int main()
{
	_APPEND_FUNC(Solution_, _PROBLEM_NUMBER);
	system("pause");
	return 0;
}