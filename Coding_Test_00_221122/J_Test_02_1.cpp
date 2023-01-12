#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ¹®Á¦ 2

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