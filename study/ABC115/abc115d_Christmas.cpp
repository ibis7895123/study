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

/*vector<ll> a(100);
vector<ll> p(100);

ll burger(ll L, ll x) {
	//終了条件
	if (L == 0) {
		if (x <= 0) return 0;
		else return 1;
	}

	if (x == 1) return 0;
	
	else if (1 < x && x < 2 + a[L - 1]) return burger(L - 1, x - 1);

	else if (x == 2 + a[L - 1]) return p[L - 1] + 1;

	else if (2 + a[L - 1] < x && x < 3 + 2 * a[L - 1]) return p[L - 1] + 1 + burger(L - 1, x - (2 + a[L - 1]));

	else if (x == 3 + 2 * a[L - 1]) return 2 * p[L - 1] + 1;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, x;
	cin >> n >> x;

	//バーガー長さ
	a[0] = 1;
	FOR(i, 0, n - 1) a[i + 1] = 2 * a[i] + 3;
	
	//cout << "a:" << endl;
	//FOR(i, 0, n) cout << a[i] << endl;
	//cout << endl;

	//パティ数
	p[0] = 1;
	FOR(i, 0, n - 1) p[i + 1] = 2 * p[i] + 1;

	//cout << "p:" << endl;
	//FOR(i, 0, n) cout << p[i] << endl;
	//cout << endl;

	cout << burger(n, x) << endl;
}*/