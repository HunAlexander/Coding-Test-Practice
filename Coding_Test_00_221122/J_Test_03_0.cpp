#include "Default.h"


#include <string>
#include <vector>
#include <iostream>
using namespace std;

int Sum(int n)
{
	return (n * (n + 1)) / 2;
}

long long solution(int n, int r, int c) {
	long long answer = 0;

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�. 

	int iSum = r + c; // �࿭ ��

	if (iSum == 2 * n)
	{
		return n * n;
	}
	else if (iSum == 2)
	{
		return 1;
	}

	if (iSum <= n + 1)
	{
		int iPre = iSum - 2; // ���� ������ ������ ��
		iPre = (iPre * (iPre + 1)) / 2;

		if (1 == iSum % 2)
		{
			answer = iPre + r;
		}
		else
		{
			answer = iPre + c;
		}
	}
	else
	{
		int iPre = (n * (n + 1)) / 2;
		int iCount = n - (iSum % n) + 1;
		int iAdd = Sum(n - 1) - Sum(iCount);

		iPre += iAdd;

		if (1 == iSum % 2)
		{
			answer = iPre + r - (iSum - n) + 1;
		}
		else
		{
			answer = iPre + c - (iSum - n) + 1;
		}
	}

	return answer;
}