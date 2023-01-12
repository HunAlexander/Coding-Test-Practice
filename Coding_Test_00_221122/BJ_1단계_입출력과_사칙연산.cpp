#include <iostream>
#include <cstdio>

#pragma region 1000 : A + B
//int main()
//{
//	using namespace std;
//	int iA = 0, iB = 0;
//	cin >> iA;
//	cin >> iB;
//
//	cout << iA + iB << endl;
//
//	system("pause");
//
//	return 0;
//}
#pragma endregion

#pragma region 1001 : A - B
//int main()
//{
//	using namespace std;
//	int iA = 0, iB = 0;
//	cin >> iA;
//	cin >> iB;
//
//	printf("%.10f", iA / (double)iB);
//
//	system("pause");
//
//	return 0;
//}
#pragma endregion

#pragma region 10998 : 사칙연산
//int main()
//{
//	using namespace std;
//	int iA = 0, iB = 0;
//	cin >> iA >> iB;
//
//	cout << iA + iB << endl;
//	cout << iA - iB << endl;
//	cout << iA * iB << endl;
//	cout << iA / iB << endl;
//	cout << iA % iB << endl;
//
//	system("pause");
//
//	return 0;
//}
#pragma endregion

#pragma region 10926 : ??!
//int main()
//{
//	int iOrigins[6] = { 1, 1, 2, 2, 2, 8 };
//
//	using namespace std;
//
//	char szID[51] = "";
//
//	cin >> szID;
//
//	strcat_s(szID, "??!");
//
//	cout << szID << endl;
//
//	system("pause");
//
//	return 0;
//}
#pragma endregion

#pragma region 3003 : 킹, 퀸, 룩, 비숍, 나이트, 폰
//int main()
//{
//	using namespace std;
//
//	int iNums[6] = { 0 };
//	int iOrigins[6] = { 1, 1, 2, 2, 2, 8 };
//
//	for (int& iNum : iNums)
//	{
//		cin >> iNum;
//	}
//
//	for (int i = 0; i < 6; ++i)
//	{
//		iNums[i] = iOrigins[i] - iNums[i];
//		cout << iNums[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}
#pragma endregion

#pragma region 10430 : 나머지
//int main()
//{
//	using namespace std;
//
//	int A = 0, B = 0, C = 0;
//
//	cin >> A >> B >> C;
//
//	cout << (A + B) % C << endl;
//	cout << ((A % C) + (B % C)) % C << endl;
//	cout << (A * B) % C << endl;
//	cout << ((A % C) * (B % C)) % C << endl;
//
//	return 0;
//}
#pragma endregion

#pragma region 10430 : 나머지
int main()
{
	using namespace std;

	int iA = 0, iB = 0;

	cin >> iA >> iB;

	int iB100 = iB / 100;
	int iB10 = (iB / 10) % 10;
	int iB1 = iB % 10;

	int i3 = iA * iB1;
	int i4 = iA * iB10;
	int i5 = iA * iB100;

	cout << i3 << endl << i4 << endl << i5 << endl;
	cout << i3 + 10 * i4 + 100 * i5 << endl;

	system("pause");

	return 0;
}
#pragma endregion
