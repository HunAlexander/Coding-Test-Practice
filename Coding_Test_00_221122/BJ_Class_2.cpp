#include "Default.h"
#define _PROBLEM_NUMBER 7568

/* == template ==

#include <iostream>
using namespace std;

#include <cmath>
#include <climits>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

int Solution_0000()
{
	return 0;
}
*/
#define MEndl '\n'
#define MPow(a) ((a) * (a))

#pragma region Previous Solutions

#pragma region 1018 : ü���� �ٽ� ĥ�ϱ�

int Solution_1018_00()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M; // ���
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
			/* ������ܺ��� ���������� �� �˻� */
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

			/* �����ʺ��� ���������� �� �˻� */
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

	cout << iResult << MEndl;

	return 0;
}

int Solution_1018_01()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M; // ���
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
			/* ��ܺ��� ���������� �� �˻� */
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

			/* �ϴܺ��� ���������� �� �˻� */
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

	cout << iResult << MEndl;

	return 0;
}

int Solution_1018()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	char szBoard[51][51] = {};
	int iResult = INT_MAX;

	/* ��� ���� �Է� */
	cin >> N >> M;

	/* �����Է� */
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

	cout << iResult << MEndl;

	return 0;
}

#pragma endregion

#pragma region 1085 : ���簢������ Ż��

int Solution_1085()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(min(abs(x - w), x), min(abs(y - h), y)) << MEndl;
	return 0;
}

#pragma endregion

#pragma region 1181 : �ܾ� ����

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

		cout << strInput[i] << MEndl;
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

		cout << strInput[i] << MEndl;
		strCheck = strInput[i];
	}

	delete[] strInput;

	return 0;
}

#pragma endregion

#pragma region 2231 : ������

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
			cout << i << MEndl;
			return 0;
		}
	}

	cout << 0 << MEndl;

	return 0;
}

#pragma endregion

#pragma region 1259 : �Ӹ���Ҽ�

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
			if (!(iInput /= 10))
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

		bPalindrome ? cout << "yes" << MEndl : cout << "no" << MEndl;
	}

	return 0;
}

#pragma endregion

#pragma region 1436 : ��ȭ���� ��

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

	cout << iCurrent << MEndl;

	return 0;
}

#pragma endregion

#pragma region 1654 : ���� �ڸ���

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

	cout << right << MEndl;

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

	cout << Length << MEndl;

	return 0;
}

#pragma endregion

#pragma region 1874 : ���� ����

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
			cout << "NO" << MEndl;
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
		cout << chOperator << MEndl;
	}

	return 0;
}

#pragma endregion

#pragma region 1920 : �� ã��

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

		bExist ? cout << 1 << MEndl : cout << 0 << MEndl;
	}

	return 0;
}

#pragma endregion

#pragma region 1929 : �Ҽ� ���ϱ�
/*
�����佺�׳׽��� ü : �Ҽ��� ���ϴ� �˰���
https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4
*/

int Solution_1929()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	bool* pPrimeNumbers = new bool[N + 1];
	for (int i = 2; i <= N; i++)
	{
		pPrimeNumbers[i] = true;
	}

	for (int i = 2; i * i <= N; i++)
	{
		if (pPrimeNumbers[i])
		{
			for (int j = i * i; j <= N; j += i)
			{
				pPrimeNumbers[j] = false;
			}
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (pPrimeNumbers[i])
			cout << i << MEndl;
	}

	delete[] pPrimeNumbers;

	return 0;
}

#pragma endregion

#pragma region 1966 : ������ ť
/*
���߿� queue�� �� �� Ȱ���غ���?
*/
int Solution_1966()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; // �׽�Ʈ ���̽� Ƚ��
	int N; // ������ ����
	int M; // (�� ��°�� �μ�Ǿ����� �ñ��� ����) ���� ť������ ��ġ 

	typedef struct tagNode {
		int iValue = 0;
		bool bCheck = false;
	} TNode;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		TNode* pDoc = new TNode[N];
		for (int i = 0; i < N; i++)
		{
			cin >> pDoc[i].iValue;

			if (i == M)
				pDoc[i].bCheck = true;
		}

		int iCmpIndex = 0;
		while (true)
		{
			bool bPop = true;
			for (int i = iCmpIndex + 1; i < N; i++)
			{
				// ù ��° �������� �߿䵵�� ū ������ ������ ������
				if (pDoc[iCmpIndex].iValue < pDoc[i].iValue)
				{
					bPop = false;
					TNode tFirstDoc = pDoc[iCmpIndex];
					for (int j = iCmpIndex; j < N - 1; j++)
					{
						pDoc[j] = pDoc[j + 1];
					}
					pDoc[N - 1] = tFirstDoc;
					break;
				}
			}

			if (true == bPop)
			{
				if (true == pDoc[iCmpIndex].bCheck)
				{
					cout << iCmpIndex + 1 << MEndl;
					break;
				}
				else
				{
					++iCmpIndex;
				}
			}
		}
		delete[] pDoc;
	}

	return 0;
}

#pragma endregion

#pragma region 1978 : �Ҽ� ã��

int Solution_1978()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; // �˻� ���� �ڿ��� ����
	bool bNotPrimeNumber[1001] = { 0 };
	int iPrimeNumberCount = 0;

	// �Ҽ����� �Ǻ��� ���� ����
	bNotPrimeNumber[0] = true;
	bNotPrimeNumber[1] = true;
	for (int i = 2; i * i <= 1000; i++)
	{
		if (false == bNotPrimeNumber[i])
		{
			for (int j = i * i; j <= 1000; j += i)
			{
				bNotPrimeNumber[j] = true;
			}
		}
	}

	cin >> N;
	while (N--)
	{
		int iIndex = 0;
		cin >> iIndex;
		if (false == bNotPrimeNumber[iIndex])
			++iPrimeNumberCount;
	}

	cout << iPrimeNumberCount << MEndl;

	return 0;
}

#pragma endregion

#pragma region 2108 : �����

int Solution_2108()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N = 0;
	int iAvg = 0;
	int iMin = INT_MAX, iMax = INT_MIN;
	int iCount = 0;
	int arrCounts[8001] = { 0 };
	list<int> ModeList;
	vector<int> NumberVector;

	cin >> N;
	NumberVector.reserve(N);

	for (int i = 0; i < N; i++)
	{
		int iInput = 0;
		cin >> iInput;
		iAvg += iInput;
		iMin = min(iMin, iInput);
		iMax = max(iMax, iInput);
		iCount = max(iCount, ++arrCounts[4000 + iInput]);
		NumberVector.push_back(iInput);
	}

	for (int i = 0; i < 8001; i++)
	{
		if (iCount == arrCounts[i])
		{
			ModeList.push_back(i - 4000);
		}
	}

	ModeList.sort();
	sort(NumberVector.begin(), NumberVector.end());
	iAvg = static_cast<int>(round((double)iAvg / N));

	cout << iAvg << MEndl;
	cout << NumberVector[N >> 1] << MEndl;
	(1 < ModeList.size()) ? cout << *(++ModeList.begin()) << MEndl : cout << ModeList.front() << MEndl;
	cout << iMax - iMin << MEndl;

	return 0;
}

#pragma endregion

#pragma region 2164 : ī��2

int Solution_2164()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	bool bFlip = false;
	while (q.size() > 1)
	{
		if (bFlip)
			q.push(q.front());
		q.pop();

		bFlip = !bFlip;
	}
	cout << q.front() << MEndl;

	return 0;
}

#pragma endregion

#pragma region 2609 : �ִ� ������� �ּ� �����

int GCD_2609(int a, int b)
{
	return b ? GCD_2609(b, a % b) : a;
}

int LCM_2609(int a, int b)
{
	return a * b / GCD_2609(a, b);
}

int Solution_2609()
{
	int a, b;
	cin >> a >> b;

	cout << GCD_2609(a, b) << MEndl;
	cout << LCM_2609(a, b) << MEndl;

	return 0;
}

#pragma endregion

#pragma region 2751 : �� �����ϱ�

int Solution_2751()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, * pData;

	cin >> N;
	pData = new int[N];

	for (int i = 0; i < N; i++)
		cin >> pData[i];

	sort(pData, pData + N);

	for (int i = 0; i < N; i++)
		cout << pData[i] << MEndl;

	return 0;
}

int Solution_2751_00()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	list<int> dataList;
	int iInput;
	for (int i = 0; i < N; i++)
	{
		cin >> iInput;
		dataList.push_back(iInput);
	}
	dataList.sort();
	for (const int& iData : dataList)
	{
		cout << iData << MEndl;
	}
	return 0;
}

#pragma endregion

#pragma region 2798 : ����

int Solution_2798()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M, * pCards, iSum, iMax = 0;

	cin >> N;
	cin >> M;
	pCards = new int[N];

	for (int i = 0; i < N; i++)
		cin >> pCards[i];

	for (int i = N - 1; i >= 2; --i)
	{
		iSum = pCards[i];
		if (M <= iSum)
			continue;

		for (int j = i - 1; j >= 1; --j)
		{
			iSum = pCards[i] + pCards[j];

			if (M <= iSum)
				continue;

			for (int k = j - 1; k >= 0; --k)
			{
				iSum = pCards[i] + pCards[j] + pCards[k];

				if (M < iSum)
					continue;
				else if (M == iSum)
				{
					iMax = iSum;
					goto loop_out;
				}
				else if (iSum > iMax)
				{
					iMax = iSum;
				}
			}
		}
	}

loop_out:

	cout << iMax << MEndl;
	delete[] pCards;

	return 0;
}

#pragma endregion

#pragma region 4153 : �����ﰢ��

int Solution_4153()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int iSide[3] = { 0, };

	while (true)
	{
		for (int i = 0; i < 3; i++)
			cin >> iSide[i];

		if (0 == iSide[0] &&
			0 == iSide[1] &&
			0 == iSide[2])
			break;

		sort(iSide, iSide + 3);

		if (MPow(iSide[2]) == (MPow(iSide[0]) + MPow(iSide[1])))
			cout << "right" << MEndl;
		else
			cout << "wrong" << MEndl;
	}

	return 0;
}

#pragma endregion

#pragma region 9012 : ��ȣ

int Solution_9012()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	string bracket = "";
	cin >> T;
	while (T--)
	{
		int st = 0;
		cin >> bracket;

		for (const char& ch : bracket)
		{
			if ('(' == ch)
				++st;
			else if (')' == ch)
				--st;

			if (0 > st)
				break;
		}

		cout << ((0 == st) ? "YES" : "NO") << MEndl;
	}
	return 0;
}

#pragma endregion

#pragma region 10250 : ACM ȣ��

int Solution_10250()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T, H, W, N;
	cin >> T;
	while (T--)
	{
		cin >> H >> W >> N;
		cout << (100 * (1 + (N - 1) % H)) + (1 + (N - 1) / H) << '\n';
	}
	return 0;
}

#pragma endregion

#pragma region 10814 : ���̼� ����

typedef struct tagMember_10814 {
	int iAge;
	string strName;
} TMember_10814;

bool Compare_10814(const TMember_10814& lhs, const TMember_10814& rhs) {
	return (lhs.iAge < rhs.iAge);
}

int Solution_10814() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	TMember_10814* pMembers = new TMember_10814[N];
	for (int i = 0; i < N; i++)
	{
		cin >> pMembers[i].iAge;
		cin >> pMembers[i].strName;
	}
	stable_sort(pMembers, pMembers + N, Compare_10814);
	for (int i = 0; i < N; i++)
	{
		cout << pMembers[i].iAge << ' ' << pMembers[i].strName << '\n';
	}
	return 0;
}

#pragma endregion

#pragma region 10816 : ���� ī�� 2

// ����������, �����÷ο�� �� ����
int Solution_10816_00()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M, iInput;
	array<int, 20000001> arr = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> iInput;
		++arr[iInput + 10000000];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> iInput;
		cout << arr[iInput + 10000000] << ' ';
	}
	return 0;
}

int Solution_10816()
{
	typedef map<int, int>::iterator itertype;
	typedef pair<const itertype, bool> rettype;
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M, iInput;
	map<int, int> cardCountMap;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> iInput;
		rettype ret = cardCountMap.emplace(iInput, 1);
		if (!ret.second)
			++(*ret.first).second;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> iInput;
		itertype iter = cardCountMap.find(iInput);
		cout << ((iter == cardCountMap.end()) ? 0 : (*iter).second) << ' ';
	}
	return 0;
}

#pragma endregion

#pragma region 10828 : ����

int Solution_10828()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, iInput;
	stack<int> st;
	string strOperation = "";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> strOperation;
		if ("push" == strOperation)
		{
			cin >> iInput;
			st.push(iInput);
		}
		else if ("pop" == strOperation)
		{
			if (st.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if ("size" == strOperation)
		{
			cout << st.size() << '\n';
		}
		else if ("empty" == strOperation)
		{
			cout << st.empty() << '\n';
		}
		else if ("top" == strOperation)
		{
			cout << (st.empty() ? -1 : st.top()) << '\n';
		}
	}

	return 0;
}

#pragma endregion

#pragma region 10845 : ť

/*
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

int Solution_10845()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, iInput;
	queue<int> qe;
	string strOperation = "";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> strOperation;
		if ("push" == strOperation)
		{
			cin >> iInput;
			qe.push(iInput);
		}
		else if ("pop" == strOperation)
		{
			if (qe.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << qe.front() << '\n';
				qe.pop();
			}
		}
		else if ("size" == strOperation)
		{
			cout << qe.size() << '\n';
		}
		else if ("empty" == strOperation)
		{
			cout << qe.empty() << '\n';
		}
		else if ("front" == strOperation)
		{
			cout << (qe.empty() ? -1 : qe.front()) << '\n';
		}
		else if ("back" == strOperation)
		{
			cout << (qe.empty() ? -1 : qe.back()) << '\n';
		}
	}
	return 0;
}

#pragma endregion

#pragma region 10866 : ��

/*
������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

int Solution_10866()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, iInput;
	deque<int> dq;
	string strOperation = "";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> strOperation;
		if ("push_front" == strOperation)
		{
			cin >> iInput;
			dq.push_front(iInput);
		}
		else if ("push_back" == strOperation)
		{
			cin >> iInput;
			dq.push_back(iInput);
		}
		else if ("pop_front" == strOperation)
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if ("pop_back" == strOperation)
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if ("size" == strOperation)
		{
			cout << dq.size() << '\n';
		}
		else if ("empty" == strOperation)
		{
			cout << dq.empty() << '\n';
		}
		else if ("front" == strOperation)
		{
			cout << (dq.empty() ? -1 : dq.front()) << '\n';
		}
		else if ("back" == strOperation)
		{
			cout << (dq.empty() ? -1 : dq.back()) << '\n';
		}
	}
	return 0;
}

#pragma endregion

#pragma region 11050 : ���� ��� 1

int Solution_11050()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	cout << Factorial_Iter(N) / (Factorial_Iter(K) * Factorial_Iter(N - K)) << '\n';
	return 0;
}

#pragma endregion

#pragma region 11650 : ��ǥ �����ϱ�

typedef struct tagPosition_11650 {
	int iX = 0;
	int iY = 0;
}TPosition_11650;

bool Compare_11650(const TPosition_11650& _lhs, const TPosition_11650& _rhs)
{
	if (_lhs.iX < _rhs.iX)
		return true;
	else if (_lhs.iX == _rhs.iX)
		return (_lhs.iY < _rhs.iY);
	return false;
}

int Solution_11650()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	pair<int, int>* pPositions = new pair<int, int>[N];
	for (int i = 0; i < N; i++)
	{
		cin >> pPositions[i].first >> pPositions[i].second;
	}
	sort(pPositions, pPositions + N);
	for (int i = 0; i < N; i++)
	{
		cout << pPositions[i].first << ' ' << pPositions[i].second << '\n';
	}
	delete[] pPositions;
	return 0;
}

int Solution_11650_00()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	TPosition_11650* pPositions = new TPosition_11650[N];
	for (int i = 0; i < N; i++)
	{
		cin >> pPositions[i].iX >> pPositions[i].iY;
	}
	sort(pPositions, pPositions + N, Compare_11650);
	for (int i = 0; i < N; i++)
	{
		cout << pPositions[i].iX << ' ' << pPositions[i].iY << '\n';
	}
	delete[] pPositions;
	return 0;
}

#pragma endregion

#pragma region 11866 : �似Ǫ�� ���� 0

int Solution_11866()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	list<int> sequenceList;
	queue<int> numberQueue;
	for (int i = 1; i <= N; i++)
		numberQueue.push(i);

	while (!numberQueue.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			numberQueue.push(numberQueue.front());
			numberQueue.pop();
		}
		sequenceList.push_back(numberQueue.front());
		numberQueue.pop();
	}
	cout << '<';
	for (auto iter = sequenceList.begin(); iter != sequenceList.end(); iter++)
	{
		cout << *iter;
		if (iter != --sequenceList.end())
			cout << ", ";
	}
	cout << '>';

	return 0;
}

int Solution_11866_00()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	list<int> dataList;
	queue<int> sequence;
	for (int i = 1; i <= N; i++)
		dataList.push_back(i);

	auto iter = dataList.begin();
	while (!dataList.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			iter++;
			if (iter == dataList.end())
				iter = dataList.begin();
		}
		sequence.push(*iter);
		iter = dataList.erase(iter);
		if (iter == dataList.end())
			iter = dataList.begin();
	}

	cout << "<";
	while (true)
	{
		cout << sequence.front();
		sequence.pop();
		if (sequence.empty())
		{
			cout << ">\n";
			break;
		}
		else
		{
			cout << ", ";
		}
	}

	return 0;
}

#pragma endregion

#pragma region 2775 : �γ�ȸ���� ���׾�

int Calculate_Recursive_2775(int k, int n)
{
	if (0 == k)
		return n;
	else
	{
		int iRet = 0;
		for (int i = 1; i <= n; i++)
			iRet += Calculate_Recursive_2775(k - 1, i);

		return iRet;
	}
}

int Solution_2775()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T, k, n;
	int arr[15][15] = { 0 };

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (0 == i)
			{
				arr[i][j] = j + 1;
			}
			else
			{
				for (int l = 0; l <= j; l++)
				{
					arr[i][j] += arr[i - 1][l];
				}
			}
		}
	}

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> k >> n;
		cout << arr[k][n - 1] << '\n';
	}
	return 0;
}

int Solution_2775_00()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T, k, n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> k >> n;
		cout << Calculate_Recursive_2775(k, n) << '\n';
	}
	return 0;
}

#pragma endregion

#pragma region 2805 : ���� �ڸ���
/*
����
����̴� ���� M���Ͱ� �ʿ��ϴ�. ��ó�� ������ ������ ���� ��� ���ع��ȱ� ������, ���ο� ���� �㰡�� ��û�ߴ�. ���δ� ����̳� �� ��ó�� ���� �� �ٿ� ���� ���� �㰡�� ���־���, ����̴� ���� ������ �������ܱ⸦ �̿��ؼ� ������ ���Ұ��̴�.

�������ܱ�� ������ ���� �����Ѵ�. ����, ����̴� ���ܱ⿡ ���� H�� �����ؾ� �Ѵ�. ���̸� �����ϸ� �鳯�� �����κ��� H���� ���� �ö󰣴�. �� ����, �� �ٿ� �������ִ� ������ ��� �����ع�����. ����, ���̰� H���� ū ������ H ���� �κ��� �߸� ���̰�, ���� ������ �߸��� ���� ���̴�. ���� ���, �� �ٿ� �������ִ� ������ ���̰� 20, 15, 10, 17�̶�� ����. ����̰� ���̸� 15�� �����ߴٸ�, ������ �ڸ� ���� ���̴� 15, 15, 10, 15�� �� ���̰�, ����̴� ���̰� 5�� ������ 2�� ������ ��� ���� �� ���̴�. (�� 7���͸� ���� ��� ����) ���ܱ⿡ ������ �� �ִ� ���̴� ���� ���� �Ǵ� 0�̴�.

����̴� ȯ�濡 �ſ� ������ ���� ������, ������ �ʿ��� ��ŭ�� ������ ���������� �Ѵ�. �̶�, ��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ �� N�� ����̰� ������ ���������� �ϴ� ������ ���� M�� �־�����. (1 �� N �� 1,000,000, 1 �� M �� 2,000,000,000)

��° �ٿ��� ������ ���̰� �־�����. ������ ������ ���� �׻� M���� ũ�ų� ���� ������, ����̴� ���� �ʿ��� ������ �׻� ������ �� �ִ�. ���̴� 1,000,000,000���� �۰ų� ���� ���� ���� �Ǵ� 0�̴�.

���
��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ��� ����Ѵ�.
*/

bool Check_2805(int* pTree, int iTreeCount, int iHeight, int M)
{
	long long iSum = 0;
	for (int i = 0; i < iTreeCount; i++)
	{
		if (iHeight < pTree[i])
			iSum += (pTree[i] - iHeight);
	}
	if (iSum >= M)
		return true;
	else
		return false;
}

int Solution_2805() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	int* pTree = nullptr;
	int iStart = 0, iEnd = 0;

	cin >> N >> M;
	pTree = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> pTree[i];
		iEnd = max(pTree[i], iEnd);
	}

	while (iStart + 1 < iEnd)
	{
		int iMid = (iStart + iEnd) / 2;
		if (Check_2805(pTree, N, iMid, M))
		{
			iStart = iMid;
		}
		else
		{
			iEnd = iMid;
		}
	}
	cout << iStart << '\n';

	return 0;
}

int Solution_2805_00()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M, H = 0;
	int* pTree = nullptr;
	int iStart = 0, iEnd = 0;

	cin >> N >> M;
	pTree = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> pTree[i];
		iEnd = max(pTree[i], iEnd);
	}

	while (iStart <= iEnd)
	{
		int iMid = (iStart + iEnd) >> 1;
		long long iSum = 0;
		for (int i = 0; i < N; i++)
		{
			if (pTree[i] > iMid)
				iSum += pTree[i] - iMid;
		}
		if (M == iSum)
		{
			H = iMid;
			break;
		}
		else if (M > iSum)
		{
			iEnd = iMid - 1;
		}
		else
		{
			iStart = iMid + 1;
			H = iMid;
		}
	}

	cout << H << '\n';

	return 0;
}

#pragma endregion

#pragma region 11651 : ��ǥ �����ϱ� 2

/*
����
2���� ��� ���� �� N���� �־�����. ��ǥ�� y��ǥ�� �����ϴ� ������, y��ǥ�� ������ x��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����. (-100,000 �� xi, yi �� 100,000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.

���
ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.
*/

int Solution_11651()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	list<pair<int, int>> Positions;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int iX, iY;
		cin >> iX >> iY;
		Positions.push_back(make_pair(iY, iX));
	}
	Positions.sort();
	for (pair<int, int> Position : Positions)
	{
		cout << Position.second << ' ' << Position.first << '\n';
	}

	return 0;
}

#pragma endregion

#pragma region 2839 : ���� ���

/*
����
����̴� ���� �������忡�� ������ ����ϰ� �ִ�. ����̴� ���� �������Կ� ������ ��Ȯ�ϰ� Nų�α׷��� ����ؾ� �Ѵ�. �������忡�� ����� ������ ������ ����� �ִ�. ������ 3ų�α׷� ������ 5ų�α׷� ������ �ִ�.

����̴� ������ ������, �ִ��� ���� ������ ��� ������ �Ѵ�. ���� ���, 18ų�α׷� ������ ����ؾ� �� ��, 3ų�α׷� ���� 6���� �������� ������, 5ų�α׷� 3���� 3ų�α׷� 1���� ����ϸ�, �� ���� ������ ������ ����� �� �ִ�.

����̰� ������ ��Ȯ�ϰ� Nų�α׷� ����ؾ� �� ��, ���� �� ���� �������� �Ǵ��� �� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (3 �� N �� 5000)

���
����̰� ����ϴ� ������ �ּ� ������ ����Ѵ�. ����, ��Ȯ�ϰ� Nų�α׷��� ���� �� ���ٸ� -1�� ����Ѵ�.
*/

int Solution_2839()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;

	int d_5 = N / 5;
	int r_5 = N % 5;

	// N�� 5���
	if (r_5 == 0)
	{
		cout << d_5 << '\n';
	}
	else
	{
		int r_3 = r_5 % 3;
		int d_3 = r_5 / 3;

		// N�� 5�� ���� �������� 3�� ���
		if (r_3 == 0)
		{
			cout << d_5 + d_3 << '\n';
		}
		else
		{
			// N���� 5�� ����� ���µ�, ������ ���� ����
			// �� ����� 3����� �� ������ Ȥ�� ������ 0���� ���� �� ����
			while (0 <= --d_5)
			{
				int N_ = N - d_5 * 5;
				r_3 = N_ % 3;
				if (r_3 == 0)
				{
					d_3 = N_ / 3;
					break;
				}
			}

			if (r_3 == 0)
			{
				cout << d_5 + d_3 << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}

#pragma endregion

#pragma endregion // Previous Solutions

#pragma region 4949 : �������� ����

/*
����
����� ������ �� �����־�� �Ѵ�. ��� ��, ���� ��� �׸��� ���� ��ȣ�� ������ ��ȣó�� ���̴�.

�������� �ӹ��� � ���ڿ��� �־����� ��, ��ȣ���� ������ �� ������ �ִ��� �Ǵ��ϴ� ���α׷��� ¥�� ���̴�.

���ڿ��� ���ԵǴ� ��ȣ�� �Ұ�ȣ("()") �� ���ȣ("[]")�� 2�����̰�, ���ڿ��� ������ �̷�� ������ �Ʒ��� ����.

��� ���� �Ұ�ȣ("(")�� ������ �Ұ�ȣ(")")�͸� ¦�� �̷�� �Ѵ�.
��� ���� ���ȣ("[")�� ������ ���ȣ("]")�͸� ¦�� �̷�� �Ѵ�.
��� ������ ��ȣ���� �ڽŰ� ¦�� �̷� �� �ִ� ���� ��ȣ�� �����Ѵ�.
��� ��ȣ���� ¦�� 1:1 ��Ī�� �����ϴ�. ��, ��ȣ �ϳ��� �� �̻��� ��ȣ�� ¦�������� �ʴ´�.
¦�� �̷�� �� ��ȣ�� ���� ��, �� ���̿� �ִ� ���ڿ��� ������ ������ �Ѵ�.
�����̸� ���� ���ڿ��� �־����� �� �������� ���ڿ����� �ƴ����� �Ǵ��غ���.

�Է�
�� ���ڿ��� ������ ���ڸ� �����ϰ� ���� ���ĺ�, ����, �Ұ�ȣ("( )"), ���ȣ("[ ]")�� �̷���� ������, ����(".")���� ������, ���̴� 100���ں��� �۰ų� ����.

�Է��� ������������ �� �������� ���� �ϳ�(".")�� ���´�.
���
�� �ٸ��� �ش� ���ڿ��� ������ �̷�� ������ "yes"��, �ƴϸ� "no"�� ����Ѵ�.

���� �Է�
So when I die (the [first] I will see in (heaven) is a score list).
[ first in ] ( first out ).
Half Moon tonight (At least it is better than no Moon at all].
A rope may form )( a trail in a maze.
Help( I[m being held prisoner in a fortune cookie factory)].
([ (([( [ ] ) ( ) (( ))] )) ]).
 .
.

���� ���
yes
yes
no
no
no
yes
yes

*/

int Solution_4949()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	while (true)
	{
		string strInput = "";
		stack<char> st;
		bool bIsBalanced = true;
		getline(cin, strInput);
		if (strInput == ".")
			break;

		bIsBalanced = true;
		for (char ch : strInput)
		{
			switch (ch)
			{
			case '(':
			{
				st.push(ch);
			}
			break;
			case ')':
			{
				if (st.empty() || st.top() != '(')
					bIsBalanced = false;
				else
					st.pop();
			}
			break;
			case '[':
			{
				st.push(ch);
			}
			break;
			case ']':
			{
				if (st.empty() || st.top() != '[')
					bIsBalanced = false;
				else
					st.pop();
			}
			break;
			default:
				break;
			}

			if (false == bIsBalanced)
				break;
		}

		if (false == bIsBalanced || !st.empty())
			cout << "no" << '\n';
		else
			cout << "yes" << '\n';
	}

	return 0;
}

// ���� �ƴ�
int Solution_4949_00()
{
	string strInput = "";
	int iSmallCnt = 0;
	int iBigCnt = 0;
	bool bIsBalanced = true;
	int iStartIndex = 0;
	int iEndIndex = 0;
	getline(cin, strInput);

	while (true)
	{
		iEndIndex = strInput.find('.', iStartIndex);
		if (string::npos == iEndIndex)
			break;

		bIsBalanced = true;

		for (int i = iStartIndex; i < iEndIndex; i++)
		{
			if (0 > iSmallCnt || 0 > iBigCnt)
			{
				bIsBalanced = false;
				break;
			}

			switch (strInput[i])
			{
			case '(':	++iSmallCnt;	break;
			case ')':	--iSmallCnt;	break;
			case '[':	++iBigCnt;		break;
			case ']':	--iBigCnt;		break;
			default:	break;
			}
		}

		if (true == bIsBalanced)
		{
			if (0 != iSmallCnt || 0 != iBigCnt)
				bIsBalanced = false;
		}

		cout << ((bIsBalanced) ? "yes" : "no") << '\n';
		iStartIndex = ++iEndIndex;
	}
	return 0;
}

#pragma endregion

#pragma region 7568 : ��ġ

/*
����
�츮�� ����� ��ġ�� Ű�� ������, �� �� ���� ������ ǥ���Ͽ� �� ����� �Űܺ����� �Ѵ�.
� ����� �����԰� x kg�̰� Ű�� y cm��� �� ����� ��ġ�� (x, y)�� ǥ�õȴ�.
�� ��� A �� B�� ��ġ�� ���� (x, y), (p, q)��� �� �� x > p �׸��� y > q �̶�� �츮�� A�� ��ġ�� B�� ��ġ���� "�� ũ��"�� ���Ѵ�.
���� ��� � A, B �� ����� ��ġ�� ���� (56, 177), (45, 165) ��� �Ѵٸ� A�� ��ġ�� B���� ū ���� �ȴ�.
�׷��� ���� �ٸ� ��ġ���� ũ�⸦ ���� �� ���� ��쵵 �ִ�.
���� ��� �� ��� C�� D�� ��ġ�� ���� (45, 181), (55, 173)�̶�� �����Դ� D�� C���� �� ���̰�, Ű�� C�� �� ũ�Ƿ�, "��ġ"�θ� �� �� C�� D�� ������ ���溸�� �� ũ�ٰ� ���� �� ����.

N���� ���ܿ��� �� ����� ��ġ ����� �ڽź��� �� "ū ��ġ"�� ����� ���� ��������. ���� �ڽź��� �� ū ��ġ�� ����� k���̶�� �� ����� ��ġ ����� k+1�� �ȴ�.
�̷��� ����� �����ϸ� ���� ��ġ ����� ���� ����� ���� �� �����ϴ�. �Ʒ��� 5������ �̷���� ���ܿ��� �� ����� ��ġ�� �� ����� ǥ�õ� ǥ�̴�.

�̸�	(������, Ű)	��ġ ���
A	(55, 185)	2
B	(58, 183)	2
C	(88, 186)	1
D	(60, 175)	2
E	(46, 155)	5

�� ǥ���� C���� �� ū ��ġ�� ����� �����Ƿ� C�� 1���� �ȴ�.
�׸��� A, B, D ������ ��ġ���� ū ����� C���̹Ƿ� �̵��� ��� 2���� �ȴ�.
�׸��� E���� ū ��ġ�� A, B, C, D �̷��� 4���̹Ƿ� E�� ��ġ�� 5���� �ȴ�. �� ��쿡 3��� 4���� �������� �ʴ´�.
�������� �л� N���� �����Կ� Ű�� ��� �Է��� �о �� ����� ��ġ ����� ����Ͽ� ����ؾ� �Ѵ�.

�Է�
ù �ٿ��� ��ü ����� �� N�� �־�����. �׸��� �̾����� N���� �ٿ��� �� ����� �����Կ� Ű�� ��Ÿ���� ���� ���� x�� y�� �ϳ��� ������ �ΰ� ���� ��Ÿ����.

���
�������� �Է¿� ������ ����� ��ġ ����� ���ؼ� �� ������� ù �ٿ� ����ؾ� �Ѵ�. ��, �� ��ġ ����� ���鹮�ڷ� �и��Ǿ�� �Ѵ�.

����
2 �� N �� 50
10 �� x, y �� 200

���� �Է�
	5
	55 185
	58 183
	88 186
	60 175
	46 155

���� ���
2 2 1 2 5

///
5
58 180
54 180
58 181
59 179
59 159

Output)

2 3 1 1 2

Answer)

1 2 1 1 1
*/



typedef struct tagPerson_7568 {
	int x = 0;
	int y = 0;
	int iRank = 1;
}TPerson_7568;

// �ʿ����
bool Compare_7568(TPerson_7568& _lhs, TPerson_7568& _rhs)
{
	if (_lhs.x > _rhs.x)
		return (_lhs.y >= _rhs.y);
	else if (_lhs.x == _rhs.x)
		return (_lhs.y > _rhs.y);

	return false;
}

int Solution_7568()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N = 0;
	TPerson_7568 people[50] = {};
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> people[i].x >> people[i].y;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j == i)
				continue;

			if (people[i].x < people[j].x &&
				people[i].y < people[j].y)
			{
				people[i].iRank++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << people[i].iRank << ' ';
	}

	return 0;
}

// ����ƴ�
int Solution_7568_00()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	typedef list<TPerson_7568>::iterator Iter_Type;
	int N = 0;
	int iRank = 1, iRank_Old = 2;
	list<TPerson_7568> people;
	list<TPerson_7568*> people_order;
	cin >> N;
	while (N--)
	{
		TPerson_7568 tPerson;
		cin >> tPerson.x >> tPerson.y;
		people.push_back(tPerson);
		people_order.push_back(&people.back());
	}

	people.sort(Compare_7568);
	people.front().iRank = iRank;
	for (Iter_Type iter = people.begin(); iter != people.end(); iter++)
	{
		Iter_Type iter_next = iter;
		++iter_next;
		++iRank;
		if (iter->x > iter_next->x)
		{
			if (iter->y >= iter_next->y)
			{
				iter_next->iRank = iRank;
				iRank_Old = iRank;
			}
			else
			{
				iter_next->iRank = iRank_Old;
			}
		}
		else if (iter->x == iter_next->x)
		{
			if (iter->y > iter_next->y)
			{
				iter_next->iRank = iRank;
				iRank_Old = iRank;
			}
			else
			{
				iter_next->iRank = iRank_Old;
			}
		}
		else
		{
			iter_next->iRank = iRank_Old;
		}

		if (iter_next == --people.end())
		{
			break;
		}
	}


	for (TPerson_7568* pPerson : people_order)
	{
		cout << pPerson->iRank << ' ';
	}
	cout << '\n';

	return 0;
}

#pragma endregion


int main()
{
	cout << "===== " << _PROBLEM_NUMBER << " =====" << MEndl;

	MAppend_Function(Solution_, _PROBLEM_NUMBER);
	system("pause");

	return 0;
}