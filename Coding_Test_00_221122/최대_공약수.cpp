#include "Default.h"

int GCD(int _iA, int _iB)
{
	int iA = max(_iA, _iB);
	int iB = min(_iA, _iB);

	if (0 == iB)
		return iA;

	return GCD(iB, iA % iB);
}

int main()
{
	cout << GCD(12, 18) << endl;

	system("pause");

	return 0;
}