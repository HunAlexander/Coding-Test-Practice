#include "Default.h"

#define _PROBLEM_NUMBER 4344

#ifndef _PROBLEM_NUMBER
#include <iostream>
using namespace std;
#endif // !_PROBLEM_NUMBER

#pragma region Preivous

// 10807 : 개수 세기
int Solution_10807()
{
	int N, v, count = 0;

	cin >> N;

	int* IntArray = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> IntArray[i];
	}

	cin >> v;

	for (int i = 0; i < N; i++)
	{
		if (v == IntArray[i])
			++count;
	}

	cout << count << '\n';

	delete[] IntArray;

	//int N, v, count = 0;
	//int IntArray[100] = { 0 };

	//cin >> N;
	//for (int i = 0; i < N; i++)
	//{
	//	cin >> IntArray[i];
	//}
	//cin >> v;
	//for (int i = 0; i < N; i++)
	//{
	//	if (v == IntArray[i])
	//		++count;
	//}
	//cout << count << '\n';

	return 0;
}

// 10871 : X보다 작은 수
int Solution_10871()
{
	int N, X;
	cin >> N >> X;
	int* A = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		if (X > A[i])
			cout << A[i] << " ";
	}
	cout << '\n';
	delete[] A;

	return 0;
}

// 10818 : 최소, 최대
int Solution_10818()
{
	int N = 0, min = 0, max = 0;

	cin >> N;

	int* Values = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> Values[i];

		if (0 == i)
		{
			min = Values[i];
			max = Values[i];
		}
		else
		{
			min = MMin(Values[i], min);
			max = MMax(Values[i], max);
		}
	}

	cout << min << " " << max << '\n';

	delete[] Values;

	return 0;
}

// 2562 : 최댓값
int Solution_2562()
{
	int arr[9] = { 0 };
	int max = 0, index = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		if (0 == i)
		{
			max = arr[i];
		}
		else if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}
	cout << max << '\n';
	cout << index + 1 << '\n';

	return 0;
}

// 5597 : 과제 안 내신 분..?
int Solution_5597()
{
#pragma region Solution 1
	//int Numbers[28] = { 0 };
	//int NoNumbers[2] = { 0 };
	//int NoNumbersIndex = 0;
	//for (int i = 0; i < 28; i++)
	//{
	//	cin >> Numbers[i];
	//}

	//for (int i = 1; i <= 30; i++)
	//{
	//	bool IsEqual = false;
	//	for (int Number : Numbers)
	//	{
	//		if (i == Number)
	//		{
	//			IsEqual = true;
	//			break;
	//		}
	//	}
	//	if (false == IsEqual)
	//	{
	//		NoNumbers[NoNumbersIndex++] = i;
	//	}
	//}
	//
	//for (int& NoNumber : NoNumbers)
	//{
	//	cout << NoNumber << '\n';
	//}

	//return 0;
#pragma endregion // Solution 1

	int arr[30] = { 0 };
	int Number = 0;
	for (int i = 0; i < 28; i++)
	{
		cin >> Number;
		arr[Number - 1] = Number;
	}
	for (int i = 0; i < 30; i++)
	{
		if (0 == arr[i])
		{
			cout << i + 1 << '\n';
		}
	}
	return 0;
}

// 3052 : 나머지
int Solution_3052()
{
	int Numbers[10] = { 0 };
	int Count = 0;
	for (int& Number : Numbers)
	{
		cin >> Number;
		Number %= 42;
	}

	for (int i = 0; i <= 42; i++)
	{
		for (int& Number : Numbers)
		{
			if (Number == i)
			{
				++Count;
				break;
			}
		}
	}

	cout << Count << '\n';

	return 0;
}

// 1546 : 평균
int Solution_1546()
{
	float M = 0.f, fTotal = 0.f;
	int N;

	cin >> N;

	float* pData = new float[N];

	for (int i = 0; i < N; i++)
	{
		cin >> pData[i];
		fTotal += pData[i];
		if (pData[i] > M)
		{
			M = pData[i];
		}
	}

	cout << (fTotal / M * 100.f) / N << '\n';

	delete[] pData;

	return 0;
}

// 8958 : OX퀴즈
int Solution_8958()
{
	int T = 0, TotalScore = 0, AddScore = 0;

	string str = "";

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> str;
		int Length = static_cast<int>(str.length());
		for (int i = 0; i < Length; i++)
		{
			if ('\0' == str[i])
			{
				break;
			}
			else if ('O' == str[i])
			{
				TotalScore += ++AddScore;
			}
			else
			{
				AddScore = 0;
			}
		}
		cout << TotalScore << '\n';
		TotalScore = 0;
		AddScore = 0;
	}

	return 0;
}

// 4344 : 평균은 넘겠지
int Solution_4344()
{
	int C; // 테스트 케이스 개수
	int N; // 케이스마다 학생 수
	cin >> C;
	float* Ratios = new float[C]; // 케이스 평균 이상 비율

	for (int i = 0; i < C; i++)
	{
		cin >> N;
		float* Scores = new float[N]; // 각 학생의 점수
		float TotalScore = 0.f; // 한 케이스에서 총점
		float AvgScore = 0.f; // 한 케이스에서 평균
		int M = 0; // 한 케이스에서 평균 이상 학생 수

		// 총점, 각 학생의 점수
		for (int j = 0; j < N; j++)
		{
			cin >> Scores[j];
			TotalScore += Scores[j];
		}

		// 평균
		AvgScore = TotalScore / N;

		// 평균 이상 학생 수
		for (int j = 0; j < N; j++)
		{
			if (AvgScore < Scores[j])
				++M;
		}

		Ratios[i] = M / static_cast<float>(N);

		delete[] Scores;
	}

	cout << fixed;
	cout.precision(3);
	for (int i = 0; i < C; i++)
	{
		cout << Ratios[i] * 100.f << "%\n";
	}
	delete[] Ratios;

	return 0;
}

#pragma endregion ! Preivous

int main()
{
	MAppend_Function(Solution_, _PROBLEM_NUMBER);
	system("pause");
	return 0;
}