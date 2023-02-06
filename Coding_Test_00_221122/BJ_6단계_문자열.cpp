#include "Default.h"

#define _PROBLEM_NUMBER 1316

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

#pragma region 11654 : 아스키 코드

int Solution_11654()
{
	//char Code = 0;

	//cin >> Code;

	//cout << (int)Code << '\n';

	cout << cin.get();

	return 0;
}

#pragma endregion

#pragma region 11720 : 숫자의 합

int Solution_11720()
{
	int N = 0, iSum = 0;
	char strNumber[101] = { 0 };

	cin >> N;
	cin >> strNumber;


	for (int i = 0; i < N; i++)
	{
		if ('0' > strNumber[i] || '9' < strNumber[i])
			continue;

		iSum += strNumber[i] - '0';
	}

	cout << iSum << '\n';

	return 0;
}

#pragma endregion

#pragma region 10809 : 알파벳 찾기

int Solution_10809()
{
	char S[101] = { 0 };
	int AP[26] = { 0 };
	cin >> S;


	for (int& iter : AP)
	{
		iter = -1;
	}

	for (int i = 0; i < 100; i++)
	{
		int iIndex = S[i] - 'a';

		if (-1 != AP[iIndex])
			continue;

		AP[S[i] - 'a'] = i;
	}

	for (int& iter : AP)
	{
		cout << iter << ' ';
	}
	cout << '\n';

	return 0;
}

#pragma endregion

#pragma region 2675 : 문자열 반복

int Solution_2675()
{
	int T = 0, R = 0;
	char S[21] = "";

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> R;
		cin >> S;

		int iLength = static_cast<int>(strlen(S));

		for (int j = 0; j < iLength; j++)
		{
			for (int k = 0; k < R; k++)
			{
				cout << S[j];
			}
		}
		cout << '\n';
	}

	return 0;
}

int Solution_2675_1()
{
	int T = 0, R = 0;
	string S = "";

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> R >> S;

		int iLength = static_cast<int>(S.length());

		for (int j = 0; j < iLength; j++)
		{
			for (int k = 0; k < R; k++)
			{
				cout << S[j];
			}
		}
		cout << '\n';
	}

	return 0;
}

#pragma endregion

#pragma region 1157 : 단어 공부

int Solution_1157()
{
	string s = "";
	int ASCII_Count[128] = { 0 };
	int iMax = 0;
	int iMaxIndex = 0;
	int iOffset = 'a' - 'A';
	bool bEqual = false;

	cin >> s;

	for (size_t i = 0; i < s.length(); i++)
	{
		int iIndex = ('Z' < s[i]) ? s[i] - iOffset : s[i];

		if (iMax < ++ASCII_Count[iIndex])
		{
			iMaxIndex = iIndex;
			iMax = ASCII_Count[iIndex];
			bEqual = false;
		}
		else if (iMax == ASCII_Count[iIndex])
		{
			bEqual = true;
		}
	}

	if (bEqual)
	{
		cout << '?';
	}
	else
	{
		cout << (char)iMaxIndex;
	}

	return 0;
}

#pragma endregion

#pragma region 1152 : 단어의 개수

int Solution_1152()
{
	string s = "";
	int iCount = 0;

	getline(cin, s);

	size_t iLength = s.length();

	if (s.front() != ' ')
		++iCount;

	for (size_t i = 1; i < s.length(); i++)
	{
		if (' ' == s.at(i - 1))
		{
			++iCount;
		}
	}

	cout << iCount;

	return 0;
}

#pragma endregion

#pragma region 2908 : 상수

int Reverse_2908(int N)
{
	int iCount = 0;
	int iTemp = N;

	while (0 < iTemp)
	{
		iTemp /=10;
		++iCount;
	}

	iTemp = 0;

	for (int i = 0; i < iCount; i++)
	{
		iTemp += (N % 10) * static_cast<int>(pow(10, iCount - i - 1)); // 자리수 더하기
		N /= 10;
	}

	return iTemp;
}

int Solution_2908()
{
	int A, B;

	cin >> A >> B;

	cout << max(Reverse_2908(A), Reverse_2908(B)) << endl;

	return 0;
}

#pragma endregion

#pragma region 5622 : 다이얼

int Solution_5622_00()
{
	string strInput = "";

	cin >> strInput;

	int iTime = 0;

	for (char& chInput : strInput)
	{
		int iTemp = chInput - 'A';

		if (0 > iTemp)
		{
			iTime += 2;
			continue;
		}

		iTemp = (iTemp / 3) + 1; // 시간

		if (9 < iTemp)
			iTemp = 9;

		iTemp += 2; // 1번 다이얼 시간

		iTime += iTemp;
	}

	cout << iTime << '\n';

	return 0;
}

int Solution_5622()
{
	string strInput = "";

	cin >> strInput;

	int iTime = 0;

	for (const char& chInput : strInput)
	{
		if ('A' > chInput)
		{
			iTime += 2;
		}
		else if ('D' > chInput) // 2 : ABC
		{
			iTime += 2 + 1;
		}
		else if ('G' > chInput)	// 3 : DEF
		{
			iTime += 2 + 2;
		}
		else if ('J' > chInput)	// 4 : 
		{
			iTime += 2 + 3;
		}
		else if ('M' > chInput)
		{
			iTime += 2 + 4;
		}
		else if ('P' > chInput)
		{
			iTime += 2 + 5;
		}
		else if ('T' > chInput)
		{
			iTime += 2 + 6;
		}
		else if ('W' > chInput)
		{
			iTime += 2 + 7;
		}
		else if ('Z' >= chInput)
		{
			iTime += 2 + 8;
		}
		else
		{
			iTime += 2 + 9;
		}
	}

	cout << iTime << '\n';

	return 0;
}

#pragma endregion

#pragma region 2941 : 크로아티아 알파벳

int Solution_2941()
{
	string arrCroatia[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string strInput;
	cin >> strInput;
	int iCount = 0;
	int iOffset = 0;
	int iInputLength = strInput.length();

	while (true)
	{
		bool bFindCroatia = false; // arrCroatia 에 속한 문자를 찾았는지

		for (string& Croatia : arrCroatia)
		{
			int iCroatiaLength = Croatia.length();

			if (0 == strInput.compare(iOffset, iCroatiaLength, Croatia))
			{
				++iCount;
				iOffset += iCroatiaLength;
				bFindCroatia = true;

				break;
			}
		}

		if (false == bFindCroatia)
		{
			++iOffset;
			++iCount;
		}

		if (iOffset >= iInputLength)
			break;
	}

	cout << iCount << ENDL;

	return 0;
}

#pragma endregion

#pragma region 1316 : 그룹 단어 체커

int Solution_1316()
{
	char strInput[101] = ""; // 입력 문자열
	int N = 0;
	int iCount = 0; // 그룹 단어 개수

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> strInput;

		int iLength = static_cast<int>(strlen(strInput));

		if (1 == iLength)
		{
			++iCount;
		}
		else
		{
			char chPre = '\0'; // 비교할 이전 문자
			bool bAlphabet[128] = { false }; // 알파벳 입력 여부
			bool bIsGroup = true;

			chPre = strInput[0];
			bAlphabet[chPre] = true;

			for (int i = 1; i < iLength; i++)
			{
				if (chPre != strInput[i])
				{
					if (true == bAlphabet[strInput[i]])
					{
						bIsGroup = false;
						break;
					}

					chPre = strInput[i];
				}

				bAlphabet[strInput[i]] = true;
			}

			if (true == bIsGroup)
				++iCount;
		}
	}

	cout << iCount << ENDL;

	return 0;
}

#pragma endregion



#pragma endregion



int main()
{
	MAppend_Function(Solution_, _PROBLEM_NUMBER);
	system("pause");
	return 0;
}