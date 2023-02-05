#pragma once

#include <vector>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

#define _COUT_BOOL(x) (x) ? std::cout << "TRUE "<< endl : std::cout << "FALSE" << endl;

#define _STR(str) # str

#define _APPEND(x, y) x ## y
#define _APPEND_FUNC(x, y) _APPEND(x, y)()

#define _MIN(x, y) ((x) < (y)) ? x : y
#define _MAX(x, y) ((x) > (y)) ? x : y

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