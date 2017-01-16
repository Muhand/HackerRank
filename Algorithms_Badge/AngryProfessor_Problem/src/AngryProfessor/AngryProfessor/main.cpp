#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	vector<string> res(t);

	for (int a0 = 0; a0 < t; a0++) {
		int n;										//Total number of students
		int k;										//Absent threshold
		int att=0, abs =0;							//Attended and absent students
		bool canc = false;							//Cancel the class or no
		cin >> n >> k;								//Input
		vector<int> a(n);							//Create a vector

		for (int a_i = 0;a_i < n;a_i++) {
			cin >> a[a_i];
			if (a[a_i] <= 0)
				att++;
			else
				abs++;

			if (att < k)
			{
				canc = true;
			}
			else
				canc = false;
		}

		if (canc)
			res[a0] = "YES";
		else
			res[a0] = "NO";
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

	return 0;
}