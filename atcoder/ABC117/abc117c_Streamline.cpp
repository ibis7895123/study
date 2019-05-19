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

int n_piece, n_x;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n_piece >> n_x;
	
	vector<int> xs(n_x);
	FOR(i, 0, n_x) {
		cin >> xs[i];
	}
	sort(xs.begin(), xs.end());
	
	cout << "xs:" << endl;
	FOR(i, 0, n_x) cout << xs[i] << endl;
	cout << endl;

	//有効な駒の数はmin(駒の数, 座標の数)
	//重複した駒は考えない
	int size_p = min(n_piece, n_x);
	vector<int> pieces(size_p);
	pieces[0] = 0; //最初の駒は左端に置く

	//駒を置く位置計算
	//座標間距離が大きいところを飛び越えたところに駒を置く
	FOR(ip, 1, size_p) {
		
		int dxmax = 0;
		FOR(ix, 0, n_x - 1) {
			//選択済みのインデックスはスキップ
			auto iter = find(pieces.begin(), pieces.end(), ix+1);
			if (iter != pieces.end()) continue;

			//cout << ip << ", " << ix << endl;
			//cout << abs(xs[ix + 1] - xs[ix]) << endl;
			//座標間距離の最大値計算
			//最大値の右側インデックスをpiecesに記憶
			if (dxmax < abs(xs[ix + 1] - xs[ix])) {
				cout << abs(xs[ix + 1] - xs[ix]) << endl;
				dxmax = abs(xs[ix + 1] - xs[ix]);
				pieces[ip] = ix + 1;
			}

		}
	}
	//末尾にダミーの駒を入れる(移動量計算用)
	pieces.push_back(n_x);

	cout << "pieces:" << endl;
	FOR(i, 0, size_p) cout << pieces[i] << endl;
	cout << endl;

	//移動量計算
	//移動量 = 次の駒の1つ前の座標 - 現在の駒
	int sum = 0;
	FOR(i, 0, size_p) {
		int distance = xs[ pieces[i + 1] - 1 ] - xs[ pieces[i] ];
		cout << distance << endl;
		sum += distance;
	}
	cout << "sum:" << endl;
	cout << sum << endl;
}