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

/*int n_piece, n_x;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n_piece >> n_x;

	if (n_piece >= n_x) {
		cout << 0 << endl;
		exit(0);
	}

	vector<int> xs(n_x);
	FOR(i, 0, n_x) {
		cin >> xs[i];
	}
	sort(xs.begin(), xs.end());

	cout << "xs:" << endl;
	FOR(i, 0, n_x) cout << xs[i] << endl;
	cout << endl;

	vector<int> dxs(n_x-1);
	FOR(i, 0, n_x - 1) {
		dxs[i] = xs[i + 1] - xs[i];
	}
	sort(dxs.begin(), dxs.end(), greater<int>());

	cout << "dxs:" << endl;
	FOR(i, 0, n_x-1) cout << dxs[i] << endl;
	cout << endl;

	//ans = x[M-1] - x[0] - max(2“_ŠÔ‹——£)
	int ans = xs.back() - xs[0];
	FOR(i, 0, n_piece - 1) {
		ans -= dxs[i];
	}
	cout << ans << endl;
}*/