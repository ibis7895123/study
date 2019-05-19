#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)
typedef long long ll;
/*static const string MinusINF = "-";


static const vector<int> vecMatch({ 2,5,5,4,5,6,3,7,6 });
int n_match, n_num;

int match(int num) {
	return vecMatch[num - 1];
}

void chmax(string& a, string b) {
	
	if (a == MinusINF) a = b;
	else if (a.size() < b.size()) a = b;
	else if (a.size() == b.size()) {
		if (a < b) a = b;
	}
	
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> n_match >> n_num;

	vector<int> nums(n_num);
	FOR(i, 0, n_num) cin >> nums[i];

	string dp[10010];
	FOR(i, 0, n_match) dp[i] = MinusINF;
	dp[0] = "";

	FOR(i, 0, n_match) {
		if (dp[i] == MinusINF) continue;
		for (int num : nums) chmax(dp[i + match(num)], dp[i] + (char)('0' + num));
	}

	cout << "dp:" << endl;
	FOR(i, 0, n_match+1) cout << dp[i] << endl;
	
}*/