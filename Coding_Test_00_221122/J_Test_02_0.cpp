#include "Default.h"

// 문제 2

int Sum_Vector(vector<int> v)
{
	int iSum = 0;
	for (int iter : v)
	{
		iSum += iter;
	}
	return iSum;
}


int solution(int N, vector<vector<int>> simulation_data) {
	vector<int> windows;
	windows.resize(N, 0);

	int iTime = 0;

	for (auto data : simulation_data)
	{
		bool bFull = true;
		for (auto& window : windows)
		{
			if (0 == window)
			{
				window = Sum_Vector(data);
				bFull = false;
				break;
			}
		}

		if (bFull)
		{
			sort(windows.begin(), windows.end());

			int iWait = windows.at(0) - data[0];

			if (0 > iWait)
			{
				windows[0] = Sum_Vector(data);
			}
			else
			{
				iTime += iWait;
				windows[0] = Sum_Vector(data) + iWait;
			}
		}
	}

	return iTime;
}

int main()
{
	vector<vector<int>> v1 { { 0, 3 }, { 2, 5 }, { 4, 2 }, { 5, 3 } };
	vector<vector<int>> v2 { { 2, 3 }, { 5, 4 }, { 6, 3 }, { 7, 4 } };
	cout << solution(2, v1) << endl;
	cout << solution(1, v2) << endl;

	system("pause");

	return 0;
}

// 문제 3

//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int Sum(int n)
//{
//	return (n * (n + 1)) / 2;
//}
//
//long long solution(int n, int r, int c) {
//	long long answer = 0;
//
//	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
//
//	int iSum = r + c; // 행열 합
//
//	if (iSum <= n + 1)
//	{
//		int iPre = iSum - 2; // 이전 라인의 마지막 값
//		iPre = (iPre * (iPre + 1)) / 2;
//
//		if (1 == iSum % 2)
//		{
//			answer = iPre + r;
//		}
//		else
//		{
//			answer = iPre + c;
//		}
//	}
//	else
//	{
//		int iPre = (n * (n + 1)) / 2;
//		int iCount = n - (iSum % n) + 1;
//		int iAdd = Sum(n - 1) - Sum(iCount);
//
//		iPre += iAdd;
//
//		if (1 == iSum % 2)
//		{
//			answer = iPre + r - (iSum - n) + 1;
//			cout << "r : " << r << endl;
//		}
//		else
//		{
//			answer = iPre + c - (iSum - n) + 1;
//		}
//	}
//
//	return answer;
//}