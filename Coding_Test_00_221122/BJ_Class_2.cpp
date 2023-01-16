#include "Default.h"

#define _PROBLEM_NUMBER 1920
/* == template ==

#include <iostream>
using namespace std;

#include <cmath>
#include <climits>
#include <list>
#include <vector>
#include <algorithm>

int Solution_0000()
{
	return 0;
}
*/
#define ENDL '\n'

#define POW(a) ((a) * (a))

#pragma region 1018 : 체스판 다시 칠하기

int Solution_1018_00()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M; // 행렬
	cin >> N >> M;
	char szBoard[51][51] = {};

	for (int i = 0; i < N; i++)
	{
		cin >> szBoard[i];
	}

	int iResult = INT_MAX;

	for (int iRow = 0; iRow < N - 7; iRow++)
	{
		for (int iCol = 0; iCol < M - 7; iCol++)
		{
			/* 좌측상단부터 순차적으로 색 검사 */
			int iCount = 0;
			char chRowCheck = szBoard[iRow][iCol];
			char chColCheck = szBoard[iRow][iCol];

			for (int i = iRow; i < iRow + 8; i++)
			{
				for (int j = iCol + 1; j < iCol + 8; j++)
				{
					if (chColCheck == szBoard[i][j])
						++iCount;

					chColCheck = ('B' == chColCheck) ? 'W' : 'B';
				}

				if (iRow == i)
					continue;

				if (chRowCheck == szBoard[i][iCol])
					++iCount;

				chRowCheck = ('B' == chRowCheck) ? 'W' : 'B';
			}

			iResult = min(iResult, iCount);

			/* 오른쪽부터 순차적으로 색 검사 */
			iCount = 0;

			for (int i = iRow + 7; i >= iRow; --i)
			{
				for (int j = iCol + 6; j >= iCol; --j)
				{
					if (chColCheck == szBoard[i][j])
						++iCount;

					chColCheck = ('B' == chColCheck) ? 'W' : 'B';
				}

				if (iRow == i)
					continue;

				if (chRowCheck == szBoard[i][iCol])
					++iCount;

				chRowCheck = ('B' == chRowCheck) ? 'W' : 'B';
			}

			iResult = min(iResult, iCount);
		}
	}

	cout << iResult << ENDL;

	return 0;
}

int Solution_1018_01()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M; // 행렬
	cin >> N >> M;
	char szBoard[51][51] = {};

	for (int i = 0; i < N; i++)
	{
		cin >> szBoard[i];
	}

	int iResult = INT_MAX;

	for (int iRow = 0; iRow < N - 7; iRow++)
	{
		for (int iCol = 0; iCol < M - 7; iCol++)
		{
			/* 상단부터 순차적으로 색 검사 */
			int iCount[2] = { 0 };
			char chRowCheck[] = { szBoard[iRow][iCol], szBoard[iRow][iCol + 7] };
			char chColCheck[] = { szBoard[iRow][iCol], szBoard[iRow][iCol + 7] };

			for (int i = iRow; i < iRow + 8; i++)
			{
				for (int j = iCol + 1; j < iCol + 8; j++)
				{
					if (chColCheck[0] == szBoard[i][j])
						++iCount[0];

					chColCheck[0] = ('B' == chColCheck[0]) ? 'W' : 'B';
				}

				for (int j = iCol + 6; j >= iCol; --j)
				{
					if (chColCheck[1] == szBoard[i][j])
						++iCount[1];

					chColCheck[1] = ('B' == chColCheck[1]) ? 'W' : 'B';
				}

				if (iRow == i)
					continue;

				if (chRowCheck[0] == szBoard[i][iCol])
					++iCount[0];

				if (chRowCheck[1] == szBoard[i][iCol + 7])
					++iCount[1];

				chRowCheck[0] = ('B' == chRowCheck[0]) ? 'W' : 'B';
				chRowCheck[1] = ('B' == chRowCheck[1]) ? 'W' : 'B';
			}

			iResult = min(iResult, iCount[0]);
			iResult = min(iResult, iCount[1]);

			if (iResult == 0)
				break;

			/* 하단부터 순차적으로 색 검사 */
			iCount[0] = 0;
			iCount[1] = 0;

			chRowCheck[0] = szBoard[iRow + 7][iCol];
			chRowCheck[1] = szBoard[iRow + 7][iCol + 7];

			chColCheck[0] = szBoard[iRow + 7][iCol];
			chColCheck[1] = szBoard[iRow + 7][iCol + 7];

			for (int i = iRow + 7; i >= iRow; --i)
			{
				for (int j = iCol + 1; j < iCol + 8; j++)
				{
					if (chColCheck[0] == szBoard[i][j])
						++iCount[0];

					chColCheck[0] = ('B' == chColCheck[0]) ? 'W' : 'B';
				}

				for (int j = iCol + 6; j >= iCol; --j)
				{
					if (chColCheck[1] == szBoard[i][j])
						++iCount[1];

					chColCheck[1] = ('B' == chColCheck[1]) ? 'W' : 'B';
				}

				if (iRow == i)
					continue;

				if (chRowCheck[0] == szBoard[i][iCol])
					++iCount[0];

				if (chRowCheck[1] == szBoard[i][iCol + 7])
					++iCount[1];

				chRowCheck[0] = ('B' == chRowCheck[0]) ? 'W' : 'B';
				chRowCheck[1] = ('B' == chRowCheck[1]) ? 'W' : 'B';
			}

			iResult = min(iResult, iCount[0]);
			iResult = min(iResult, iCount[1]);

			if (iResult == 0)
				break;
		}
	}

	cout << iResult << ENDL;

	return 0;
}

int Solution_1018()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	char szBoard[51][51] = {};
	int iResult = INT_MAX;

	/* 행렬 개수 입력 */
	cin >> N >> M;

	/* 보드입력 */
	for (int i = 0; i < N; i++)
	{
		cin >> szBoard[i];
	}

	for (int iRow_Begin = 0; iRow_Begin < N - 7; iRow_Begin++)
	{
		for (int iCol_Begin = 0; iCol_Begin < M - 7; iCol_Begin++)
		{
			int iCount[2] = { 0 };

			for (int i = iRow_Begin; i < iRow_Begin + 8; i++)
			{
				for (int j = iCol_Begin; j < iCol_Begin + 8; j++)
				{
					if (0 == (i + j) % 2)
					{
						if ('W' == szBoard[i][j])
						{
							++iCount[0];
						}
						else
						{
							++iCount[1];
						}
					}
					else
					{
						if ('B' == szBoard[i][j])
						{
							++iCount[0];
						}
						else
						{
							++iCount[1];
						}
					}
				}
			}
			iResult = min(iResult, iCount[0]);
			iResult = min(iResult, iCount[1]);
		}
	}

	cout << iResult << ENDL;

	return 0;
}

#pragma endregion

#pragma region 1085 : 직사각형에서 탈출

int Solution_1085()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(min(abs(x - w), x), min(abs(y - h), y)) << ENDL;
	return 0;
}

#pragma endregion

#pragma region 1181 : 단어 정렬

bool Compare_1181(const string& _lhs, const string& _rhs)
{
	if (_rhs.length() == _lhs.length())
	{
		return _lhs < _rhs;
	}
	else
	{
		return (_lhs.length() < _rhs.length());
	}
}

int Solution_1181()
{
	int N;
	cin >> N;
	string* strInput = new string[N];
	for (int i = 0; i < N; i++)
	{
		cin >> strInput[i];
	}

	sort(strInput, strInput + N, Compare_1181);

	string strCheck = "";
	for (int i = 0; i < N; i++)
	{
		if (strCheck == strInput[i])
			continue;

		cout << strInput[i] << ENDL;
		strCheck = strInput[i];
	}


	return 0;
}

int Solution_1181_00()
{
	int N;
	cin >> N;
	string* strInput = new string[N];

	for (int i = 0; i < N; i++)
	{
		cin >> strInput[i];
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (strInput[j].length() > strInput[j + 1].length())
			{
				swap(strInput[j], strInput[j + 1]);
			}
		}
	}

	int iBegin = 0;
	int iEnd = 0;
	for (int i = 0; i < N - 1; i++)
	{
		if (strInput[i].length() < strInput[i + 1].length())
		{
			iEnd = i + 1;

			for (int j = iBegin; j < iEnd; j++)
			{
				for (int k = iBegin; k < iEnd - 1 - (j - iBegin); k++)
				{
					if (0 < strInput[k].compare(strInput[k + 1]))
					{
						swap(strInput[k], strInput[k + 1]);
					}
				}
			}

			iBegin = iEnd;
		}
	}

	string strCheck = "";
	for (int i = 0; i < N; i++)
	{
		if (strInput[i] == strCheck)
			continue;

		cout << strInput[i] << ENDL;
		strCheck = strInput[i];
	}

	delete[] strInput;

	return 0;
}

#pragma endregion

#pragma region 2231 : 분해합

int Solution_2231()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int M = i;
		int iTemp = i;
		while (0 < M)
		{
			iTemp += M % 10;
			M /= 10;
		}

		if (iTemp == N)
		{
			cout << i << ENDL;
			return 0;
		}
	}

	cout << 0 << ENDL;

	return 0;
}

#pragma endregion

#pragma region 1259 : 팰린드롬수

int Solution_1259()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int iInput = 0;

	while (true)
	{
		cin >> iInput;
		if (0 == iInput)
			break;

		int iCount = 0;
		int	arrNumber[5] = { 0 };

		for (int& iNumber : arrNumber)
		{
			iNumber = iInput % 10;
			if (!(iInput /=10))
				break;
			++iCount;
		}

		int iLength = (iCount >> 1) + 1;
		bool bPalindrome = true;

		if (0 < iCount)
		{
			for (int i = 0; i < iLength; i++)
			{
				if (arrNumber[i] != arrNumber[iCount - i])
				{
					bPalindrome = false;
					break;
				}
			}
		}

		bPalindrome ? cout << "yes" << ENDL : cout << "no" << ENDL;
	}

	return 0;
}

#pragma endregion

#pragma region 1436 : 영화감독 숌

int Solution_1436()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N = 0;
	cin >> N;

	int iCurrent = 666;
	int iCount = 0;


	while (true)
	{
		int iTemp = iCurrent;
		while (iTemp != 0)
		{
			if (666 == (iTemp % 1000))
			{
				++iCount;
				break;
			}
			iTemp /= 10;
		}

		if (N == iCount)
			break;

		++iCurrent;
	}

	cout << iCurrent << ENDL;

	return 0;
}

#pragma endregion

#pragma region 1654 : 랜선 자르기

int Solution_1654()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	typedef unsigned long long _ullong;

	_ullong K, N;
	list<_ullong> LanList;
	_ullong left = 0, right = 0, mid;
	cin >> K >> N;

	for (_ullong i = 0; i < K; i++)
	{
		_ullong Arg = 0;
		cin >> Arg;
		LanList.push_back(Arg);
		right = max(Arg, right);
	}

	while (left <= right)
	{
		mid = (left + right) >> 1;

		_ullong Count = 0;
		for (const _ullong& Line : LanList)
		{
			Count += Line / mid;
		}

		if (Count < N)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << right << ENDL;

	return 0;
}

int Solution_1654_00()
{
	typedef unsigned long long _ullong;

	int K, N;
	list<_ullong> LanList;
	_ullong Length = 0;
	cin >> K >> N;
	for (_ullong i = 0; i < K; i++)
	{
		_ullong Arg = 0;
		cin >> Arg;
		LanList.push_back(Arg);
		Length = max(Arg, Length);

	}

	while (true)
	{
		_ullong Count = 0;
		for (const _ullong& Line : LanList)
		{
			Count += Line / Length;
		}

		if (Count >= N)
			break;

		--Length;
	}

	cout << Length << ENDL;

	return 0;
}

#pragma endregion

#pragma region 1874 : 스택 수열

int Solution_1874()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n = 0;
	cin >> n;
	list<int> sequenceList;
	list<int> intList;
	list<int> stackList;
	list<char> operatorList;

	for (int i = 1; i <= n; i++)
	{
		int iData = 0;
		cin >> iData;
		sequenceList.push_back(iData);
		intList.push_back(i);
	}

	while (true)
	{
		if (!stackList.empty() && sequenceList.front() == stackList.back())
		{
			sequenceList.pop_front();
			stackList.pop_back();
			operatorList.push_back('-');

			if (sequenceList.empty())
				break;
		}
		else if (intList.empty())
		{
			cout << "NO" << ENDL;
			return 0;
		}
		else
		{
			stackList.push_back(intList.front());
			intList.pop_front();
			operatorList.push_back('+');
		}
	}

	for (const char& chOperator : operatorList)
	{
		cout << chOperator << ENDL;
	}

	return 0;
}

#pragma endregion

#pragma region 1920 : 수 찾기

int Solution_1920()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N;
	vector<int> A;
	A.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int A_element = 0;
		cin >> A_element;
		A.push_back(A_element);
	}
	sort(A.begin(), A.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int X = 0;
		int left = 0, right = static_cast<int>(A.size()) - 1;
		int mid = 0;
		bool bExist = false;
		cin >> X;
		while (left <= right)
		{
			mid = (left + right) >> 1;
			if (X == A[mid])
			{
				bExist = true;
				break;
			}
			if (X < A[mid])
			{
				right = mid - 1;
			}
			if (X > A[mid])
			{
				left = mid + 1;
			}
		}

		bExist ? cout << 1 << ENDL : cout << 0 << ENDL;
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