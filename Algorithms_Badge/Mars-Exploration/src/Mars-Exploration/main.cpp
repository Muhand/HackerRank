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
	string S;
	string sos = "SOS";
	cin >> S;
	int errors = 0;

	if (S.length() % 3 != 0 || S.length() < 1 || S.length() > 99)
		goto exit;

	for (int i = 0; i < S.length(); i++)
	{
		if (!isupper(S[i]))
			goto exit;

		if (S[i] != sos[i%3])
			errors++;
	}

	cout << errors << endl;

	exit:
	return 0;
}
