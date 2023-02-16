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

#include "Function.h"

#define MCout_Bool(x) (x) ? std::cout << "TRUE "<< endl : std::cout << "FALSE" << endl;
#define MCout_Endl std::cout << '\n';

#define	MToStr_Pre(str) # str
#define MToStr(str) MToStr_Pre(str)

#define MAppend(x, y) x ## y
#define MAppend_Function(x, y) MAppend(x, y)()

#define MMin(x, y) ((x) < (y)) ? x : y
#define MMax(x, y) ((x) > (y)) ? x : y
