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
	int n;
	map<int, int> largest;
	cin >> n;
	vector<int> height(n);
	for (int height_i = 0; height_i < n; height_i++) {
		int t;
		cin >> t;

		height[height_i] = t;
		if (largest[t] == false)
		{
			largest[t] = 1;
			//cout << "notfound" << endl;
		}
		else
		{
			int inc = largest[t];
			inc++;
			largest[t] = inc;
		}
	}

	int lar = -1;
	for (auto const &ent1 : largest) {
		//cout << "Key: " << ent1.first << "\t\tValue: " << ent1.second << endl;
		if (ent1.second > lar)
			lar = ent1.second;
	}

	cout << lar << endl;
	return 0;
}
