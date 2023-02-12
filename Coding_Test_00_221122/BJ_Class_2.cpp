#include "Default.h"
#define _PROBLEM_NUMBER 10845

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
			for (int j = i * i; j <= N; j+=i)
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
			for (int j = i * i; j <= 1000; j+=i)
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

	int N, *pData;

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

	int N, M, *pCards, iSum, iMax = 0;

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

#pragma endregion // Previous Solutions

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

int main()
{
	cout << "===== " << _PROBLEM_NUMBER << " =====" << MEndl;

	MAppend_Function(Solution_, _PROBLEM_NUMBER);
	system("pause");

	return 0;
}