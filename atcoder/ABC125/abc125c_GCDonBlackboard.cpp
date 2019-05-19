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

/*int n;

//aとbの最大公約数を返す
int gcd(ll a, ll b) {
	//aの方が大きくなるよう入れ替え
	if (a < b) swap(a, b);

	int r;
	//ユークリッドの互除法
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}

	return b;
}

//O(n^2)のためTLEになる
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	vector<ll> a(n);
	FOR(i, 0, n) cin >> a[i];

	//cout << gcd(a[2], a[1]) << endl;

	//aから1つ抜いて最大公約数求める
	int max1 = 0;
	FOR(tgt, 0, n) {
		int ans;
		if (tgt == 0) ans = a[1];
		else ans = a[0];

		//aの最大、最小値求める
		//抜いた数が最大or最小値なら消して再計算
		int amax = *max_element(a.begin(), a.end());
		if (amax == a[tgt]) {
			vector<ll> tmp1 = a;
			tmp1.erase(tmp1.begin() + tgt);
			amax = *max_element(tmp1.begin(), tmp1.end());
		}
		else amax = *max_element(a.begin(), a.end());

		int amin = *min_element(a.begin(), a.end());
		if (amin == a[tgt]) {
			vector<ll> tmp2 = a;
			tmp2.erase(tmp2.begin() + tgt);
			amin = *min_element(tmp2.begin(), tmp2.end());
		}

		ans = gcd(amax, amin);
		
		FOR(i, 1, n) {
			if (i == tgt) continue;
			ans = gcd(ans, a[i]);
		}
		cout << ans << endl;
		max1 = max(max1, ans);
	}
	cout << "max:" << max1 << endl;
}*/