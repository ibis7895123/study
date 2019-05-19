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
	
	//b == 0ならaを返す
	if (b == 0) return a;

	//終了条件
	if (a % b == 0) return b;

	return gcd(b, a%b);
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	vector<ll> a(n);
	FOR(i, 0, n) cin >> a[i];

	//cout << gcd(a[2], a[1]) << endl;

	//累積和計算
	//左累積和L
	vector<ll> L(n+1,0);
	FOR(i, 0, n) {
		L[i + 1] = gcd(L[i], a[i]);
	}

	cout << "L:" << endl;
	FOR(i, 0, n+1) cout << L[i] << endl;
	cout << endl;

	//右累積和R
	vector<ll> R(n + 1, 0);
	REF(i, n-1, -1) {
		R[i] = gcd(R[i + 1], a[i]);
	}

	cout << "R:" << endl;
	FOR(i, 0, n + 1) cout << R[i] << endl;
	cout << endl;

	//aからa[i]を抜いたgcdを計算、最大値を更新
	//ans = gcd(L[i], R[i+1])
	ll max1 = 0;
	FOR(i, 0, n) {
		ll ans = gcd(L[i], R[i + 1]);
		cout << "ans:" << ans << endl;
		max1 = max(max1, ans);
	}
	cout << max1 << endl;
}*/