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
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


int n;
ll k;
const int dmax = 50;
//dp[上からi桁まで][smaller]
vector<vector<ll>> dp(100, vector<ll>(2, -1));

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	vector<ll> a(n);

	cout << "a:" << endl;
	FOR(i, 0, n) {
		cin >> a[i];
		cout << a[i] << endl;
	}

	dp[0][0] = 0;
	
	FOR(d, 0, dmax) {
		cout << "---" << d << "---" << endl;
		//maskは2^(dmax - d - 1)が入る d:0~49に対してmask:0~のため1引く
		//mask: d桁目が1で残り0の数(10進数)
		ll mask = 1LL << (dmax - d - 1);
		cout << "mask:" << mask << endl;

		//Aで元々d桁目にビットが立っている(d桁目が1)ものの個数
		//&: ビット演算(2進数に変換して計算)
		int num = 0;
		FOR(i, 0, n) if (a[i] & mask) num++;
		cout << "num:" << num << endl;

		//xのd桁目を0,1にした時のコスト
		ll cost0 = mask * num;
		ll cost1 = mask * (n - num);
		cout << "cost0:" << cost0 << endl;
		cout << "cost1:" << cost1 << endl;

		//dp[ i ][ smaller ] -> dp [ i+1 ][ smaller ]への遷移
		
		//1. smaller -> smaller
		//0でも1でも自在に大きい方選ぶ
		if (dp[d][1] != -1) {
			chmax(dp[d + 1][1], dp[d][1] + max(cost0, cost1));
		}

		//2. exact -> smaller
		if (dp[d][0] != -1) {
			if (k & mask) { //kのd桁目が1なら、xのd桁目は0にする
				chmax(dp[d + 1][1], dp[d][0] + cost0);
			}
		}

		//3. exact -> exact
		//kにぴったり合わせる
		if (dp[d][0] != -1) {
			if (k & mask) chmax(dp[d + 1][0], dp[d][0] + cost1); //kのd桁目が1
			else chmax(dp[d + 1][0], dp[d][0] + cost0); //kのd桁目が0
		}
		
	}

	cout << max(dp[dmax][0], dp[dmax][1]) << endl;

}