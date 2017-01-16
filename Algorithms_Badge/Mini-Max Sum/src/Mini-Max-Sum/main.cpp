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
	long int a;
	long int b;
	long int c;
	long int d;
	long int e;
	long int largest;
	long int smallest;
	long int temp;
	cin >> a >> b >> c >> d >> e;
	largest = b + c + d + e;					//Keep a away
	smallest = largest;
	
	temp = a + c + d + e;						//Keep b away
	if (temp > largest)
		largest = temp;
	else if (temp < smallest)
		smallest = temp;

	temp = a + b + d + e;						//Keep c away
	if (temp > largest)
		largest = temp;
	else if (temp < smallest)
		smallest = temp;

	temp = a + c + b + e;						//Keep d away
	if (temp > largest)
		largest = temp;
	else if (temp < smallest)
		smallest = temp;

	temp = a + c + d + b;						//Keep e away
	if (temp > largest)
		largest = temp;
	else if (temp < smallest)
		smallest = temp;



	cout << smallest << " " << largest << endl;
	return 0;
}
