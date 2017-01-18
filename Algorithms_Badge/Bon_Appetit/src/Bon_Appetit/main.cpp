#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n, k, paid, sum = 0;
	cin >> n >> k;
	vector<int> prices(n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		prices[i] = temp;
	}
	cin >> paid;

	for(int i = 0; i < prices.size(); i++)
	{
		if (i != k)
			sum += prices[i];
	}

	if ((sum/2) == paid)
		cout << "Bon Appetit" << endl;
	else
		cout << paid - (sum/2)<< endl;


	return 0;
}
