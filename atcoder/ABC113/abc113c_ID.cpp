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

//6桁のゼロ埋め
string zeroPadding(int num) {
	string s = to_string(num);
	int zero = 6 - s.size();
	
	return string("").append(zero, '0') + s;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> py;
	FOR(i, 0, m) {
		int p, y;
		cin >> p >> y;
		py.emplace_back(p, y, i);
	}
	sort(py.begin(), py.end());

	cout << "py:" << endl;
	FOR(i, 0, m) cout << get<0>(py[i]) << ", " << get<1>(py[i]) << ", " << get<2>(py[i]) << endl;
	cout << endl;

	vector<string> ID(m);
	int cnt = 1;

	//初期条件
	ID[get<2>(py[0])] = zeroPadding(get<0>(py[0])) + zeroPadding(1);
	//cout << ID[get<2>(py[0])] << endl;

	FOR(i, 1, m) {
		//pが違うならcntリセット、そうでないならcnt+1
		if (get<0>(py[i]) != get<0>(py[i - 1])) cnt = 1;
		else cnt++;

		ID[get<2>(py[i])] = zeroPadding(get<0>(py[i])) + zeroPadding(cnt);
	}

	//cout << "ID:" << endl;
	FOR(i, 0, m) cout << ID[i] << endl;
	//cout << endl;

}