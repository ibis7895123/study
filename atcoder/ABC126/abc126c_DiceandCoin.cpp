#include "pch.h"
#include <iostream>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)
typedef long long ll;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	double k;
	//n = 100000;
	//k = 5;
	cin >> n >> k;

	double sum = 0.0;
	FOR(i, 1, n+1) {

		//2^digit>k/i‚Æ‚È‚édigit‹‚ß‚é
		double tmp = k / i;
		int digit = 0;
		while (tmp > 1) {
			tmp /= 2;
			digit++;
		}
		cout << digit << endl;

		//o–Ú‚ªi‚ÌŽž‚ÌŠm—¦ŒvŽZ
		double ans = pow(0.5, digit) / n;
		cout << "ans: " << ans << endl;
		sum += ans;

	}
	cout << setprecision(15) << sum << endl;
}