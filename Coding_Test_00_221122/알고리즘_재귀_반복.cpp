#include "Default.h"

int Factorial_R(int n)
{
	if (n <= 1)
		return 1;

	return n * Factorial_R(n - 1);
}

int Factorial_L(int n)
{
	int answer = 1;

	for (int i = 2; i <= n; ++i)
	{
		answer  *= i;
	}

	return answer;
}

int FibonacciNumbers_R(int n)
{
	if (n < 3)
		return 1;

	return FibonacciNumbers_R(n - 1) + FibonacciNumbers_R(n - 2);
}

int FibonacciNumbers_L(int n)
{
	int answer = 1;
	int pre = 1, temp = 0;

	for (int i = 2; i < n; ++i)
	{
		temp = answer;
		answer = pre + answer;
		pre = temp;
	}

	return answer;
}

// 1 1 2 3 5 8
int main()
{
	cout << "===== Factorial =====" << endl;
	for (int i = 1; i <= 5; ++i)
	{
		cout << Factorial_R(i) << endl;
		cout << Factorial_L(i) << endl;
	}

	cout << "===== Fibonacci Numbers =====" << endl;
	for (int i = 1; i <= 10; ++i)
	{
		cout << i << " : " << FibonacciNumbers_R(i) << endl;
		cout << i << " : " << FibonacciNumbers_L(i) << endl;
	}
	
	system("pause");

	return 0;
}