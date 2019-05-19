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

/*int n, k;
string s;
vector<int> nums01;


int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	cin >> s;

	//先頭、末尾"0"なら0を入れる(両端を1の個数にするため)
	if (s[0] == '0') nums01.push_back(0);
	for (int i = 0; i < s.size();) {
		
		int end_i = i;
		//cout << end_i << endl;
		//s[i]と同じ数字が何個つづくか
		while (end_i < s.size() && s[end_i] == s[i]) end_i++;
		nums01.push_back(end_i - i);
		i = end_i;

	}
	if (s.back() == '0') nums01.push_back(0);

	//nums01: 0,2,4...に1の連続数、1,3,5...に0の連続数を格納
	cout << "nums01:" << endl;
	FOR(i, 0, nums01.size()) cout << nums01[i] << endl;

	//累積和: sums[0]は0
	vector<int> sums(nums01.size()+1, 0);
	FOR(i, 0, nums01.size()) sums[i+1] = sums[i] + nums01[i];

	cout << "sums:" << endl;
	FOR(i, 0, sums.size()) cout << sums[i] << endl;

	cout << "res:" << endl;
	//nums01の2k+1個以下の要素の合計値計算
	int res = 0;
	for (int left = 0; left < sums.size(); left += 2) {
		int right = left + 2 * k + 1;
		if (right >= sums.size()) right = sums.size() - 1;

		//cout << left << ", " << right << endl;		
		//cout << sums[right] - sums[left] << endl;
		res = max(res, sums[right] - sums[left]);
	}
	cout << res << endl;

}*/