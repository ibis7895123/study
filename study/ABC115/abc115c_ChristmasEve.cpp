#include "pch.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)
typedef long long ll;
/*const int INF = 1<<30;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> h(n);
	FOR(i, 0, n) cin >> h[i];
	sort(h.begin(), h.end());

	cout << "h:" << endl;
	FOR(i, 0, n) cout << h[i] << endl;
	cout << endl;

	//h[i+k] - h[i]‚ÌÅ‘å’l‚ª“š‚¦
	int min1 = INF;
	FOR(i, 0, n - k + 1) {
		int tmp = h[i + k - 1] - h[i];
		cout << "tmp: " << tmp << endl;
		min1 = min(min1, tmp);
	}
	cout << min1 << endl;

}*/