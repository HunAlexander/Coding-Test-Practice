#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

/*

22-11-23
https://school.programmers.co.kr/learn/challenges?order=recent&levels=1&languages=cpp
과일 장수

*/

int solution(int k, int m, vector<int> score) {
	int answer = 0;

	sort(score.begin(), score.end(), greater<int>());

	/* 정렬 됐는지 확인 */
	for (auto iNum : score)
	{
		cout << iNum << " ";
	}
	cout << endl;

	for (int i = m; i < score.size(); i += m)
	{
		answer += score.at(i - 1) * m;
		cout << answer << endl;
	}

	return answer;
}

int main()
{
	vector<int> v { 4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2 };

	cout << solution(4, 3, v) << endl;

	system("pause");

	return 0;
}