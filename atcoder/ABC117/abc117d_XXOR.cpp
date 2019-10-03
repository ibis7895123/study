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
//dp[�ォ��i���܂�][smaller]
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
		//mask��2^(dmax - d - 1)������ d:0~49�ɑ΂���mask:0~�̂���1����
		//mask: d���ڂ�1�Ŏc��0�̐�(10�i��)
		ll mask = 1LL << (dmax - d - 1);
		cout << "mask:" << mask << endl;

		//A�Ō��Xd���ڂɃr�b�g�������Ă���(d���ڂ�1)���̂̌�
		//&: �r�b�g���Z(2�i���ɕϊ����Čv�Z)
		int num = 0;
		FOR(i, 0, n) if (a[i] & mask) num++;
		cout << "num:" << num << endl;

		//x��d���ڂ�0,1�ɂ������̃R�X�g
		ll cost0 = mask * num;
		ll cost1 = mask * (n - num);
		cout << "cost0:" << cost0 << endl;
		cout << "cost1:" << cost1 << endl;

		//dp[ i ][ smaller ] -> dp [ i+1 ][ smaller ]�ւ̑J��
		
		//1. smaller -> smaller
		//0�ł�1�ł����݂ɑ傫�����I��
		if (dp[d][1] != -1) {
			chmax(dp[d + 1][1], dp[d][1] + max(cost0, cost1));
		}

		//2. exact -> smaller
		if (dp[d][0] != -1) {
			if (k & mask) { //k��d���ڂ�1�Ȃ�Ax��d���ڂ�0�ɂ���
				chmax(dp[d + 1][1], dp[d][0] + cost0);
			}
		}

		//3. exact -> exact
		//k�ɂ҂����荇�킹��
		if (dp[d][0] != -1) {
			if (k & mask) chmax(dp[d + 1][0], dp[d][0] + cost1); //k��d���ڂ�1
			else chmax(dp[d + 1][0], dp[d][0] + cost0); //k��d���ڂ�0
		}
		
	}

	cout << max(dp[dmax][0], dp[dmax][1]) << endl;

}