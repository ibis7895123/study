#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)

int n, a, b, c;
vector<int> bamboo(8);
int min1 = 9999999;

void calc(vector<int> flag) {
	//FOR(i, 0, n) cout << flag[i] << ",";
	//cout << endl;

	int cost = -30; //a,b,cの1回分の合成costを始めに引いておく

	//合成
	vector<int> synthesis(4,0);
	FOR(i,0,n) {
		synthesis[ flag[i] ] += bamboo[i];
		//a,b,cのどれかに使うならcostに10足す
		if (flag[i] != 0) cost += 10;
	}

	//FOR(i, 0, 4) cout << synthesis[i] << ",";
	//cout << endl;
	//cout << a << " " << b << " " << c << endl;

	if (synthesis[1] != 0 && synthesis[2] != 0 && synthesis[3] != 0) {
		cost += abs(a - synthesis[1]) + abs(b - synthesis[2]) + abs(c - synthesis[3]);
		min1 = min(min1, cost);
		//cout << cost << " : " << min1 << endl;
	}
}

//0: 未使用、1:a、2:b、3:c
void dfs(int depth, vector<int> flag) {
	if (depth == n) calc(flag);
	else{
		FOR(i, 0, 4) {
			flag[depth] = i;
			dfs(depth + 1, flag);
		}
	}
}

int main(void) {
	
	cin >> n >> a >> b >> c;
	
	FOR(i, 0, n) {
		cin >> bamboo[i];
	}

	vector<int> comb(n);
	dfs(0, comb);

	//cout << "ans:" << endl;
	cout << min1 << endl;

	//vector<int> flag({1,2,2,2,3});
	//calc(flag);
}