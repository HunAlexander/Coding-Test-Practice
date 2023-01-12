#include "Default.h"

int solution(vector<int> cards) {
	int iSize = cards.size();
	vector<set<int>> vGroups;

	for (int i = 0; i < iSize; ++i)
	{
		set<int> setGroup;

		if (false == vGroups.empty())
		{
			bool bDupl = false;
			for (auto Group : vGroups)
			{
				if (Group.end() != Group.find(i + 1))
				{
					bDupl = true;
					break;
				}
			}

			if (true == bDupl)
				continue;
		}

		int iIndex = cards[i] - 1;
		setGroup.emplace(iIndex + 1);
		while (true)
		{
			iIndex = cards[iIndex] - 1;
			if (false == setGroup.emplace(iIndex + 1).second)
			{
				vGroups.push_back(setGroup);
				break;
			}
		}
	}

	if (1 >= vGroups.size())
		return 0;

	int iBoxA = 0, iBoxB = 0;

	for (auto iter = vGroups.begin(); iter != vGroups.end(); ++iter)
	{
		if (iBoxA < int((*iter).size()))
		{
			iBoxB = iBoxA;
			iBoxA = int((*iter).size());
		}
		else if(iBoxB < int((*iter).size()))
		{
			iBoxB = int((*iter).size());
		}
	}

	return  iBoxA * iBoxB;
}

int main()
{
	cout << solution(vector<int>{8, 6, 3, 7, 2, 5, 1, 4}) << endl;

	system("pause");

	return 0;
}