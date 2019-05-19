#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)


int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b, k;
	cin >> a >> b >> k;
	//cout << a << ", " << b << ", " << k <<"\n";

	int end = min(a, b);
	//cout << end << "\n";

	int count = 0;
	REF(num, end, 0) {
		//cout << "\n";
		//cout << num <<", ";

		if (a % num == 0 && b % num == 0) {
			count++;
			//cout << num << ", ";
			if (count == k) {
				cout << num;
				return 0;
			}
		}


	}

}