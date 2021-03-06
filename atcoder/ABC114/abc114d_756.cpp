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

int n;
vector<int> e(110, 0); //各素因数の指数を格納 prime^e

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	

	//n!を素因数分解
	//1~nまでを素因数分解して合算
	FOR(num, 2, n+1) {
		
		int tmp = num; //tmpに2~nを格納
		
		FOR(prime, 2, num + 1) {
			//num = prime1^e1 * prime2^e2 * prime3^e3...
			while (tmp % prime == 0) {
				e[prime] += 1;
				tmp /= prime;
			}
		}

	}

	cout << "e:" << endl;
	FOR(i, 0, n+1) cout << e[i] << endl;
	cout << endl;

	//約数75個の時、考えられるnumは
	//a4b4c2、a14b4、a24b2、a74のみ
	int cnt = 0;

	//a74の時
	FOR(i, 2, n + 1) if (e[i] >= 74) cnt++;

	//a24b2の時
	FOR(i, 2, n + 1) FOR(j, 2, n + 1) {
		if (i != j && e[i] >= 24 && e[j] >= 2) cnt++;
	}
	
	//a14b4の時
	FOR(i, 2, n + 1) FOR(j, 2, n + 1) {
		if (i != j && e[i] >= 14 && e[j] >= 4) cnt++;
	}
	
	//a4b4c2の時
	//bはaとかぶらないように注意
	FOR(i, 2, n + 1) FOR(j, i+1, n + 1) FOR(k, 0, n+1) {
		if (i != j && j != k && k != i && e[i] >= 4 && e[j] >= 4 && e[k] >= 2) cnt++;
	}
	
	cout << cnt << endl;

}