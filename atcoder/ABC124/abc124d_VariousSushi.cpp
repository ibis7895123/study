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
const ll INF = 1LL << 40;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> sushi(n); //d,tを格納したpair
	
	FOR(i, 0, n) {
		int t, d;
		cin >> t >> d;
		t--;
		sushi[i] = { d, t }; //ソートしやすさのためにt,d入れ替え
	}

	//美味しさで大きい順にソート
	sort(sushi.begin(), sushi.end(), greater<pair<int, int>>());

	cout << "sushi:" << endl;
	FOR(i, 0, n) cout << sushi[i].first << ", " << sushi[i].second << endl;
	cout << endl;

	
	ll score = 0; //満足度
	vector<int> neta(n, 0); //選んだ寿司をネタごとに集計
	int kind = 0; //選んだ寿司のネタ数

	//美味しい順にk個とる(初期値)
	FOR(i, 0, k) {
		score += sushi[i].first;
		neta[ sushi[i].second ]++;

		if (neta[sushi[i].second] == 1) kind++; //新しいネタならネタ種類プラス
	}
	score += kind * kind;

	cout << "score:" << score << endl;
	cout << "neta:" << endl;
	FOR(i, 0, n) cout << neta[i] << endl;
	cout << "kind:" << kind << endl;
	cout << endl;

	int in = 0;
	ll max1 = score;
	REF(out, k - 1, -1) {
		//ダブリの中から美味しさ最小のもの選ぶ
		if (neta[ sushi[out].second ] > 1) {
			in = -1;

			//選んでないものの中から
			//①ネタ数増えるかつ②美味しさ最大のものを選ぶ
			FOR(i, k, n) if (neta[ sushi[i].second ] == 0) { in = i; break; }
			//なければbreak
			if (in == -1) break;


			//食べるのをやめる寿司の分をscore、netaから引く
			score -= sushi[out].first;
			neta[ sushi[out].second ]--;
			cout << "out:" << sushi[out].first << "," << sushi[out].second << endl;


			//追加する寿司の分をscore、neta、kind(ネタ増える)に足す
			score += sushi[in].first;
			neta[sushi[in].second]++;
			kind++;
			cout << "in:" << sushi[in].first << "," << sushi[in].second << endl;
			cout << "kind:" << kind << endl;

			//種類ボーナス追加
			score += kind * kind - (kind - 1)*(kind - 1);
			cout << "score:" << score << endl;

			cout << "neta:" << endl;
			FOR(i, 0, n) cout << neta[i] << endl;
			cout << endl;
		}
		max1 = max(max1, score);
	}

	cout << max1 << endl;
}