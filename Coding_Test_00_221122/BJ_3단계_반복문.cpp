#include "Default.h"

#define _PROBLEM_NUMBER 1110

#ifndef _PROBLEM_NUMBER
#include <iostream>
using namespace std;
#endif // !_PROBLEM_NUMBER

#pragma region TEST : 
#if _PROBLEM_NUMBER == 1
int Solution_3()
{
	return 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//Solution_3();

	cout << "Hello" << _STR(a) << "World" << _APPEND(Solution_, 3)() << '\n';
	system("pause");

	return 0;
}
#endif // TEST
#pragma endregion

#pragma region 15552 : ºü¸¥ A+B
#if _PROBLEM_NUMBER == 15552
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, A, B;

	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> A >> B;
		cout << A + B << '\n';
	}

	return 0;
}
#endif // 15552
#pragma endregion

#pragma region 11021 : A+B - 7
#if _PROBLEM_NUMBER == 11021
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, A, B;

	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		cin >> A >> B;
		cout << "Case #" << i << ":" << A + B << '\n';
	}

	return 0;
}
#endif // 11021
#pragma endregion

#pragma region 11022 : A+B - 8
#if _PROBLEM_NUMBER == 11022
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, A, B;

	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		cin >> A >> B;
		cout << "Case #" << i << ": " << A << " + " << B << " = " << A + B << '\n';
	}

	return 0;
}
#endif // 11022
#pragma endregion

#pragma region 2438 : º° Âï±â - 1
#if _PROBLEM_NUMBER == 2438
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}
#endif // 2438
#pragma endregion

#pragma region 2439 : º° Âï±â - 2
#if _PROBLEM_NUMBER == 2439
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = N; j >= 1; --j)
		{
			if (j <= i)
				cout << "*";
			else
				cout << " ";
		}
		cout << '\n';
	}

	system("pause");

	return 0;
}
#endif // 2439
#pragma endregion

#pragma region 10952 : A+B - 5
#if _PROBLEM_NUMBER == 10952
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int A, B;

	while (true)
	{
		cin >> A >> B;

		if (0 == A && 0 == B)
			break;
		else
			cout << A + B << '\n';
	}

	return 0;
}
#endif // 10952
#pragma endregion

#pragma region 10951 : A+B - 4
#if _PROBLEM_NUMBER == 10951
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int A, B;

	while (true)
	{
		cin >> A >> B;

		if (cin.eof())
			break;

		cout << A + B << '\n';
	}

	return 0;
}
#endif // 10951
#pragma endregion

#pragma region 1110 : A+B - 4
/*
https://www.acmicpc.net/problem/1110
*/
#if _PROBLEM_NUMBER == 1110
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, l, r, temp;
	int cycle = 0;

	cin >> N;
	temp = N;

	while (true)
	{
		if (10 > temp)
		{
			temp *= 11;
		}
		else
		{
			l = temp / 10;
			r = temp % 10;
			temp = l + r;
			temp = (r * 10) + (temp % 10);
		}

		++cycle;

		cout << temp << '\n';

		if (N == temp)
			break;
	}
	cout << cycle << '\n';
	system("pause");

	return 0;
}
#endif // 1110
#pragma endregion
