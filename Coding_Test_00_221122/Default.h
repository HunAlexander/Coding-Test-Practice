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