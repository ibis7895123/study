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
const ll INF = 1LL << 40;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<ll> a(n);
	FOR(i, 0, n) cin >> a[i];

	//dp[i][flip]: a[i-1]をflip(1:反転、0:反転しない)させたときのa(0 ~ i-1)の和の最大値
	vector<vector<ll>> dp(n+1, vector<ll>(2, -INF));
	dp[0][0] = 0;

	FOR(i, 0, n) {
		//a[i-1]の反転とa[i]の反転の組み合わせでa[i]の符号が決まる

		//a[i]を反転させない場合
		chmax(dp[i + 1][0], dp[i][0] + a[i]);
		chmax(dp[i + 1][0], dp[i][1] - a[i]);

		//a[i]を反転させる場合
		chmax(dp[i + 1][1], dp[i][0] - a[i]);
		chmax(dp[i + 1][1], dp[i][1] + a[i]);
	}
	
	cout << "dp:" << endl;
	FOR(i, 0, n+1) cout << dp[i][0] << "," << dp[i][1] << endl;
	cout << endl;

}