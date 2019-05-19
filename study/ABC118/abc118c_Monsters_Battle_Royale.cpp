#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)

/*int main(void) {
	int n;
	cin >> n;

	vector<int> monsters;

	FOR(i, 0, n) {
		int hp;
		cin >> hp;
		monsters.push_back(hp);
	}
	
	cout << "monsters:" << endl;
	FOR(i, 0, n) cout << monsters[i] << endl;

	while (monsters.size() > 1) {
		//小さい順にソート
		sort(monsters.begin(), monsters.end());

		//最小HPで残りのHP割る
		FOR(i, 1, monsters.size()) monsters[i] %= monsters[0];
		
		//HP0は削除
		auto it_remove = remove(monsters.begin(), monsters.end(), 0);
		monsters.erase(it_remove, monsters.end());

		cout << "monsters:" << endl;
		for(int m: monsters) cout << m << endl;
	}

	cout << monsters[0];

}*/