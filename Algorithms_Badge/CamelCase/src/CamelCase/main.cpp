#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
	string s;
	int words = 0;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if(i == 0)
		{
			if (islower(s[i]))
				words++;
		}
		else
		{
			if (isupper(s[i]))
				words++;
		}
	}

	cout << words << endl;
	return 0;
}
