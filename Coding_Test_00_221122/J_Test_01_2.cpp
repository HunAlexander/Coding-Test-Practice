#include "Default.h"

using namespace std;

bool solution(string s, string t)
{
	bool answer = true;

	int iSize_S = s.size();
	int iSize_T = t.size();

	string origin = "";
	string compare = "";
	string second = "";
	bool bCmpDone = false;

	if (iSize_S > iSize_T)
	{
		for (int i = 1; i < (iSize_S >> 1); i++)
		{
			if (s.at(0) == s.at(i))
			{
				origin.assign(s.begin(), s.begin() + i);
				compare.assign(s.begin() + i, s.begin() + 2 * i);

				if (0 == origin.compare(compare))
				{
					if (iSize_S < 3 * i)
						continue;

					compare.assign(s.begin() + 2 * i, s.begin() + 3 * i);

					if (0 == origin.compare(compare))
					{
						bCmpDone = true;
						break;
					}
				}
			}
		}

		if (false == bCmpDone)
		{
			return false;
		}

	}
	else
	{
		for (int i = 1; i < iSize_T; i++)
		{
			if (t.at(0) == t.at(i))
			{
				origin.assign(t.begin(), t.begin() + i);
				compare.assign(t.begin() + i, t.begin() + i + i);

				if (0 == origin.compare(compare))
				{
					bCmpDone = true;
					break;
				}
			}
		}

		if (false == bCmpDone)
		{
			return false;
		}
	}


	second.assign(t.begin(), t.begin() + origin.size());

	return second == origin;
}

void main()
{
	MCout_Bool(solution("ABAB", "AB"));

	//cout << solution("AB", "ABABC") << endl;

	system("pause");
}