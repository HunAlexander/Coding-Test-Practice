#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/*

22-11-23
https://school.programmers.co.kr/learn/challenges?order=recent&levels=1&languages=cpp
푸드 파이트 대회

*/

string solution(vector<int> food) {
	string answer = "";
	string temp = "";

	int iSize = food.size();

	for (int i = 1; i < iSize; ++i)
	{
		int iFoodCount = i / 2;

		for (int j = 0; j < iFoodCount; ++j)
		{
			answer.append(to_string(food[i]));
		}
	}

	temp = answer;

	reverse(temp.begin(), temp.end());

	answer.append("0");
	answer.append(temp);

	return answer;
}

int main()
{
	vector<int> v { 4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2 };

	//to_string()
	v.front();


	system("pause");

	return 0;
}