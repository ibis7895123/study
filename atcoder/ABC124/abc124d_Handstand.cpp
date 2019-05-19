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

	//�擪�A����"0"�Ȃ�0������(���[��1�̌��ɂ��邽��)
	if (s[0] == '0') nums01.push_back(0);
	for (int i = 0; i < s.size();) {
		
		int end_i = i;
		//cout << end_i << endl;
		//s[i]�Ɠ������������Â���
		while (end_i < s.size() && s[end_i] == s[i]) end_i++;
		nums01.push_back(end_i - i);
		i = end_i;

	}
	if (s.back() == '0') nums01.push_back(0);

	//nums01: 0,2,4...��1�̘A�����A1,3,5...��0�̘A�������i�[
	cout << "nums01:" << endl;
	FOR(i, 0, nums01.size()) cout << nums01[i] << endl;

	//�ݐϘa: sums[0]��0
	vector<int> sums(nums01.size()+1, 0);
	FOR(i, 0, nums01.size()) sums[i+1] = sums[i] + nums01[i];

	cout << "sums:" << endl;
	FOR(i, 0, sums.size()) cout << sums[i] << endl;

	cout << "res:" << endl;
	//nums01��2k+1�ȉ��̗v�f�̍��v�l�v�Z
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