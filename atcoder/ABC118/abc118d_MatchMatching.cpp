#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)
typedef long long ll;
static const int INF = 999999999;


static const vector<int> numToMatch({ 2,5,5,4,5,6,3,7,6 });
int n_match, n_num;



int match(int num) {
	return numToMatch[num - 1];
}

void calMaxDigit(vector<int>& dp, vector<int> nums) {
	
	FOR(i, 1, n_match+1) {
		for (int num : nums) {

			int iMinusMatchNum = i - match(num);
			if (iMinusMatchNum >= 0) dp[i] = max(dp[i], dp[iMinusMatchNum] + 1);

		}
	}

}

string calNums(vector<int> dp, vector<int> nums, string ans) {
	int tmp_n = n_match;
	//大きい順にソート
	sort(nums.begin(), nums.end(), greater<int>());
	
	while (tmp_n > 0) {
		
		for (int num : nums) {
			int tmp_i = tmp_n - match(num);
			if (tmp_i >= 0 && dp[tmp_i] == dp[tmp_n] - 1) {
				ans += to_string(num);
				tmp_n -= match(num);
				break;
			}
		}

	}
	return ans;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	
	cin >> n_match >> n_num;

	vector<int> nums(n_num);
	FOR(i, 0, n_num) cin >> nums[i];

	vector<int> dp(n_match + 1, -INF);
	dp[0] = 0;

	//最大桁数計算
	calMaxDigit(dp, nums);
	cout << "dp:" << endl;
	FOR(i, 0, n_match+1) cout << dp[i] << endl;
	

	//各桁の数値計算
	string ans;
	ans = calNums(dp, nums, ans);
	cout << "ans:" << ans << endl;
}