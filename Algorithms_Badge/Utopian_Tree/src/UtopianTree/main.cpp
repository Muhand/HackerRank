#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;
	cin >> t;
	vector<int> res;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		cin >> n;
		int height = 1;
		for(int i =1; i <= n; i++)
		{
			if (i % 2 == 0)
				height += 1;
			else
				height *= 2;
		}
		res.push_back(height);

	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

	return 0;
}
