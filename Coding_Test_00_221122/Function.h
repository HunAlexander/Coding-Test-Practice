#pragma once

int Factorial_Iter(int _iNumber)
{
	int iRet = 1;
	while (_iNumber)
		iRet *= _iNumber--;
	return iRet;
}

template <typename T>
void Print_Container_Elements_To_Console(const T& Container)
{
	std::cout << "Elements : ";
	for (const auto& element : Container)
		std::cout << element << " ";
	std::cout << '\n';
}
template <typename T>
void Print_Container_Size_To_Console(const T& Container)
{
	std::cout << "Size : " << Container.size() << '\n';
}
template <typename T>
void Print_Container_Info_To_Console(const T& Container)
{
	std::cout << "==========" << '\n';
	Print_Container_Size_To_Console(Container);
	Print_Container_Elements_To_Console(Container);
	std::cout << "==========" << '\n';
}
template <typename T>
void Print_Container_Info_To_Console(const std::vector<T>& Container)
{
	std::cout << "==========" << '\n';
	Print_Container_Size_To_Console(Container);
	std::cout << "Capacity : " << Container.capacity() << '\n';
	Print_Container_Elements_To_Console(Container);
	std::cout << "==========" << '\n';
}