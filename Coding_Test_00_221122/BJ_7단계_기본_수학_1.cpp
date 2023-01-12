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

#pragma region 1712 : ���ͺб���

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

#pragma region 2292 : ����

int Solution_2292()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// ��ȭ��
	// 3 * (n - 1) * n + 1 = 'a(n)'

	int N;
	int n = 0, a = 0;
	cin >> N;

	while (a < N)
	{
		//a = 3 * (n - 1) * n + 1; // ����Ƚ���� ���̱� ���� ���� �ڵ�� ����
		a = 3 * n * (n + 1) + 1;
		++n;
	}

	cout << n << ENDL;

	return 0;
}

#pragma endregion

#pragma region 1193 : �м�ã��

int Solution_1193()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int X;
	int n = 0;
	int iPreLine = 0, iCurrentLine = 0; // �ش� ������ ������ �ε��� + 1
	cin >> X;

	while (true)
	{
		iCurrentLine = (n + 1) * n / 2;
		if (X <= iCurrentLine)
			break;

		iPreLine = iCurrentLine;
		++n;
	}

	// n�� Ȧ��
	if (n % 2)
	{
		cout
			<< iCurrentLine - X + 1
			<< '/'
			<< X - iPreLine;
	}
	// n�� ¦��
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

#pragma region 2869 : �����̴� �ö󰡰� �ʹ�

int Solution_2869()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int V; // ����
	int A; // �� �̵��Ÿ�
	int B; // �� �̲������� �Ÿ�

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