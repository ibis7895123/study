#include "pch.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)
typedef long long ll;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> p(m), y(m);
	FOR(i, 0, m) {
		cin >> p[i] >> y[i];
		p[i]--;
	}

	cout << "p:" << endl;
	FOR(i, 0, m) cout << p[i] << endl;
	cout << endl;

	cout << "y:" << endl;
	FOR(i, 0, m) cout << y[i] << endl;
	cout << endl;

	vector<vector<int>> vals(n);
	FOR(i, 0, m) vals[p[i]].push_back(y[i]);

	cout << "vals:" << endl;
	FOR(v, 0, n) {
		FOR(j,0,vals[v].size()) cout << vals[v][j] << ", ";
		cout << endl;
	}
	cout << endl;

	//�ep�ɑ΂��ă\�[�g
	FOR(v, 0, n) {
		sort(vals[v].begin(), vals[v].end());

		//�_�u���Ȃ���(����͕s�v)
		auto iter1 = unique(vals[v].begin(), vals[v].end());
		vals[v].erase(iter1, vals[v].end());
	}

	FOR(i, 0, m) {
		int v = p[i];

		//�O����
		printf("%06d", v + 1);

		//�㔼��
		//vals[v]�̒�����y[i]�ȏ�̒l���o�Ă���ŏ��̃C�e���[�^��Ԃ�
		auto iter2 = lower_bound(vals[v].begin(), vals[v].end(), y[i]);
		int id = iter2 - vals[v].begin();

		printf("%06d\n", id + 1);
	}

}