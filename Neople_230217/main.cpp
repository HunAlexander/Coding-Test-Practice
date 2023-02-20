#include "Default.h"

#define _PROBLEM_NUMBER 2

typedef struct tagVersionInfo {
	int iIndex = 0;
	int iMajor = 0;
	int iMinor = 0;
	int iPatch = 0;
}TVersionInfo;

bool Compare(const TVersionInfo& lhs, const TVersionInfo& rhs)
{
	if (lhs.iMajor < rhs.iMajor)
	{
		return true;
	}
	else if (lhs.iMajor == rhs.iMajor)
	{
		if (lhs.iMinor < rhs.iMinor)
			return true;
		else if (lhs.iMinor == rhs.iMinor)
		{
			return (lhs.iPatch < rhs.iPatch);
		}
		else
			return false;
	}
	else
		return false;
}

vector<string> Solution_1(vector<string> versions)
{
	vector<string> answer;
	list<TVersionInfo> tVersionInfoList;

	int iSize = static_cast<int>(versions.size());

	for (int i = 0; i < iSize; i++)
	{
		TVersionInfo tVersionInfo;
		tVersionInfo.iIndex = i;
		stack<int> stNumber;
		int iFlag = 0;
		for (const char ch : versions[i])
		{
			if (ch == '.' || ch == '\0')
			{
				int idigit = 1;
				int iVersionNumber = 0;
				while (!stNumber.empty())
				{
					iVersionNumber += stNumber.top() * idigit;
					idigit *= 10;
					stNumber.pop();
				}

				switch (iFlag++)
				{
				case 0:
					tVersionInfo.iMajor = iVersionNumber;
					break;
				case 1:
					tVersionInfo.iMinor = iVersionNumber;
					break;
				case 2:
					tVersionInfo.iPatch = iVersionNumber;
					break;
				default:
					break;
				}
			}
			else
			{
				stNumber.push(ch - '0');
			}
		}

		int idigit = 1;
		int iVersionNumber = 0;
		while (!stNumber.empty())
		{
			iVersionNumber += stNumber.top() * idigit;
			idigit *= 10;
			stNumber.pop();
		}
	}

	tVersionInfoList.sort(Compare);
	for (const TVersionInfo& tVersionInfo : tVersionInfoList)
	{
		answer.push_back(versions[tVersionInfo.iIndex]);
	}

	return answer;
}


int solution_2(vector<string> logs) {
	int answer = -1;
	for (const string& log : logs)
	{
		int iSize = static_cast<int>(log.size());
		int iFlag = 0;
		bool bFlag = true;
		for (int i = 0; i < iSize; ++i)
		{
			char chCmp = '\0';
			string strCmp = "";
			int iCmpLength = 0;

			if (bFlag)
			{
				bFlag = false;
				switch (iFlag)
				{
				case 0:
					chCmp = 't';
					strCmp = "team_name : ";
					iCmpLength = strCmp.length();
					break;
				case 1:
					chCmp = 'a';
					strCmp = "application_name : ";
					iCmpLength = strCmp.length();
					break;
				case 2:
					chCmp = 'e';
					strCmp = "error_level : ";
					iCmpLength = strCmp.length();
					break;
				case 3:
					chCmp = 'm';
					strCmp = "message : ";
					iCmpLength = strCmp.length();
					break;
				default:
					break;
				}
			}

			if (chCmp == log[i])
			{
				if (i + iCmpLength >= iSize)
				{
					iFlag = -1;
					break;
				}

				if (log.substr(i, iCmpLength) == strCmp)
				{
					if (' ' == log[i + iCmpLength + 1])
						break;

					++iFlag;
					bFlag = true;
					i += iCmpLength;
				}
			}

			if (-1 == iFlag || 4 == iFlag)
				break;
		}
		if (4 != iFlag)
		{
			++answer;
		}
	}
	return answer;
}

//vector<vector<int>> Calculate_Potion(int k, int n, vector<int>& v)
//{
//	if (v.size() == k)
//	{
//		v.push_back(n);
//	}
//	else
//	{
//		for (int i = 0; i <= n; ++i)
//		{
//			v.push_back(i);
//			Calculate_Potion(k, n - i, v);
//		}
//	}
//}

int solution_3(int k, int n, vector<vector<int>> stats) {
	int answer = 0;
	int iSize = static_cast<int>(stats.size());
	list<vector<int>> characters;
	vector<vector<int>> potions;

	vector<int> potion;
	for (int i = 0; i <= n; ++i)
	{
		potion.push_back(i);
		for (int j = 0; j <= n - i; ++j)
		{
			potion.push_back(j);
			for (int l = 0; l <= n - i - j; ++j)
			{
				potion.push_back(l);

				potion.push_back(n - i - j - l);
			}
		}
	}

	while (true)
	{
		auto iter = stats.begin();
		if (k > characters.size())
		{
			characters.push_back(*iter);
			++iter;
		}
		else
		{
			int iSum = 0;
			for (auto character : characters)
			{
				iSum += character[0];
			}
		}
	}

	return answer;
}

int solution_4(vector<string> nicks, vector<string> emails) {
	int answer = -1;
	int iSize = static_cast<int>(nicks.size());
	bool bSame = false;
	map<int, list<int>> accounts;
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = i + 1; j < iSize; ++j)
		{
			if (nicks[i] == nicks[j])
			{
				bSame = true;
			}
			else if (nicks[i].size() > nicks[j].size())
			{
				int iNickSize = nicks[i].size();
				for (int k = 0; k < iNickSize; k++)
				{
					int iLength1 = (int)nicks[i].size() - (k + 1 + 1);
					int iLength2 = (int)nicks[i].size() - (k + 2 + 1);

					if (0 >= iLength2)
					{
						if (0 < iLength1)
						{
							if (nicks[j] == nicks[i].substr(0, k) + nicks[k].substr(k + 1, iLength1))
							{
								bSame = true;
								break;
							}
						}
						else if (nicks[j] == nicks[i].substr(0, k))
						{
							bSame = true;
							break;
						}
					}
					else if (
						nicks[j] == nicks[i].substr(0, k) + nicks[j].substr(k + 1, iLength1) ||
						nicks[j] == nicks[i].substr(0, k) + nicks[j].substr(k + 1, iLength2))
					{
						bSame = true;
						break;
					}
				}
			}
			else
			{
				int iNickSize = nicks[j].size();
				for (int k = 0; k < iNickSize; k++)
				{
					int iLength1 = (int)nicks[j].size() - (k + 1 + 1);
					int iLength2 = (int)nicks[j].size() - (k + 2 + 1);

					if (0 >= iLength2)
					{
						if (0 < iLength1)
						{
							if (nicks[i] == nicks[j].substr(0, k) + nicks[j].substr(k + 1, iLength1))
							{
								bSame = true;
								break;
							}
						}
						else if (nicks[i] == nicks[j].substr(0, k))
						{
							bSame = true;
							break;
						}
					}
					else if (
						nicks[i] == nicks[j].substr(0, k) + nicks[j].substr(k + 1, iLength1) ||
						nicks[i] == nicks[j].substr(0, k) + nicks[j].substr(k + 1, iLength2))
					{
						bSame = true;
						break;
					}
				}
			}

			if (bSame)
			{
				// 이메일이 같다면
				if (emails[i] == emails[j])
				{
					auto iter = accounts.find(i);
					if (iter != accounts.end())
					{
						accounts[i].push_back(j);
					}
					else
					{
						accounts.emplace(i, list<int>{ i, j });
					}
				}
				// 이메일 : 계정 이름이 같다면
				else if (emails[i].substr(0, emails[i].find('@')) == emails[j].substr(0, emails[j].find('@')))
				{
					auto iter = accounts.find(i);
					if (iter != accounts.end())
					{
						accounts[i].push_back(j);
					}
					else
					{
						accounts.emplace(i, list<int>{ i, j });
					}
				}
				else
				{
					for (int l = 0; l < iSize; l++)
					{
						int iLengthl = emails[i].length() - (l + 1);
						int iLengthr = emails[j].length() - (l + 1);

						// 이메일 : 계정 이름이 유사하다면
						if ((emails[j] == emails[i].substr(0, l) + emails[i].substr(l + 1, iLengthl)) || (emails[i] == emails[j].substr(0, l) + emails[j].substr(l + 1, iLengthr)))
						{
							auto iter = accounts.find(i);
							if (iter != accounts.end())
							{
								accounts[i].push_back(j);
							}
							else
							{
								accounts.emplace(i, list<int>{ i, j });
							}
							break;
						}
					}
				}
			}



			for (pair<const int, list<int>>& pair_account : accounts)
			{
				auto iter = find(pair_account.second.begin(), pair_account.second.end(), i);
				if (iter == pair_account.second.end())
				{
					auto iter2 =  accounts.find(i);
					if (iter2 == accounts.end())
						accounts.emplace(i, list<int>{i});
				}
				else
				{
					break;
				}
			}
		}
	}

	answer = static_cast<int>(accounts.size());
	return answer;
}

enum ECheck_Vane {
	CHECK_VANE_NONE,
	CHECK_VANE_FAN, // 오브젝트가 팬임
	CHECK_VANE_WEIGHT_DEC, // 가중치를 줄임
	CHECK_VANE_DONE, // 가중치가 0, 바람개비가 돌고 있는 상태
	CHECK_VANE_ALREADY_ZERO, // 가중치가 이미 0 이하
};
enum EObj {
	OBJ_EMPTY,
	OBJ_VANE,
	OBJ_VANE_START = OBJ_VANE,
	OBJ_VANE_END = 4,
	OBJ_FAN,
	OBJ_WALL,
	OBJ_END
};

// 바람개비인지 확인하고, 가중치를 줄임
ECheck_Vane Check_Vane(int _iObject, int& _iWeight, int& _iVaneCount)
{
	if (OBJ_FAN == _iObject)
	{
		return CHECK_VANE_FAN;
	}
	// 바람개비임
	else if (OBJ_VANE_START <= _iObject && _iObject <= OBJ_VANE_END)
	{
		if (0 < _iWeight)
		{
			--_iWeight;

			if (0 == _iWeight)
			{
				++_iVaneCount;
				return CHECK_VANE_DONE;
			}
			else
				return CHECK_VANE_WEIGHT_DEC;
		}
		else
			return CHECK_VANE_ALREADY_ZERO;
	}
	return CHECK_VANE_NONE;
}

int solution_5_00(vector<vector<int>> grid) {
	int answer = 0;

	enum EDir {
		DIR_UP,
		DIR_DONW,
		DIR_LEFT,
		DIR_RIGHT,
		DIR_END
	};
	typedef struct tagFan {
		tagFan(int iX = 0, int iY = 0, EDir eDir = DIR_END)
			:iX(iX)
			, iY(iY)
			, eDir(eDir)
		{}
		int iX = 0;
		int iY = 0;
		EDir eDir = DIR_UP;
	} TFan;
	vector<TFan> vFans;

	int iGridX = static_cast<int>(grid.size());
	int iGridY = static_cast<int>(grid[0].size());

	for (int i = 0; i < iGridX; i++)
	{
		for (int j = 0; j < iGridY; j++)
		{
			// 선풍기
			if (5 == grid[i][j])
			{
				vFans.push_back(TFan { i, j, DIR_UP });
			}
		}
	}

	while (true)
	{
		vector<vector<int>> grid_copy = grid;
		int iCount = 0;
		for (TFan tFan : vFans)
		{
			switch (tFan.eDir)
			{
			case DIR_UP:
			{
				for (int i = tFan.iY - 1; i >= 0; i++)
				{
					if (5 == grid[tFan.iX][i])
					{
						break;
					}
					else if (0 < grid[tFan.iX][i] && grid[tFan.iX][i] < 5)
					{
						--grid_copy[tFan.iX][i];
					}
				}
			}
			break;
			case DIR_DONW:
			{
				for (int i = tFan.iY + 1; i < iGridY; i++)
				{
					if (5 == grid[tFan.iX][i])
					{
						break;
					}
					else if (0 < grid[tFan.iX][i] && grid[tFan.iX][i] < 5)
					{
						--grid_copy[tFan.iX][i];
					}
				}
			}
			break;
			case DIR_LEFT:
			{
				for (int i = tFan.iX - 1; i >= 0; i--)
				{
					if (5 == grid[i][tFan.iY])
					{
						break;
					}
					else if (0 < grid[i][tFan.iY] && grid[i][tFan.iY] < 5)
					{
						--grid_copy[i][tFan.iY];
					}
				}
			}
			break;
			case DIR_RIGHT:
			{
				for (int i = tFan.iX + 1; i < iGridX; i++)
				{
					if (5 == grid[i][tFan.iY])
					{
						break;
					}
					else if (0 < grid[i][tFan.iY] && grid[i][tFan.iY] < 5)
					{
						--grid_copy[i][tFan.iY];
					}
				}
			}
			break;
			default:
				break;
			}
		}

		for (int i = 0; i < iGridX; i++)
		{
			for (int j = 0; j < iGridY; j++)
			{
				if (0 < grid[i][j] && grid[i][j] < 5)
				{
					if (0 >= grid_copy[i][j])
						++iCount;
				}
			}
		}

		answer = max(iCount, answer);

		bool bFinished = true;

		vFans.back().eDir = EDir(vFans.back().eDir + 1);
		if (vFans.back().eDir == DIR_END)
		{
			for (TFan tFan : vFans)
			{
				if (tFan.eDir < DIR_END - 1)
				{
					tFan.eDir = EDir(tFan.eDir + 1);
					vFans.back().eDir = DIR_UP;
					bFinished = false;
					break;
				}
			}
		}
		if (bFinished)
			break;
	}

	cout << answer << '\n';
	return answer;
}
int solution_5(vector<vector<int>> grid) {
	int answer = 0;

	enum EDir {
		DIR_UP,
		DIR_DOWN,
		DIR_LEFT,
		DIR_RIGHT,
		DIR_END
	};

	typedef struct tagFan {
		tagFan(int iX = 0, int iY = 0, EDir eDir = DIR_END)
			:iX(iX), iY(iY), eDir(eDir)
		{}
		int iX = 0;
		int iY = 0;
		EDir eDir = DIR_END;
	} TFan;

	int iGrid_X_Size = static_cast<int>(grid[0].size());
	int iGrid_Y_Size = static_cast<int>(grid.size());
	list<TFan> Fans;

	// 선풍기 찾고, 리스트에 넣기
	for (int iY = 0; iY < iGrid_Y_Size; iY++)
	{
		for (int iX = 0; iX < iGrid_X_Size; iX++)
		{
			if (5 == grid[iY][iX])
			{
				Fans.push_back(TFan { iX, iY, DIR_UP });
			}
		}
	}

	while (true)
	{
		// 가중치를 저장 -> 바람개비 개수를 찾기 위해
		vector<vector<int>> grid_copy = grid;
		int iVaneCount = 0;

		// 움직이는 바람개비 개수를 구함
		for (const TFan& tFan : Fans)
		{
			switch (tFan.eDir)
			{
			case DIR_UP:
			{
				for (int iY = tFan.iY - 1; iY >= 0; iY--)
				{
					if (CHECK_VANE_FAN == Check_Vane(grid[iY][tFan.iX], grid_copy[iY][tFan.iX], iVaneCount))
						break;
				}
			}
			break;
			case DIR_DOWN:
			{
				for (int iY = tFan.iY + 1; iY < iGrid_Y_Size; iY++)
				{
					if (CHECK_VANE_FAN == Check_Vane(grid[iY][tFan.iX], grid_copy[iY][tFan.iX], iVaneCount))
						break;
				}
			}
			break;
			case DIR_LEFT:
			{
				for (int iX = tFan.iX + 1; iX < iGrid_X_Size; iX++)
				{
					if (CHECK_VANE_FAN == Check_Vane(grid[tFan.iY][iX], grid_copy[tFan.iY][iX], iVaneCount))
						break;
				}
			}
			break;
			case DIR_RIGHT:
			{
				for (int iX = tFan.iX - 1; iX >= 0; iX--)
				{
					if (CHECK_VANE_FAN == Check_Vane(grid[tFan.iY][iX], grid_copy[tFan.iY][iX], iVaneCount))
						break;
				}
			}
			break;
			default:
				break;
			}
		}

		answer = max(iVaneCount, answer);

		TFan& tFirstFan = Fans.front();
		tFirstFan.eDir = EDir(tFirstFan.eDir + 1);
		if (tFirstFan.eDir == DIR_END)
		{
			for (auto iter = ++Fans.begin(); iter != Fans.end(); iter++)
			{
				(*iter).eDir = EDir((*iter).eDir + 1);
				if ((*iter).eDir == DIR_END)
				{
					++iter;
					(*iter).eDir = EDir((*iter).eDir + 1);
				}
			}
		}





















		bool bFinished = true;

		TFan& tFirstFan = Fans.front();

		if (tFirstFan.eDir == EDir(DIR_END - 1))
		{
			for (TFan& tFan : Fans)
			{
				if (tFan.eDir < DIR_END - 1)
				{
					tFan.eDir = EDir(tFan.eDir + 1);
					tFirstFan.eDir = DIR_UP;
					bFinished = false;
					break;
				}
			}
		}
		else
		{
			tFirstFan.eDir = EDir(tFirstFan.eDir + 1);
			bFinished = false;
		}
		if (bFinished)
			break;
	}

	return answer;
}
int main() {
	cout << "===== " << _PROBLEM_NUMBER << " =====" << '\n';

	//MAppend_Function(Solution_, _PROBLEM_NUMBER);

	vector<string> logs1
	{
		"team_name : db application_name : dbtest error_level : info message : test",
		"team_name : test application_name : I DONT CARE error_level : error message : x",
		"team_name : ThisIsJustForTest application_name : TestAndTestAndTestAndTest error_level : test message : IAlwaysTestingAndIWillTestForever",
		"team_name : oberervability application_name : LogViewer error_level : error"
	};

	vector<string> logs2
	{
		"team_name : MyTeam application_name : YourApp error_level : info messag : IndexOutOfRange", "no such file or directory",
		"team_name : recommend application_name : recommend error_level : info message : RecommendSucces11",
		"team_name : recommend application_name : recommend error_level : info message : Success!",
		"team_name : db application_name : dbtest error_level : info message : test",
		"team_name     : db application_name : dbtest error_level : info message : test", "team_name : TeamTest application_name : TestApplication error_level : info message : ThereIsNoError"
	};

	vector<vector<int>> grid1
	{
		{ 1, 6, 1, 5, 0, 0, 1 },
		{ 0, 6, 6, 2, 6, 6, 0 },
		{ 0, 6, 6, 0, 6, 6, 1 },
		{ 5, 0, 2, 4, 2, 0, 5 },
		{ 2, 6, 6, 0, 6, 6, 6 },
		{ 3, 0, 0, 5, 6, 6, 6 },
		{ 2, 6, 6, 6, 6, 6, 6 },
		{ 5, 1, 6, 6, 6, 6, 6 }
	};

	vector<vector<int>> grid2
	{
		{ 6, 6, 5, 1, 0 },
		{ 6, 6, 2, 6, 1 },
		{ 5, 2, 4, 2, 5 },
		{ 1, 6, 2, 6, 6 },
		{ 0, 1, 5, 6, 6 },
	};

	vector<vector<int>> grid3
	{
		{ 6, 6, 5, 1, 2 },
		{ 6, 6, 2, 6, 1 },
		{ 5, 2, 4, 2, 5 },
		{ 1, 6, 2, 6, 6 },
		{ 2, 1, 5, 6, 6 },
	};

	//cout << "Solution 5 - Grid : " << solution_5(grid1) << '\n';
	cout << "Solution 5 - Grid : " << solution_5(grid2) << '\n';
	cout << "Solution 5 - Grid : " << solution_5(grid3) << '\n';

	system("pause");

	return 0;
}
