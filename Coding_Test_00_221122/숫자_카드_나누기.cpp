#include "Default.h"

/*

22-11-23 16:30
https://school.programmers.co.kr/learn/challenges?order=recent&levels=2&languages=cpp
숫자 카드 나누기

*/

int GCD(int _iA, int _iB)
{
	int iA = max(_iA, _iB);
	int iB = min(_iA, _iB);

	if (0 == iB)
		return iA;

	return GCD(iB, iA % iB);
}

int GCD_Vector(vector<int> array)
{
	int iGCD = array.front();

	for (int i = 1; i < array.size(); ++i)
	{
		iGCD = GCD(iGCD, array[i]);
	}

	return iGCD;
}

//int GCD_Vector_Param(vector<int> array, int _iParam)
//{
//	int iGCD = _iParam;
//
//	for (int i = 0; i < array.size(); ++i)
//	{
//		iGCD = GCD(iGCD, array[i]);
//	}
//
//	return iGCD;
//}

bool Find_Can_Div(vector<int> array, int iParam)
{
	for (int iter : array)
	{
		if (0 == (iter % iParam))
		{
			return true;
		}
	}

	return false;
}

int solution(vector<int> arrayA, vector<int> arrayB) 
{
	int answer = 0;

	int iGCD_A = GCD_Vector(arrayA);
	int iGCD_B = GCD_Vector(arrayB);

	if (iGCD_A > iGCD_B)
	{
		if (false == Find_Can_Div(arrayB, iGCD_A))
		{
			answer = iGCD_A;
		}
	}
	else if (iGCD_A < iGCD_B)
	{
		if (false == Find_Can_Div(arrayA, iGCD_B))
		{
			answer = iGCD_B;
		}
	}

	return answer;
}

int main()
{
	vector<int> arrayA { 10, 17 }, arrayB { 5, 20 };

	cout << solution(arrayA, arrayB) << endl;

	system("pause");

	return 0;
}