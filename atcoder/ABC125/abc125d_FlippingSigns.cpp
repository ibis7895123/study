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

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<ll> a(n);
	int countMinus = 0;
	FOR(i, 0, n) {
		cin >> a[i];
		//マイナスの数数える
		if (a[i] < 0) countMinus++;
	}

	//aの絶対値和を計算
	ll sum1 = 0;
	FOR(i, 0, n) sum1 += abs(a[i]);
	cout << "sum:" << sum1 << endl;

	cout << "count[-] :" << countMinus << endl;
	//マイナスの数が偶数なら
	//ans = sum1
	if (countMinus % 2 == 0) cout << sum1 << endl;
	
	//マイナスの数が奇数なら
	//ans = sum1 - 2*min(a[i]の絶対値)
	//2倍してるのはsum1の中にmin(a[i]の絶対値)が含まれてるため
	else {
		//min(a[i]の絶対値)計算
		ll min_a = 1LL<<30;
		FOR(i, 0, n) min_a = min(min_a, abs(a[i]));
		cout << "min_a:" << min_a << endl;
		
		cout << sum1 - 2*min_a << endl;
	}
}