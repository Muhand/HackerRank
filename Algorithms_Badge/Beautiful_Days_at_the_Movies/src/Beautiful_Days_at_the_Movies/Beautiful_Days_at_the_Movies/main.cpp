#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Prototypes
int reverse(int input);

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	test:
	int i, j, k, btf_Days= 0;
	cin >> i >> j >> k;
	if (i < 1 || j < i || k < 1)
	{
		cout << "Error, make sure i > j and i > 1 and k > 1";
		goto exit;
	}

	for (int ct = i; ct <= j; ct++)
	{
		if (abs(ct - reverse(ct)) % k == 0)
			btf_Days++;
	}


	cout << btf_Days << endl;
	exit:
	return 0;
}

int reverse(int input)
{
	int output = 0, remainder;

	while (input != 0)
	{
		remainder = input % 10;
		output = output * 10 + remainder;
		input /= 10;
	}

	return output;
}