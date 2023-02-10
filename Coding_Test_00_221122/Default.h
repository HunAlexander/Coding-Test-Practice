#pragma once

#include <vector>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

#define MCout_Bool(x) (x) ? std::cout << "TRUE "<< endl : std::cout << "FALSE" << endl;
#define MCout_Endl std::cout << '\n';

#define	MToStr_Pre(str) # str
#define MToStr(str) MToStr_Pre(str)

#define MAppend(x, y) x ## y
#define MAppend_Function(x, y) MAppend(x, y)()

#define MMin(x, y) ((x) < (y)) ? x : y
#define MMax(x, y) ((x) > (y)) ? x : y

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